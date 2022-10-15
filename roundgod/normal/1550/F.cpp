#include<bits/stdc++.h>
#define MAXN 200005
#define MAXE 800005
#define MAXK 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,s,d;
int a[MAXN];
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
//idea: find a superset of minimum spanning tree with O(n) edges
edge es[MAXE];
int V,E;
int p[MAXN],r[MAXN];
void add_edge(int u,int v,int cost)
{
    //printf("added edge %d %d %d\n",u,v,cost);
    es[E++]=(edge){u,v,cost};
}
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
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
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
int calc_cost(int x,int y)
{
    return max(d-(y-x),(y-x)-d);
}
vector<pair<int,P> > query;
int ans[MAXN];
int main()
{
    scanf("%d%d%d%d",&n,&q,&s,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=INF;
    for(int i=1;i<=n;i++)
    {
        int x=a[i]-d;
        int id=lower_bound(a+1,a+n+2,x)-a;
        if(id>=1&&id<=n) add_edge(id,i,calc_cost(a[id],a[i]));
        if(id-1>=1&&id-1<=n) add_edge(id-1,i,calc_cost(a[id-1],a[i]));
        x=a[i]+d;
        id=lower_bound(a+1,a+n+2,x)-a;
        if(id>=1&&id<=n) add_edge(id,i,calc_cost(a[i],a[id]));
        if(id-1>=1&&id-1<=n) add_edge(id-1,i,calc_cost(a[i],a[id-1]));
    }
    for(int i=0;i<q;i++)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        query.push_back(make_pair(k,P(x,i)));
    }
    init(n);
    sort(query.begin(),query.end());
    sort(es,es+E,cmp);
    int now=0;
    for(int i=0;i<q;i++)
    {
        while(now<E&&es[now].cost<=query[i].F)
        {
            unite(es[now].u,es[now].v);
            now++;
        } 
        if(same(s,query[i].S.F)) ans[query[i].S.S]=1;
    }
    for(int i=0;i<q;i++) if(ans[i]) puts("Yes"); else puts("No");
    return 0;
}