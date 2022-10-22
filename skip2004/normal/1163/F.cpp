#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m, q;
struct T {
	int to, nxt, v;
} way[maxn << 1];
int h[maxn], num = 1;
inline void link(int x, int y, int v) {
	way[++num] = {y, h[x], v}, h[x] = num;
	way[++num] = {x, h[y], v}, h[y] = num;
}
struct graph {
	typedef std::pair<ll, int> pr;
	std::priority_queue<pr, std::vector<pr>, std::greater<pr>> q;
	ll dis[maxn];
	int vis[maxn], fr[maxn];
	int lca[maxn], main_node;
	inline bool relax(int x, ll v) {
		if(dis[x] > v) {
			q.push(pr(dis[x] = v, x));
			return 1;
		}
		return 0;
	}
	inline void dij(int s) {
		main_node = n ^ 1 ^ s;
		rep(i, 1, n) {
			dis[i] = 1e18;
		}
		for(relax(s, 0);q.size();) {
			int x = q.top().second; q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			for(int i = h[x];i;i = way[i].nxt)
				if(relax(way[i].to, dis[x] + way[i].v)) {
					fr[way[i].to] = i;
				}
		}
	}
	int fa[maxn];
	std::vector<int> edge[maxn];
	inline void init() {
		rep(i, 1, n) {
			fa[i] = i;
		}
	}
	inline int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	inline bool update(int x, int y, int v) {
		if(dis[y] == dis[x] + v && find(x) != find(y)) {
			fa[find(x)] = find(y);
			edge[x].push_back(y);
			edge[y].push_back(x);
			return 1;
		}
		return 0;
	}
	inline void dfs0(int x, int fa = 0) {
		this -> fa[x] = fa;
		for(int i : edge[x]) if(i != fa) {
			dfs0(i, x);
		}
	}
	inline void set() {
		for(int i = main_node;i;i = fa[i])
			lca[i] = i;
	}
	inline int getlca(int x) {
		if(lca[x]) return lca[x];
		lca[x] = getlca(fa[x]);
		return lca[x];
	}
} g0, g1;
int u[maxn], v[maxn], w[maxn];
int on[maxn];
int cnt[maxn];
ll min[maxn << 2];
inline void build(int cur = 1,int l = 1,int r = n) {
	min[cur] = 1e18;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
}
inline void down(ll & x, ll y) {
	if(x > y) {
		x = y;
	}
}
inline void upt(int ql, int qr, ll v, int cur = 1, int l = 1,int r = n) {
	if(ql <= l && r <= qr) return down(min[cur], v);
	int mid = l + r >> 1;
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
}
inline ll test(int pos, int cur = 1, int l = 1, int r = n){
	ll ans = 1e18;
	for(;;) {
		down(ans, min[cur]);
		if(l == r) break;
		int mid = l + r >> 1;
		if(pos <= mid) r = mid, cur <<= 1;
		else l = mid + 1, cur = cur << 1 | 1;
	}
	return ans;
}
inline void update(int x, int y, ll v) {
	if(g0.vis[x] && g1.vis[y]) {
		int A = g0.getlca(x), B = g1.getlca(y);
		if(cnt[B] < cnt[A]) {
			upt(cnt[B], cnt[A] - 1, v + g0.dis[x] + g1.dis[y]);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	rep(i, 1, m) {
		cin >> u[i] >> v[i] >> w[i];
		link(u[i], v[i], w[i]);
	}
	g0.dij(1), g1.dij(n);
	g0.init(), g1.init();
	int s0 = 0, s1 = 0;
	for(int i = n, c = 0;;) {
		cnt[i] = ++ c;
		if(i == 1) break;
		int E = g0.fr[i], e = E / 2;
		s0 += g0.update(u[e], v[e], w[e]);
		s0 += g0.update(v[e], u[e], w[e]);
		s1 += g1.update(u[e], v[e], w[e]);
		s1 += g1.update(v[e], u[e], w[e]);
		on[e] = 1;
		i = way[E ^ 1].to;
	}
	rep(e, 1, m) {
		s0 += g0.update(u[e], v[e], w[e]);
		s0 += g0.update(v[e], u[e], w[e]);
		s1 += g1.update(u[e], v[e], w[e]);
		s1 += g1.update(v[e], u[e], w[e]);
	}
	g0.dfs0(1), g1.dfs0(n);
	g0.set(), g1.set();
	build();
	rep(i, 1, m) if(!on[i]) {
		update(u[i], v[i], w[i]);
		update(v[i], u[i], w[i]);
	}
	rep(i, 1, q) {
		int t, x;
		cin >> t >> x;
		ll ans = std::min(g0.dis[u[t]] + g1.dis[v[t]], g0.dis[v[t]] + g1.dis[u[t]]) + x;
		if(on[t]) {
			down(ans, test(std::min(cnt[u[t]], cnt[v[t]])));
		} else {
			down(ans, g0.dis[n]);
		}
		cout << ans << '\n';
	}
}