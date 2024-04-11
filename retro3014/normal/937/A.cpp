#include <stdio.h>

int N;
int arr[700];

int main()
{
    int cnt=0;
    scanf("%d", &N);
    int x;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &x);
        if(x!=0 && arr[x]==0)
        {
            arr[x]++;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}