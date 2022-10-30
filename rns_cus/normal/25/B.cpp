#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i, n;
    char c[100];
    scanf("%d\n", &n);
    for(i = 0; i < n; i ++)
        scanf("%c", &c[i]);
    if(n <= 3) {
        for(i = 0; i < n; i ++)
            printf("%c", c[i]);
        printf("\n");
    }
    else if(n % 2 == 0) {
        for(i = 0; i < n; i += 2)
            printf("%c%c%c", c[i] ,c[i+1], (i == n-2) ? '\n' : '-');
    }
    else {
        printf("%c%c%c-", c[0], c[1], c[2]);
        for(i = 3; i < n; i += 2)
            printf("%c%c%c", c[i] ,c[i+1], (i == n-2) ? '\n' : '-');
    }
}