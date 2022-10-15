#include<bits/stdc++.h>
#define MAXN 2005
#define MAXV 3005
#define MAXE 10000
#define INF 1000000000
using namespace std;
typedef pair<double,int> P;
struct edge{int to,cap; double cost; int rev;};
double dist[MAXV],h[MAXV];
int prevv[MAXV],preve[MAXV];
int n,a,b,V;
vector<edge> G[MAXV];
double p[MAXN],q[MAXN];
const double eps=1e-12;
void add_edge(int from,int to,int cap,double cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
double min_cost_flow(int s,int t,int f)
{
    double res=0;
    fill(h+1,h+V+1,0.0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,1e12);
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
        if(abs(dist[t]-1e12)<eps)
        {
            return -1;
        }
        for(int v=1;v<=V;v++) h[v]+=dist[v];
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
double offset=2.0;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&q[i]);
    V=n+4;
    int s=n+3,t=n+4;
    add_edge(s,n+1,a,0.0); add_edge(s,n+2,b,0.0);
    for(int i=1;i<=n;i++)
    {
        add_edge(n+1,i,1,offset-p[i]);
        add_edge(n+2,i,1,offset-q[i]);
        add_edge(i,t,1,0.0);
        add_edge(i,t,1,p[i]*q[i]);
    }
    printf("%.10f\n",(a+b)*offset-min_cost_flow(s,t,a+b));
    return 0;
}