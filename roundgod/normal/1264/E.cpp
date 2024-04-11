#include<bits/stdc++.h>
#define MAXN 55
#define MAXV 5005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev,id;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int V,n,m;
vector<edge> G[MAXV];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h+1,h+V+1,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,INF);
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
int w[MAXV][MAXV];
int ans[MAXV][MAXV];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        w[u][v]=1;
    }
    int s=n+n*(n-1)/2+1,t=s+1;
    V=t;
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            tot++;
            add_edge(s,tot+n,1,0);
            if(!w[i][j]) add_edge(tot+n,i,1,0);
            if(!w[j][i]) add_edge(tot+n,j,1,0);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n-1;j++)
            add_edge(i,t,1,2*j-1);
    int res=min_cost_flow(s,t,n*(n-1)/2);
    tot=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            tot++;
            for(auto e:G[n+tot])
            {
                if(e.cap) continue;
                if(e.to==i) w[j][i]=1; else w[i][j]=1; 
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) printf("%d",w[i][j]);
        puts("");
    }
    return 0;
}