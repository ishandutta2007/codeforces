#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
int n, m;
namespace flow {
	const int maxn = ::maxn;
	struct T {
		int to, nxt, v;
	} way[maxn << 4];
	int h[maxn], head[maxn], num = 1;
	inline void link(int x,int y,int v) {
		way[++num] = {y, h[x], v}, h[x] = num;
		way[++num] = {x, h[y], 0}, h[y] = num;
	}
	int dis[maxn], vis[maxn];
	inline bool bfs(int s,int t) {
		std::queue<int> q;
		for(int i = s;i <= t;++i) dis[i] = - 1, head[i] = h[i];
		for(q.push(s), dis[s] = 0;!q.empty();) {
			int t = q.front(); q.pop();
			for(int i = h[t];i;i = way[i].nxt) if(way[i].v && dis[way[i].to] < 0) 
				dis[way[i].to] = dis[t] + 1, q.push(way[i].to);
		}
		return dis[t] >= 0;
	}
	inline void dfs(int x) {
		vis[x] = 1;
		for(int i = h[x];i;i = way[i].nxt) if(!vis[way[i].to] && way[i].v) {
			dfs(way[i].to);
		}
	}
	inline int dfs(int s,int t,int lim) {
		if(s == t || !lim) return lim;
		int ans = 0, mn;
		for(int & i = head[s];i;i = way[i].nxt)
			if(dis[way[i].to] == dis[s] + 1 && (mn = dfs(way[i].to, t, std::min(lim, way[i].v)))) {
				way[i].v -= mn;
				way[i ^ 1].v += mn;
				ans += mn; lim -= mn;
				if(!lim) break;
			}
		return ans;
	}
	inline int dinic(int s,int t) {
		int ans = 0;
		for(;bfs(s,t);) ans += dfs(s,t,1e9);
		return ans;
	}
}
struct T {
	int to, nxt, id;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, int i) {
	way[++num] = {y, h[x], i}, h[x] = num;
	way[++num] = {x, h[y], i}, h[y] = num;
}
int fa[maxn], v[maxn], vis[maxn], tot;
typedef std::pair<int, int> pr;
std::vector<pr> vc[maxn];
const int inf = 1e8;
inline int find(int x) {
	if(fa[x] == x) return x;
	int o = find(fa[x]);
	if(o != fa[x]) {
		++ tot;
		flow::link(tot, v[x], inf);
		flow::link(tot, v[fa[x]], inf);
		v[x] = tot;
	}
	return fa[x] = o;
}
inline void dfs0(int x, int f = 0) {
	vis[x] = 1; fa[x] = x;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != f) {
		dfs0(way[i].to, x);
		fa[way[i].to] = x;
		v[way[i].to] = way[i].id;
	}
	for(auto i : vc[x]) if(vis[i.second]) {
		int lca = find(i.second);
		if(lca != i.second) flow::link(i.first + n, v[i.second], inf);
		if(lca != x) vc[lca].emplace_back(i.first, x);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y, i);
	}
	rep(i, 1, m) {
		int a, b;
		cin >> a >> b;
		vc[a].emplace_back(i, b);
		vc[b].emplace_back(i, a);
		flow::link(0, i + n, 1);
	}
	tot = n + m;
	dfs0(1);
	++ tot;
	rep(i, 1, n - 1) flow::link(i, tot, 1);
	int ans = flow::dinic(0, tot);
	cout << ans << '\n';
	flow::dfs(0);
	std::vector<int> v0, v1;
	for(int i = 1;i <= m;++i) if(flow::vis[i + n] ^ flow::vis[0]) v0.push_back(i);
	for(int i = 1;i < n;++i) if(flow::vis[i] ^ flow::vis[tot]) v1.push_back(i);
	cout << v0.size(); for(int i : v0) cout << ' ' << i; cout << '\n';
	cout << v1.size(); for(int i : v1) cout << ' ' << i; cout << '\n';
}