#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a=1, b=2, c=3;
    if(N==1)
    {
        printf("O");
        return 0;
    }
    printf("OO");
    for(int i=3; i<=N; i++)
    {
        if(i==c)
        {
            printf("O");
            a=b;
            b=c;
            c=a+b;
        }
        else
        {
            printf("o");
        }
    }
    return 0;
}