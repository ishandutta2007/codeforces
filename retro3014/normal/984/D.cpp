#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 5000

int N, M;
int arr[MAX_N+1];
int DP[MAX_N+1][MAX_N+1];
int ans[MAX_N+1][MAX_N+1];

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int l=0; l<N; l++)
    {
        for(int i=1; i+l<=N; i++)
        {
            if(l==0)
            {
                DP[i][i+l]=arr[i];
                ans[i][i+l]=DP[i][i];
            }
            else
            {
                DP[i][i+l]=(DP[i][i+l-1])^(DP[i+1][i+l]);
                ans[i][i+l]=max(ans[i][i+l-1], max(ans[i+1][i+l], DP[i][i+l]));
            }
        }
    }
    cin>>M;
    for(int i=1; i<=M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", ans[x][y]);
    }
    return 0;
}