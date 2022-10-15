#include<bits/stdc++.h>
#define MAXN 400005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,r,tot;
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int p[MAXN],rk[MAXN];
void init_dsu(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        rk[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rk[x]<rk[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,0,0);
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
int go(int u,int v,int x)
{
    int l=lca(u,v);
    if(l==u) return go(v,u,depth[v]-depth[u]-x);
    else if(l==v) return get(u,x);
    else
    {
        if(depth[u]-depth[l]>=x) return get(u,x);
        else return go(l,v,x-(depth[u]-depth[l]));
    }
    
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int d[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&r);
    tot=n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,++tot);
        add_edge(v,tot);
    }
    init(tot);
    init_dsu(tot);
    for(int i=1;i<=tot;i++) d[i]=INF;
    queue<int> que;
    for(int i=0;i<r;i++)
    {
        int x;
        scanf("%d",&x);
        d[x]=0;
        que.push(x);
    }
    while(que.size())
    {
        int v=que.front(); que.pop();
        if(d[v]>=k) continue;
        for(auto to:G[v])
        {
            unite(v,to);
            if(d[to]==INF)
            {
                d[to]=d[v]+1;
                que.push(to);
            }
        } 
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(same(x,y)) puts("YES");
        else if(dis(x,y)<=2*k) puts("YES");
        else if(same(go(x,y,k),go(y,x,k))) puts("YES");
        else puts("NO");
    }
    return 0;
}