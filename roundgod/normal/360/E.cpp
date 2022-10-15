#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
struct edge{int to,cost;};
typedef long long ll;
typedef pair<ll,int> P;
int n,m,k,s1,s2,f;
vector<edge> G[MAXN];
vector<edge> G2[MAXN];
ll d[MAXN];
int l[MAXN],r[MAXN],res[MAXN];
int type[MAXN];
priority_queue<P,vector<P>,greater<P> > que;
void update(int u,ll dis,int tp)
{
    if(dis>d[u]) return;
    if(dis<d[u]) {d[u]=dis; type[u]=tp; que.push(P(dis,u)); return;}
    type[u]|=tp;
}
void dijkstra(bool flag)
{
    for(int i=0;i<k;i++) res[i]=l[i];
    fill(d+1,d+n+1,INF); memset(type,0,sizeof(type));
    d[s1]=0; type[s1]=1; d[s2]=0; type[s2]=2;
    que.push(P(0,s1)); que.push(P(0,s2));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.F) continue;
        for(auto e:G[v]) update(e.to,p.F+e.cost,type[v]);
        for(auto e:G2[v])
        {
            int cost=l[e.cost];
            if(flag&&(type[v]&2)) cost=r[e.cost],res[e.cost]=r[e.cost];
            if(!flag&&(!(type[v]&1))) cost=r[e.cost],res[e.cost]=r[e.cost];
            update(e.to,p.F+cost,type[v]);
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&k,&s1,&s2,&f);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back((edge){v,w}); 
    }
    for(int i=0;i<k;i++)
    {
        int u,v;
        scanf("%d%d%d%d",&u,&v,&l[i],&r[i]);
        G2[u].push_back((edge){v,i}); 
    }
    if(s1==s2)
    {
        puts("DRAW");
        for(int i=0;i<k;i++) printf("%d ",l[i]);
        puts("");
        return 0;
    }
    dijkstra(true);
    if(type[f]==1) 
    {
        puts("WIN");
        for(int i=0;i<k;i++) printf("%d ",res[i]);
        puts("");
        return 0;
    }
    dijkstra(false);
    if(type[f]&1) 
    {
        puts("DRAW");
        for(int i=0;i<k;i++) printf("%d ",res[i]);
        puts("");
        return 0;
    }
    puts("LOSE");
    return 0;
}