#include<bits/stdc++.h>
#define MAXN (1<<20)
#define MAXV 16505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<pair<int,P> >v;
struct edge{int to,cap; ll cost; int rev;};
int V,s[MAXV],e[MAXV];
ll w[MAXV];
ll h[MAXV],dist[MAXV];
int prevv[MAXV],preve[MAXV];
vector<edge> G[MAXV];
bool inque[MAXV];
void add_edge(int from,int to,int cap,ll cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
void dijkstra(int s)
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
}
void spfa(int s)
{
    queue<int>que;
    fill(h+1,h+V+1,INF);
    fill(inque+1,inque+V+1,false);
    h[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front(); que.pop();
        for(int i=0;i<(int)G[u].size();i++)
        {
            if(G[u][i].cap>0&&h[u]+G[u][i].cost<h[G[u][i].to])
            {
                h[G[u][i].to]=h[u]+G[u][i].cost;
                prevv[G[u][i].to]=u;
                preve[G[u][i].to]=i;
                if(!inque[G[u][i].to])
                {
                    inque[G[u][i].to]=true;
                    que.push(G[u][i].to);
                }
            }
        }
        inque[u]=false;
    }
}
ll min_cost_flow(int s,int t,int f)
{
    ll res=0;
    spfa(s);
    while(f>0)
    {
        dijkstra(s);
        if(dist[t]==INF) return res;
        if(h[t]+dist[t]>=0) return res;
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
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)&1) continue;
		for(int j=0;j<n;j++)
			v.push_back(make_pair(a[i]+a[i^(1<<j)],P(i,i^(1<<j))));
	}
	int need=min((1<<(n-1))*n,2*k*n+1);
	assert(v.size()>=need);
	nth_element(v.begin(),v.begin()+need,v.end(),greater<pair<int,P> >());
	vector<pair<int,P> > tmp;
	for(int i=0;i<need;i++) tmp.push_back(v[i]); 
	vector<int> vertices;
	for(auto p:tmp) vertices.push_back(p.S.F),vertices.push_back(p.S.S);
	sort(vertices.begin(),vertices.end()); 
	vertices.erase(unique(vertices.begin(),vertices.end()),vertices.end());
	int sz=(int)vertices.size(),s=sz+1,t=sz+2;
	V=t;
	for(auto x:vertices)
	{
		int id=lower_bound(vertices.begin(),vertices.end(),x)-vertices.begin()+1;
		if(__builtin_popcount(x)&1) add_edge(id,t,1,0); else add_edge(s,id,1,0);
	}
	for(auto p:tmp)
	{
		int u=lower_bound(vertices.begin(),vertices.end(),p.S.F)-vertices.begin()+1;
		int v=lower_bound(vertices.begin(),vertices.end(),p.S.S)-vertices.begin()+1;
		add_edge(u,v,1,-p.F);
	}
	printf("%lld",-min_cost_flow(s,t,k));
	return 0;
}