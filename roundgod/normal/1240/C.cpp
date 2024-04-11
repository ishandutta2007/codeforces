#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
vector<edge> G[MAXN];
int q,n,k;
ll f[MAXN],g[MAXN];
vector<ll> weights[MAXN];
void add_edge(int u,int v,int cost)
{
    G[u].push_back((edge){v,cost});
    G[v].push_back((edge){u,cost});
}
void dfs(int v,int p)
{
    f[v]=g[v]=0;
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v);
        f[v]+=f[e.to]; g[v]+=f[e.to];
        weights[v].push_back(e.cost+g[e.to]-f[e.to]);
    }
    sort(weights[v].begin(),weights[v].end(),greater<ll>());
    ll sum1=0,sum2=0;
    for(int i=0;i<(int)weights[v].size();i++)
    {
        if(weights[v][i]<=0) break;
        if(i<k-1) sum1+=weights[v][i];
        if(i<k) sum2+=weights[v][i];
    }
    f[v]+=sum2; g[v]+=sum1;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear(),weights[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            add_edge(u,v,cost);
        }
        dfs(1,0);
        printf("%lld\n",f[1]);
    }
    return 0;
}