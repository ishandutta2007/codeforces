#include<bits/stdc++.h>
#define MAXN 105
#define MAXV 500
#define MAXE 50000
#define INF 100000000
using namespace std;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int l[MAXN],r[MAXN];
int V,n,q;
vector<edge> G[MAXV];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(int i=0;i<G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(int v=0;v<V;v++) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&q);
    V=3*n+2;
    for(int i=1;i<=n;i++)
    {
        l[i]=1;
        r[i]=n;
    }
    for(int i=0;i<q;i++)
    {
        int type,x,y,z;
        scanf("%d%d%d%d",&type,&x,&y,&z);
        for(int j=x;j<=y;j++)
            if(type==1) l[j]=max(l[j],z); else r[j]=min(r[j],z);
    }
    for(int i=1;i<=n;i++)
        if(l[i]>r[i]) {puts("-1"); return 0;}
    for(int i=1;i<=n;i++)
        add_edge(0,i,1,0);
    for(int i=1;i<=n;i++)
        for(int j=l[i];j<=r[i];j++)
            add_edge(i,n+j,1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            add_edge(n+i,2*n+j,1,j*2-1);
    for(int i=1;i<=n;i++)
        add_edge(2*n+i,3*n+1,INF,0);
    printf("%d\n",min_cost_flow(0,3*n+1,n));
    return 0;
}