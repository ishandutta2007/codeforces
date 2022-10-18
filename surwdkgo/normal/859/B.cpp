#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i<= 1000; i++)
    {
        if (i * i >= n)
        {
            printf("%d\n", 4*i);
            break;
        }
        else if (i * (i+1) >= n)
        {
            printf("%d\n", 4*i+2);
            break;
        }
    }
    return 0;
}