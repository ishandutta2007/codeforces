#include <stdio.h>

int N, M;

bool isprime(int x)
{
    for(int i=2; i*i<=x && i<=N; i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=M; i>N; i--)
    {
        if(isprime(i))
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}