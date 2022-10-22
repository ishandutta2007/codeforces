#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300200;
typedef long long ll;
const int mod = 998244353;
int n, m, s;
struct T {
	int to, nxt, v;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, int v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
ll dis[maxn];
int vis[maxn];
inline void dij(int s) {
	rep(i, 1, n) {
		dis[i] = 1e18;
	}
	typedef std::pair<ll, int> pr;
	std::priority_queue<pr, std::vector<pr>, std::greater<pr>> q;
	for(q.emplace(dis[s] = 0, s);!q.empty();) {
		int x = q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = h[x];i;i = way[i].nxt) if(dis[way[i].to] > dis[x] + way[i].v) {
			q.emplace(dis[way[i].to] = dis[x] + way[i].v, way[i].to);
		}
	}
}
int ans;
namespace dag {
	struct T {
		int to, nxt;
	} way[maxn];
	int h[maxn], num;
	int cnt[maxn], fa[maxn], dep[maxn], bz[20][maxn];
	inline void link(int x, int y) {
		++ cnt[y];
		way[++num] = {y, h[x]}, h[x] = num;
	}
	inline int lca(int x, int y) {
		if(!x) return y;
		if(dep[x] > dep[y]) std::swap(x, y);
		for(int t = dep[y] - dep[x];t;t &= t - 1) y = bz[__builtin_ctz(t)][y];
		for(int i = 19;i >= 0;--i) if(bz[i][x] != bz[i][y]) {
			x = bz[i][x]; 
			y = bz[i][y];
		}
		return x == y ? x : bz[0][x];
	}
	int out[maxn];
	inline int find(int x) {
		return fa[x] = fa[x] == s ? x : fa[fa[x]];
	}
	inline void build() {
		rep(x, 1, n) for(int i = ::h[x];i;i = ::way[i].nxt) {
			if(dis[::way[i].to] == dis[x] + ::way[i].v){ 
				link(x, ::way[i].to);
			}
		}
		std::queue<int> q; q.push(s);
		for(;q.size();) {
			int x = q.front(); q.pop();
			dep[x] = dep[fa[x]] + 1;
			bz[0][x] = fa[x];
			if(x != s)
				++ out[find(x)];
			for(int i = 1;i < 20;++i) bz[i][x] = bz[i - 1][bz[i - 1][x]];
			for(int i = h[x];i;i = way[i].nxt) {
				fa[way[i].to] = lca(fa[way[i].to], x);
				if(!--cnt[way[i].to]) {
					q.push(way[i].to);
				}
			}
		}
		ans = * std::max_element(out + 1, out + n + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 0;i < m;++i) {
		int u, v, w;
		cin >> u >> v >> w;
		link(u, v, w);
	}
	dij(s);
	dag::build();
	cout << ans << '\n';
}