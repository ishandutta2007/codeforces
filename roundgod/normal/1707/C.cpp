#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,u[MAXN],v[MAXN];
vector<int> G[MAXN];
int p[MAXN],r[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return false;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
    return true;
}
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init2(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int ans[MAXN];
bool mst[MAXN];
vector<P> edges;
void go(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    int l=lca(u,v);
    if(l==u)
    {
        ans[v]++; ans[1]++; 
        int to=get(v,depth[v]-depth[u]-1);
        ans[to]--;
    }
    else
    {
        ans[u]++; ans[v]++;
    }
}
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        ans[to]+=ans[v];
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d",&u[i],&v[i]);
    init(n);
    for(int i=0;i<m;i++)
    {
        if(unite(u[i],v[i])) {mst[i]=true; G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);}
    }
    init2(n);
    for(int i=0;i<m;i++)
        if(!mst[i]) go(u[i],v[i]);
    dfs2(1,0);
    for(int i=1;i<=n;i++) if(ans[i]==m-(n-1)) printf("1"); else printf("0");
    printf("\n");
    return 0;
}