#include<bits/stdc++.h>
#define MAXN 800005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
struct edge{int to,cost;};
typedef pair<ll,int> P;
int n,m;
vector<edge> G[MAXN];
ll d[MAXN];
//1-n: sum of path
//n+1-2n: sum of path add arbitrary
//2n+1-3n: sum of path delete arbitrary
//3n+1-4n: sum of path add arbitrary then delete arbitrary
void add_edge(int from,int to,int cost)
{
    G[from].push_back((edge){to,cost});
}
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+4*n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        for(int x=0;x<=3;x++)
            for(int y=0;y<=3;y++)
            {
                if((y&x)!=x) continue;
                int s=x^y;
                int c=cost;
                if(s&1) c+=cost;
                if(s&2) c-=cost;
                add_edge(x*n+u,y*n+v,c); add_edge(x*n+v,y*n+u,c);
            }
    }
    dijkstra(1);
    for(int i=2;i<=n;i++) printf("%lld ",d[3*n+i]);
    return 0;
}