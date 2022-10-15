#include<bits/stdc++.h>
#define MAXN 51
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n;
char mp[MAXN][MAXN];
int cnt[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int getcnt(int xl,int xr,int yl,int yr)
{
    return cnt[xr][yr]-cnt[xl-1][yr]-cnt[xr][yl-1]+cnt[xl-1][yl-1];
}
int solve(int xl,int xr,int yl,int yr)
{
    if(dp[xl][xr][yl][yr]!=-1) return dp[xl][xr][yl][yr];
    if(!getcnt(xl,xr,yl,yr)) return 0;
    int &res=dp[xl][xr][yl][yr];
    res=max(xr-xl+1,yr-yl+1);
    for(int i=xl;i<xr;i++) res=min(res,solve(xl,i,yl,yr)+solve(i+1,xr,yl,yr));
    for(int i=yl;i<yr;i++) res=min(res,solve(xl,xr,yl,i)+solve(xl,xr,i+1,yr));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt[i][j]=(mp[i][j]=='#'?1:0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt[i][j]=cnt[i][j]+cnt[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt[i][j]=cnt[i][j]+cnt[i-1][j];
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,n,1,n));
    return 0;
}