#include <stdio.h>

int main()
{
    int k, max = 0;
    scanf ("%d", &k);
    for (int i=0 ; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        if (x > max) max = x;
    }
    if (max < 25)
    {
        printf ("0\n");
    }
    else
    {
        printf ("%d\n", max - 25);
    }
    return 0;
}