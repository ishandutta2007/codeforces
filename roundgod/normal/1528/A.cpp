#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int l[MAXN],r[MAXN];
vector<int> G[MAXN];
ll dp[MAXN][2];
void dfs(int v,int p)
{
    dp[v][0]=dp[v][1]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v][0]+=max(max(l[v]-l[to],l[to]-l[v])+dp[to][0],max(l[v]-r[to],r[to]-l[v])+dp[to][1]);
        dp[v][1]+=max(max(r[v]-l[to],l[to]-r[v])+dp[to][0],max(r[v]-r[to],r[to]-r[v])+dp[to][1]);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}