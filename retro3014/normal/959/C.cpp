#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    if(N<6)
    {
        printf("-1\n");
    }
    else
    {
        printf("1 2\n1 3\n1 4\n");
        for(int i=5; i<=N; i++)
        {
            printf("2 %d\n", i);
        }
    }
    for(int i=2; i<=N; i++)
    {
        printf("%d %d\n", i-1, i);
    }
    return 0;
}