#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll w[MAXN],f[MAXN],ans;
struct edge
{
    int to,cost;
};
vector<edge> G[MAXN];
void add_edge(int u,int v,int c)
{
    G[u].push_back((edge){v,c});
    G[v].push_back((edge){u,c});
}
void dfs(int v,int p)
{
    f[v]=w[v];
    for(auto e:G[v])
    {
        int to=e.to,cost=e.cost;
        if(to==p) continue;
        dfs(to,v);
        ans=max(ans,f[v]+f[to]-cost);
        f[v]=max(f[v],f[to]-cost+w[v]);
    }
}
int main()
{
    //freopen("path15.in","r",stdin);
    scanf("%d",&n);
    ans=0;
    for(int i=1;i<=n;i++) {scanf("%d",&w[i]); ans=max(ans,1LL*w[i]);}
    for(int i=0;i<n-1;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add_edge(u,v,c);
    }
    dfs(1,0);printf("%lld\n",ans);

    return 0;
}