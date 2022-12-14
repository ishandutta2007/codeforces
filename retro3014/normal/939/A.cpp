#include <stdio.h>

#define MAX_N 5000

int arr[MAX_N+1];
int N;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=N; i++)
    {
        int k=i;
        for(int j=1; j<=3; j++)
        {
            k=arr[k];
        }
        if(k==i)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}