#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define MOD 1000000007
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,b,c[MAXN],d[MAXN],sz[MAXN],dp[MAXN][MAXN][2];
vector<int> G[MAXN];
void dfs(ll v)
{
    sz[v]=1;
    dp[v][0][1]=0;
    dp[v][1][0]=c[v]-d[v];dp[v][1][1]=c[v];
    for(auto to:G[v])
    {
        dfs(to);
        for(ll i=sz[v];i>=0;i--)
            for(ll j=sz[to];j>=0;j--)
            {
                dp[v][i+j][0]=min(dp[v][i+j][0],dp[v][i][0]+dp[to][j][0]);
                dp[v][i+j][1]=min(dp[v][i+j][1],dp[v][i][1]+dp[to][j][1]);
                dp[v][i+j][0]=min(dp[v][i+j][0],dp[v][i][0]+dp[to][j][1]);
            }
        sz[v]+=sz[to];
    }
}
int main()
{
    scanf("%lld%lld",&n,&b);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&c[i],&d[i]);
        if(i>=2)
        {
            ll x;scanf("%lld",&x);G[x].push_back(i);
        }
    }
    for(ll i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=INF;
    dfs(1);
    for(ll i=n;i>=0;i--) if(dp[1][i][0]<=b||dp[1][i][1]<=b) {printf("%lld\n",i); return 0;}
    return 0;
}