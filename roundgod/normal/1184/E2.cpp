#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXLOGN 20
#define MAXN 100005
#define MAXE 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
struct edge{int u,v,cost,id;};
int pa[MAXLOGN][MAXN],maxi[MAXLOGN][MAXN];
int depth[MAXN];
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE],backup[MAXE];
int V,E;
int p[MAXN],r[MAXN];
bool use[MAXE];
struct ee{int to,cost;};
vector<ee> G[MAXN];
void init_dsu(int n)
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
void unite(int x,int y,int w)
{
    int xx=x,yy=y;
    x=find(x);
    y=find(y);
    if(x==y) return;
    G[xx].push_back((ee){yy,w}); G[yy].push_back((ee){xx,w});
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int kruskal()
{
    sort(es,es+E,cmp);
    init_dsu(V);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            use[e.id]=true;
            unite(e.u,e.v,e.cost);
            res+=e.cost;
        }
    }
    return res;
}
void dfs(int v,int p,int d,int cost)
{
    pa[0][v]=p;
    maxi[0][v]=cost;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i].to!=p) dfs(G[v][i].to,v,d+1,G[v][i].cost);
}
void init(int V)
{
    dfs(1,-1,0,-INF);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) 
            {
                pa[k+1][v]=-1;
                maxi[k+1][v]=maxi[k][v];
            }
            else 
            {
                pa[k+1][v]=pa[k][pa[k][v]];
                maxi[k+1][v]=max(maxi[k][v],maxi[k][pa[k][v]]);
            }
        }
    }
}
P get(int v,int x)
{
    int res=-INF;
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
        {
            res=max(res,maxi[k][v]);
            v=pa[k][v];
        }
    return P(v,res);
}
int get_ans(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    P p=get(v,depth[v]-depth[u]);
    v=p.F;
    int ans=p.S;
    if(u==v) return ans;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            ans=max(ans,maxi[k][u]);
            ans=max(ans,maxi[k][v]);
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    ans=max(ans,maxi[0][u]);
    ans=max(ans,maxi[0][v]);
    assert(ans!=-INF);
    return ans;
}
int main()
{
    scanf("%d%d",&V,&E);
    memset(use,false,sizeof(use));
    for(int i=0;i<E;i++)
    {
        int a,b,e;
        scanf("%d%d%d",&a,&b,&e);
        es[i]=backup[i]=(edge){a,b,e,i};
    }
    kruskal();
    init(V);
    for(int i=0;i<E;i++)
    {
        if(!use[i]) printf("%d\n",get_ans(backup[i].u,backup[i].v));
    }
    return 0;
}