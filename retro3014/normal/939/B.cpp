#include <stdio.h>

#define MAX_K 100000

long long N;
int K;
long long arr[MAX_K+1];

int main()
{
    scanf("%lld %d", &N, &K);
    int t=1;
    for(int i=1; i<=K; i++)
    {
        scanf("%lld", &arr[i]);
        if(i!=1 && N-(N%arr[i])>N-(N%arr[t]))
        {
            t=i;
        }
    }
    printf("%d %lld", t, N/arr[t]);
    return 0;
}