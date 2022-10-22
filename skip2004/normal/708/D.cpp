#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll,int> pr;
const int maxn = 10010,maxm = 1001000;
int n,m;
namespace mcmf{
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
int deg[maxn];
int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0);
    std::cin >> n >> m;
	ll ans = 0;
	using mcmf::link;
	for(int i = 1;i <= m;++i) {
		int u, v, c, f;
		std::cin >> u >> v >> c >> f;
		if(c < f) {
			ans += f - c;
			link(v, u, c, 1);
			link(u, v, f - c, 0);
			link(u, v, 1e9, 2);
			deg[v] += c; deg[u] -= c;
		} else {
			link(v, u, f, 1);
			link(u, v, c - f, 1);
			link(u, v, 1e9, 2);
			deg[v] += f; deg[u] -= f;
		}
	}
	for(int i = 1;i <= n;++i) {
		if(deg[i] > 0) link(0, i, deg[i], 0);
		if(deg[i] < 0) link(i, n + 1, -deg[i], 0);
	}
	link(n, 1, 1e9, 0);
	std::cout << ans + mcmf::ek(0,n + 1).second << '\n';
}