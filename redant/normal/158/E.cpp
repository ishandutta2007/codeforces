#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MXN 4004
#define MXS 86400

int dp[2][MXN];
int start[MXN], duration[MXN];

int main()
{
    //freopen("in1.in","r",stdin);
    int N, K;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d %d",start+i,duration+i);
    int ans = 0;
    int c = 0, p = 1;
    for(int i=0;i<N;i++)
    {
        c^=1; p^=1;
        for(int k=0;k<=K;k++)
        {
            ans = max(ans, start[i]-dp[p][k]-1);
            dp[c][k] = max( start[i], dp[p][k] + 1 ) + duration[i] - 1;
            if(k!=0) dp[c][k] = min(dp[c][k], dp[p][k-1]);
        }
    }
    ans = max(ans, MXS + 1 - dp[c][K] - 1);
    printf("%d\n",ans);
    return 0;
}