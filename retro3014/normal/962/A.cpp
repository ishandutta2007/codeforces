#include <stdio.h>

#define MAX_N  200000

long long arr[MAX_N+1];
int N;
long long sum=0;
long long sum2=0;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%lld", &arr[i]);
        sum+=arr[i];
    }
    for(int i=1; i<=N; i++)
    {
        sum2+=arr[i];
        if(sum2*2>=sum)
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}