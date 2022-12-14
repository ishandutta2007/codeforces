#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAX_N 100000

int N, M;
int arr[MAX_N+10];
double ans=-1;
bool flag=true;

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int idx=1;
    for(int i=1; i<N; i++)
    {
        while(idx<N && arr[idx+1]-arr[i]<=M)
        {
            idx++;
        }
        if(i<=idx-2)
        {
            ans=max(ans, (double)(arr[idx]-arr[i+1])/(double)(arr[idx]-arr[i]));
            flag=false;
        }
    }
    if(flag)
    {
        printf("-1");
    }
    else
    {
        printf("%.10lf", ans);
    }
    return 0;
}