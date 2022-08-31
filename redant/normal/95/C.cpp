#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(int i=1;i<=(n);i++)
#define FORE(i,v) for(__typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)

#define MX 1005
#define PB(x) push_back(x)
#define SZ(v) (int)((v).size())
#define MP(x,y) make_pair(x,y)

typedef long long LL;

LL const inf = 1000000000000015ll;

int N, M, S, T;
vector<pair<int,LL> > G[MX], GG[MX];

LL dist[MX];
void dijkstra(int src)
{
	FOR(i,N) dist[i] = inf;
	dist[src]=0;
	priority_queue<pair<LL,int> > pq;
	pq.push(MP(0,src));
	while(!pq.empty())
	{
		int u = pq.top().second; 
		LL d = -pq.top().first;
		pq.pop();
		if(dist[u]<d) continue;
		for(int j=0;j<SZ(G[u]);j++)
		{
			int v = G[u][j].first; LL w = G[u][j].second;
			if(dist[u]+w<dist[v]){ dist[v]=dist[u]+w; pq.push(MP(-dist[v],v)); }
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	scanf("%d %d %d %d",&N,&M,&S,&T);
	
	FOR(i,M)
	{
		int a, b, w;
		scanf("%d %d %d",&a,&b,&w);
		G[a].PB(MP(b,w)); G[b].PB(MP(a,w));
	}
	
	FOR(i,N)
	{
		int t, c;
		scanf("%d %d",&t,&c);
		dijkstra(i);
		FOR(j,N) 
			if(dist[j]<=t)
			{
				GG[i].PB(MP(j,c));	
			}
	}
	
	FOR(i,N) G[i] = GG[i];
	
	dijkstra(S);
	
	LL r = (dist[T]<inf) ? dist[T] : -1;
	
	cout<<r<<endl;
	
	return 0;
}