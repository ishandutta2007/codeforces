#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 100005
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
vector<int> G[MAXN];
int p[MAXN],color[MAXN],cyc[MAXN],cnt[MAXN],depth[MAXN];
int pa[MAXLOGN][MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs1(int v,int p,int d)
{
    color[v]=1; pa[0][v]=p; depth[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!color[to]) dfs1(to,v,d+1);
        else if(color[to]==1)
        {
            cyc[to]=1; cnt[to]=1;
            int tmp=v;
            while(tmp!=to)
            {
                cyc[tmp]=1;
                tmp=pa[0][tmp];
            }
        }
    }
    color[v]=2;
}
void dfs2(int v)
{
    color[v]=0;
    for(auto to:G[v])
    {
        if(!color[to]) continue;
        cnt[to]+=cnt[v];
        dfs2(to);
    }
}
void init(int V)
{
    dfs1(1,-1,0); dfs2(1);
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
int main()
{
    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=2LL*p[i-1]%MOD;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    init(n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int ans=cnt[u]+cnt[v];
        int z=lca(u,v);
        if(cyc[z]) ans-=2*cnt[z]-1; else ans-=2*cnt[z];
        printf("%d\n",p[ans]);
    }
    return 0;
}