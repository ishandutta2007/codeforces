#include<bits/stdc++.h>
#define MAXN 1005
#define MAXW 10005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll c[MAXN],cost[MAXN],dp[MAXN][MAXW+1];
ll n,W,B,X;
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&W,&B,&X);
    ll m=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%I64d",&c[i]);
        m+=c[i];
    }
    for(ll i=1;i<=n;i++)
        scanf("%I64d",&cost[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=W;
    ll ans=0;
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=m;j++)
        {
            for(ll k=0;k<=min(j,c[i]);k++)
            {
                if(dp[i-1][j-k]==-1) continue;
                ll mana=min(W+(j-k)*B,dp[i-1][j-k]+X)-k*cost[i];
                if(mana<0) continue;
                dp[i][j]=max(dp[i][j],mana);
                ans=max(ans,j);
            }
        }
    printf("%I64d\n",ans);
    return 0;
}