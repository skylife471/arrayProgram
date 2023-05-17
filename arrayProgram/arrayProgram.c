#include<stdio.h>
#include<stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

void init(ArrayListType* L)
{
    L->size = 0;
}
int is_empty(ArrayListType* L)
{
    return L->size == 0;
}
int is_full(ArrayListType* L)
{
    return L->size == MAX_LIST_SIZE;
}
void print_list(ArrayListType* L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}
void insert(ArrayListType* L, int pos, element item)
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size))
    {
        int move_count = 0;
        for (int i = (L->size - 1); i >= pos; i--)
        {
            L->array[i + 1] = L->array[i];
            move_count++;
        }
        L->array[pos] = item;
        L->size++;
        printf("\nMove: %d\n", move_count);

    }
}
element deleteItem(ArrayListType* L, int pos)
{
    element item;

    if (pos < 0 || pos >= L->size)
        fprintf(stderr, "위치오류");
    item = L->array[pos];
    int move_count = 0;
    for (int i = pos; i < (L->size - 1); i++)
    {
        L->array[i] = L->array[i + 1];
        move_count++;
    }
    L->size--;
    printf("\nMove: %d\n", move_count);

    return item;
}
int main(void)
{
    ArrayListType list;
    init(&list);
    for (;;) {
        int input;
        printf("MENU\n");
        printf("(1) Insert\n");
        printf("(2) Delete\n");
        printf("(3) Print\n");
        printf("(0) Exit\n");
        printf("Enter the Menu: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            int num, pos;
            printf("Enter the number and position: ");
            do {
                scanf("%d %d", &num, &pos);

                if (list.size == 0 && pos == 1) {
                    printf("List size is zero. please enter again(number position): ");
                }
                else {
                    insert(&list, pos, num);
                    break;
                }
            } while (1);
            printf("\n");
            break;
        case 2:
            int pos1;

            if (is_empty(&list)) {
                printf("List is empty\n");
            }
            else {
                printf("Enter the position: ");
                scanf("%d", &pos1);
                element deletedItem = deleteItem(&list, pos1);
                printf("Deleted: %d\n", deletedItem);
            }
            printf("\n");
            break;
        case 3:
            print_list(&list);
            printf("\n");
            break;
        case 0:
            printf("Exit the program");
            printf("\n");
            exit(1);
        default:
            printf("Invalid Menu. Please Select again..\n");
            printf("\n");
            break;
        }
    }
    return 0;
}