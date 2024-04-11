#include<bits/stdc++.h>
#define MAXV 200005
#define MAXLOGV 20
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
    int u,v,cost;
};
vector<int> G[MAXV];
vector<edge> H[MAXV];
int root,n,m,t;
int parent[MAXLOGV][MAXV],depth[MAXV],l[MAXV],r[MAXV],bit[MAXV+1],dp[MAXV],s[MAXV];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<MAXV)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(int v,int p,int d)
{
    l[v]=++t;
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    r[v]=t;
}
void init(int V)
{
    dfs(root,-1,0);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=0;v<n;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
void solve(int v)
{
    for(int i=0;i<G[v].size();i++)
    {
        solve(G[v][i]);
        s[v]+=dp[G[v][i]];
    }
    dp[v]=s[v];
    for(int i=0;i<H[v].size();i++)
    {
        edge e=H[v][i];
        dp[v]=max(dp[v],sum(l[e.u])+sum(l[e.v])+s[v]+e.cost);
    }
    add(l[v],s[v]-dp[v]); add(r[v]+1,dp[v]-s[v]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        G[x-1].push_back(i);
    }
    init(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        H[lca(u,v)].push_back((edge){u,v,w});
    }
    memset(bit,0,sizeof(bit));
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    solve(0);
    printf("%d\n",dp[0]);
    return 0;
}