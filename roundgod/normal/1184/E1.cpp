#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
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
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
edge es[MAXE];
int V,E;
int x,y,w;
int p[MAXN],r[MAXN];
struct ee{int to,cost;};
vector<ee> G[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
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
int ans,target;
void dfs(int v,int p,int maxx)
{
    if(v==target)
    {
        ans=maxx;
        return;
    }
    for(auto e:G[v])
    {
        if(e.to==p) continue;
        dfs(e.to,v,max(maxx,e.cost));
    }
}
int kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v,e.cost);
            res+=e.cost;
        }
    }
    return res;
}

int main()
{
    scanf("%d%d",&V,&E);
    E--;
    scanf("%d%d%d",&x,&y,&w);
    for(int i=0;i<E;i++)
    {
        int a,b,e;
        scanf("%d%d%d",&a,&b,&e);
        es[i]=(edge){a,b,e};
    }
    kruskal();
    if(!same(x,y)) printf("%d\n",INF);
    else
    {
        target=y;
        ans=INF;
        dfs(x,0,-1);
        printf("%d\n",ans);
    }
    return 0;
}