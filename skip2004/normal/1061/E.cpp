#include<bits/stdc++.h>

typedef long long ll;
const int maxn = 100100;

const int dijkstra_tag = 114514;
const int bellmanford_tag = 1919810;
template <const int Tag = dijkstra_tag, const int node_cnt = 100000, const int edge_cnt = 1000000>
struct Graph {
	static const int maxn = node_cnt + 10;
	struct edge {
		int to, nxt, v, f;
	} way[(edge_cnt + 100) << 1];
	int h[node_cnt], H[node_cnt], num, minidx, maxidx;
	inline Graph() {
		num = 1;
		minidx = 1e9;
		maxidx = 0;
	}
	inline void update(int x) {
		if(x < minidx) minidx = x;
		if(x > maxidx) maxidx = x;
	}
	inline void link(int x, int y, int v, int f) {
		update(x), update(y);
		way[++num] = (edge) {y, h[x], v, f}, h[x] = num;
		way[++num] = (edge) {x, h[y], 0, -f}, h[y] = num;
	}
	typedef long long ll;
	static const ll inf = 1e18;
	ll dis[maxn], d[maxn];
	int vis[maxn];
	inline ll calc(int x) {
		return Tag == dijkstra_tag ? way[x].f + d[way[x ^ 1].to] - d[way[x].to] : way[x].f; 
	}
	inline bool bellmanford(ll * dis, int s, int t) {
		std::queue<int> q;
		static int inq[maxn];
		for(int i = minidx;i <= maxidx;++i) dis[i] = inf;
		dis[s] = 0, q.push(s);
		for(;q.size();) {
			int x = q.front(); q.pop();
			inq[x] = 0;
			for(int i = h[x];i;i = way[i].nxt) if(way[i].v) {
				if(dis[way[i].to] > dis[x] + way[i].f) {
					dis[way[i].to] = dis[x] + way[i].f;
					if(!inq[way[i].to]) {
						q.push(way[i].to);
						inq[way[i].to] = 0;
					}
				}
			}
		}
		return dis[t] < inf;
	}
	inline bool dijkstra(int s, int t) {
		typedef std::pair<ll, int> pr;
		static int vis[maxn];
		for(int i = minidx;i <= maxidx;++i) dis[i] = inf, vis[i] = 0;
		std::priority_queue<pr, std::vector<pr>, std::greater<pr>> q;
		q.push(pr(dis[s] = 0, s));
		for(;q.size();) {
			int x = q.top().second; q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			for(int i = h[x];i;i = way[i].nxt) if(way[i].v) {
				if(dis[way[i].to] > dis[x] + calc(i)) {
					q.push(pr(dis[way[i].to] = dis[x] + calc(i), way[i].to));
				}
			}
		}
		return dis[t] < inf;
	}
	inline int dfs(int x, int t, int lim) {
		if(x == t || !lim) return lim;
		int ans = 0, mn;
		vis[x] = 1;
		for(int &i = H[x];i;i = way[i].nxt) {
			if(!vis[way[i].to] && dis[way[i].to] == dis[x] + calc(i) && (mn = dfs(way[i].to, t, std::min(lim, way[i].v)))) {
				ans += mn, lim -= mn;
				way[i].v -= mn, way[i ^ 1].v += mn;
				if(!lim) break;
			}
		}
		vis[x] = 0;
		return ans;
	}
	inline std::pair<ll, ll> flow(int s, int t) {
		ll cost = 0, sum = 0;
		if(dijkstra_tag == Tag) {
			bellmanford(d, s, t);
			do {
				for(int i = minidx;i <= maxidx;++i) H[i] = h[i];
				int c = dfs(s, t, 1e9);
				for(int i = minidx;i <= maxidx;++i) d[i] += dis[i];
				sum += c, cost += c * d[t];
			} while(dijkstra(s, t));
		} else {
			for(;bellmanford(dis, s, t);) {
				for(int i = minidx;i <= maxidx;++i) H[i] = h[i];
				int c = dfs(s, t, 1e9);
				sum += c;
				cost += c * dis[t];
			}
		}
		return std::pair<ll, ll>(sum, cost);
	}
};
Graph<> G;
int n, x, y;
int a[maxn];
int u0[maxn], v0[maxn];
int u1[maxn], v1[maxn];
int fa0[maxn], fa1[maxn];
int lim0[maxn], lim1[maxn];
int rem0[maxn], rem1[maxn];
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = (T) {y, h[x]}, h[x] = num;
	way[++num] = (T) {x, h[y]}, h[y] = num;
}
inline void dfs0(int x, int * fa, int f) {
	fa[x] = f;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != f) {
		dfs0(way[i].to, fa, x);
	}
}
inline void add(int * u, int * v, int * fa, int root) {
	memset(h, 0, sizeof h), num = 0;
	for(int i = 1;i < n;++i) link(u[i], v[i]);
	dfs0(root, fa, 0);
}
int main() {
	using std::cin;
	using std::cout;
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> x >> y;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1;i < n;++i) {
		cin >> u0[i] >> v0[i];
	}
	for(int i = 1;i < n;++i) {
		cin >> u1[i] >> v1[i];
	}
	int q;
	cin >> q;
	for(int i = 1, k;i <= q;++i) {
		cin >> k, cin >> lim0[k];
	}
	cin >> q;
	for(int i = 1, k;i <= q;++i) {
		cin >> k, cin >> lim1[k];
	}

	add(u0, v0, fa0, x);
	add(u1, v1, fa1, y);

	for(int i = 1;i <= n;++i) {
		rem0[i] = lim0[i];
		rem1[i] = lim1[i];
	}

	for(int i = 1;i <= n;++i) {
		int x = i, y = i;
		for(;!lim0[x];) x = fa0[x];
		for(;!lim1[y];) y = fa1[y];
		G.link(i, i + n, 1, -a[i]);
		G.link(x + n + n, i, 1, 0);
		G.link(i + n, y + n + n + n, 1, 0);
		if(lim0[i]) {
			for(x = fa0[x];x && !lim0[x];) x = fa0[x];
			rem0[x] -= lim0[i];
		}
		if(lim1[i]) {
			for(y = fa1[y];y && !lim1[y];) y = fa1[y];
			rem1[y] -= lim1[i];
		}
	}
	for(int i = 1;i <= n;++i) if(lim0[i]) {
		if(rem0[i] < 0) {
			cout << -1 << '\n';
			return 0;
		}
		G.link(0, i + n + n, rem0[i], 0);
	}
	for(int i = 1;i <= n;++i) if(lim1[i]) {
		if(rem1[i] < 0) {
			cout << -1 << '\n';
			return 0;
		}
		G.link(i + n + n + n, n + n + n + n + 1, rem1[i], 0);
	}
	std::pair<ll, ll> res = G.flow(0, n + n + n + n + 1);
	if(res.first != lim0[x] || res.first != lim1[y]) {
		cout << -1 << '\n';
	} else {
		cout << -res.second << '\n';
	}
}