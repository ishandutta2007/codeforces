#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> G[MAXN];
ll ans[MAXN];
int sz[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p; sz[v]=1;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v,d+1);
        sz[v]+=sz[G[v][i]];
    }
}
void init(int V)
{
    dfs(0,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=0;v<V;v++)
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
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
bool on_chain(int u,int v,int w)//if w is on chain (u,v)
{
    return dis(u,w)+dis(v,w)==dis(u,v);
}
int get_subtree_size(int u,int v)//subtree size of u where v is in
{
    int l=lca(u,v);
    if(l!=u) return n-sz[u];
    else return sz[get(v,depth[v]-depth[u]-1)];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++) G[i].clear(),ans[i]=0;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        init(n);
        //compute ans[0]
        for(auto to:G[0]) ans[0]+=1LL*sz[to]*(sz[to]-1)/2;
        //compute ans[1]
        ans[1]=1LL*n*(n-1)/2-ans[0];//number of paths containing 0
        ans[1]-=1LL*(n-get_subtree_size(0,1))*(n-get_subtree_size(1,0));
        //compute ans[2]-ans[n-1]
        int u=0,v=1;
        bool f=true;
        for(int i=2;i<=n-1;i++)
        {
            if(on_chain(u,v,i)) ans[i]=0;
            else if(!on_chain(u,i,v)&&!on_chain(v,i,u))
            {
                ans[i]=1LL*(n-get_subtree_size(u,v))*(n-get_subtree_size(v,u));
            }
            else if(on_chain(u,i,v))
            {
                ans[i]=-1LL*(n-get_subtree_size(u,i))*(n-get_subtree_size(i,u))+1LL*(n-get_subtree_size(u,v))*(n-get_subtree_size(v,u));
            }
            else
            {
                ans[i]=-1LL*(n-get_subtree_size(v,i))*(n-get_subtree_size(i,v))+1LL*(n-get_subtree_size(u,v))*(n-get_subtree_size(v,u));
            }
            if(on_chain(u,v,i));
            else if(on_chain(u,i,v)) v=i;
            else if(on_chain(v,i,u)) u=i;
            else {f=false; break;}
        }
        if(f) ans[n]=1;
        for(int i=0;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}