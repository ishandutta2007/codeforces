#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=55;
const int M=2505;

struct edge
{
  int u,v,w,f; int next;
}G[M<<1];
int head[N],inum=1;
inline void add(int u,int v,int w,int f,int p)
{
  G[p].u=u; G[p].v=v; G[p].w=w; G[p].f=f; G[p].next=head[u]; head[u]=p;
}
inline void link(int u,int v,int w,int f)
{
  add(u,v,w,f,++inum); add(v,u,-w,0,++inum);
}
#define oo 1<<29
int n,m,P;
int S,T,Mincost;
int Q[N*M],l,r;
int dis[N],pre[N],ins[N];
#define V G[p].v
inline bool SPFA()
{
    for (int i=1;i<=n;i++) dis[i]=oo,pre[i]=0,ins[i]=0;
    l=r=-1; Q[++r]=S,dis[S]=0,ins[S]=1;
    while (l<r)
    {
        int u=Q[++l]; ins[u]=0;
        for (int p=head[u];p;p=G[p].next)
        if (G[p].f && dis[V]>dis[u]+G[p].w)
        {
            dis[V]=dis[u]+G[p].w; pre[V]=p;
            if (!ins[V]) Q[++r]=V,ins[V]=1;
        }
    }
    if (dis[T]==oo) return 0;
    Mincost+=dis[T];
    for (int p=pre[T];p;p=pre[G[p].u]) G[p].f--,G[p^1].f++;
    return 1;
}
vector<int> v;
int main()
{
    scanf("%d%d",&n,&m);
    S=1; T=n;
    for (int i=1;i<=m;i++)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        link(u,v,d,1);
    }
    double ans=1e20; int m=0;
    while (SPFA())
    {
        v.push_back(Mincost);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        double ans=1e12;
        for(int i=0;i<(int)v.size();i++) ans=min(ans,(double)(v[i]+x)/(double)(i+1));
        printf("%.10f\n",ans);
    }
    return 0;
}