#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define L 1
#define R 1000000

int N;
int arr[MAX_N+1];
int ans=R;

int main()
{
    scanf("%d", &N);
    arr[0]=1;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
        ans=min(ans, max(arr[i-1]-L, R-arr[i]));
    }
    ans=min(ans, arr[N]-L);
    printf("%d", ans);
    return 0;
}