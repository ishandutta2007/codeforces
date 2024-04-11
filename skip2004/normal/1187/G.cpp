#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;

typedef long long ll;
typedef std::pair<ll,int> pr;
namespace mcmf{
	const int maxn = 10010,maxm = 1001000;
	struct T{ int to,nxt,v,f; } way[maxm << 1];;
	int h[maxn],num = 1;
	inline void link(int x,int y,int v,int f){
		way[++num]={y,h[x],v,f},h[x]=num;
		way[++num]={x,h[y],0,-f},h[y]=num;
	}
	ll d[maxn],dis[maxn]; int vis[maxn],fr[maxn];
	inline void bellmanford(int s,int t){
		std::queue<int> q; std::fill(d + s,d + t + 1,1e18);
		for(d[s] = 0,q.push(s);!q.empty();){
			int t = q.front(); q.pop(); vis[t] = 0;
			for(int i=h[t];i;i=way[i].nxt) 
				if(way[i].v && d[way[i].to] > d[t] + way[i].f){
					d[way[i].to] = d[t] + way[i].f;
					if(!vis[way[i].to]) vis[way[i].to]=1,q.push(way[i].to);
				}
		}
	}
	inline bool dijkstra(int s,int t){
		std::priority_queue<pr,std::vector<pr>,std::greater<pr>> q;
		std::fill(dis + s,dis + t + 1,1e18);
		std::fill(vis + s,vis + t + 1,0);
		for(dis[s] = 0,q.push(pr(0,s));!q.empty();){
			pr t=q.top(); q.pop(); if(vis[t.second]) continue; vis[t.second] = 1;
			for(int i=h[t.second];i;i=way[i].nxt){
				const ll v = way[i].f + d[t.second] - d[way[i].to];
				if(way[i].v && dis[way[i].to] > dis[t.second] + v){
					dis[way[i].to] = dis[t.second] + v; fr[way[i].to] = i;
					q.push(pr(dis[way[i].to],way[i].to));
				}
			}
		}
		return dis[t] < 1e17;
	}
	inline std::pair<ll,ll> ek(int s,int t){
		bellmanford(s,t); ll flow = 0,cost = 0;
		while(dijkstra(s,t)){
			ll sum = 0,fl = 1e18;
			for(int i=fr[t];i;i=fr[way[i^1].to])
				fl = std::min<ll>(way[i].v,fl), sum += way[i].f;
			flow += fl,cost += fl * sum;
			for(int i=fr[t];i;i=fr[way[i^1].to]) way[i].v -= fl,way[i ^ 1].v += fl;
			for(int i=s;i<=t;++i) d[i] += dis[i];
		}
		return {flow,cost};
	}
}
int n, m, k, c, d;
inline int id(int node, int time) {
	return time * n + node;
}
using mcmf::link;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	cin >> n >> m >> k >> c >> d;
	for(int i = 0, x;i < k;++i) {
		cin >> x;
		link(0, x, 1, 0);
	}
	const int T = 100;
	const int to = id(n + 1, T);
	for(int i = 0, x, y;i < m;++i) {
		cin >> x >> y;
		for(int j = T;j > 0;--j) {
			for(int i = k;i > 0;--i) {
				link(id(x, j - 1), id(y, j), 1, (i + i - 1) * d);
				link(id(y, j - 1), id(x, j), 1, (i + i - 1) * d);
			}
		}
	}
	for(int j = T;j > 0;--j) {
		for(int i = 1;i <= n;++i) {
			link(id(i, j - 1), id(i, j), k, 0);
		}
	}
	for(int i = 0;i <= T;++i) {
		link(id(1, i), to, k, i * c);
	}
	auto res = mcmf::ek(0, to);
	cout << res.second << '\n';
	// cout << res.first << ' ' << res.second << '\n';
}