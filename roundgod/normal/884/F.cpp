#include<bits/stdc++.h>
#define MAXV 105
#define MAXE 10300
#define INF 1000000
using namespace std;
char str[MAXV];
int n,b[MAXV];
vector<int> l,r;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
int V;
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
    scanf("%d",&n);
    scanf("%s",str);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        sum+=b[i];
    }
    for(int i=0;i<n/2;i++)
        if(b[i]<=b[n-1-i]) {l.push_back(i);r.push_back(n-1-i);} else {l.push_back(n-1-i);r.push_back(i);}
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
            if(str[l[i]]!=str[r[j]])
                if(l[i]+r[j]!=n-1) add_edge(l[i],r[j],1,b[l[i]]); else add_edge(l[i],r[j],1,0);
    }
    for(int i=0;i<n/2;i++)
        add_edge(n,l[i],1,0);
    for(int i=0;i<n/2;i++)
        add_edge(r[i],n+1,1,0);
    V=n+2;
    printf("%d\n",sum-min_cost_flow(n,n+1,n/2));
    return 0;
}