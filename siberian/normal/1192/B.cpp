#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define data data228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct segment_tree{
	vector<ll> tree;
	vector<ll> mod;
	int n;
	segment_tree() {}

	void build(int v, int tl, int tr, const vector<ll> & a) {
		if (tl == tr - 1) {
			tree[v] = a[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm, a);
		build(v * 2 + 1, tm, tr, a);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}

	segment_tree(vector<ll> a) {
		n = a.size();
		tree.assign(n * 4, 0);
		mod.assign(n * 4, 0);
		build(1, 0, n, a);
	}

	void push(int v) {
		mod[v * 2] += mod[v];
		mod[v * 2 + 1] += mod[v];
		tree[v] += mod[v];
		mod[v] = 0;
	}

	ll get_val(int v) {
		return tree[v] + mod[v];
	}

	void upd(int v, int tl, int tr, int l, int r, ll add) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			mod[v] += add;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, l, r, add);
		upd(v * 2 + 1, tm, tr, l, r, add);
		tree[v] = max(get_val(v * 2), get_val(v * 2 + 1));
	}

	void upd(int l, int r, ll add) {
		upd(1, 0, n, l, r + 1, add);
	}

	ll get() {
		return get_val(1);
	}
};

struct fsetik{
	int v;
	ll dist;
	fsetik() {}
	fsetik(int _v, ll _dist) {
		v = _v, dist = _dist;
	}
};

bool operator<(const fsetik & a, const fsetik & b) {
	return tie(a.dist, a.v) < tie(b.dist, b.v);
}

struct edge{
	int to;
	ll cost;
	edge() {}
	edge(int _to, ll _cost) {
		to = _to, cost = _cost;
	}
};

struct event{
	int u, v;
	ll cost;
	event() {}
	event(int _u, int _v, ll _cost) {
		u = _u, v = _v, cost = _cost;
	}
};

const int MAXN = 1e5 + 10, MAXLOG = 17;
vector<edge> g[MAXN];
vector<event> ed;

int n, q;
ll w;

bool used[MAXN];
int sz[MAXN];
int centr;

int tin[MAXLOG][MAXN], tout[MAXLOG][MAXN], ind[MAXLOG][MAXN];
int timer;
vector<vector<ll>> dist[MAXN];
int par[MAXLOG][MAXN];
int h[MAXN];

vector<segment_tree> data[MAXN];
set<fsetik> help[MAXN];
set<fsetik> fans;

vector<ll> ans;

void read() {
	cin >> n >> q >> w;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		u--;
		v--;
		ed.push_back({u, v, c});
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
}

void dfs_centroid(int v, int p, int size) {
	sz[v] = 1;
	int mx = 0;
	for (auto [to, cost] : g[v]) {
		if (to == p) continue;
		if (used[to]) continue;
		dfs_centroid(to, v, size);
		chkmax(mx, sz[to]);
		sz[v] += sz[to];
	}
	chkmax(mx, size - sz[v]);
	if (mx <= size / 2) {
		centr = v;
	}
}

void dfs_calc(int v, int p, int centr, int Ind, int H, ll len) {
	tin[H][v] = timer++;
	ind[H][v] = Ind;
	dist[centr][dist[centr].size() - 1].push_back(len);
	par[H][v] = centr;

	for (auto [to, cost] : g[v]) {
		if (used[to]) continue;
		if (to == p) continue;
		dfs_calc(to, v, centr, Ind, H, len + cost);
	}	
	tout[H][v] = timer - 1;
}

void find_centroid(int v, int H, int size) {
	dfs_centroid(v, -1, size);
	v = centr;
	par[H][v] = v;
	used[v] = true;
	h[v] = H;
	int Ind = 0;
	tin[H][v] = -1;
	tout[H][v] = n + 1;
	for (auto [to, cost] : g[v]) {
		if (used[to]) continue;
		dist[v].push_back({});
		timer = 0;
		dfs_calc(to, -1, v, Ind++, H, cost);
	}
	
	for (auto [to, cost] : g[v]) {
		if (used[to]) continue;
		int fsz = sz[to];
		if (fsz > sz[v]) fsz = size - sz[v];
		find_centroid(to, H + 1, fsz);
	}
}

ll get_best(int v) {
	if (help[v].empty()) return 0;
	if (help[v].size() == 1) return help[v].begin()->dist;
	ll have = 0;
	auto it = help[v].end();
	--it;
	have += it->dist;
	--it;
	have += it->dist;
	return have;
}

void build() {
	find_centroid(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < dist[i].size(); j++) {
			data[i].push_back(segment_tree(dist[i][j]));
			help[i].insert({j, data[i][j].get()});
		}
		fans.insert({i, get_best(i)});
	}
}

void upd(int v, int Tin, int Tout, ll add, int ind) {
	fans.erase(fans.find({v, get_best(v)}));
	help[v].erase({ind, data[v][ind].get()});
	data[v][ind].upd(Tin, Tout, add);
	help[v].insert({ind, data[v][ind].get()});
	fans.insert({v, get_best(v)});
}

void upd(int pos, ll c) {
	int v = ed[pos].v;
	int u = ed[pos].u;
	ll add = c - ed[pos].cost;
	ed[pos].cost = c;

	for (int i = 0; i <= min(h[u], h[v]); i++) {
		assert(par[i][v] == par[i][u]);
		int find = ind[i][v];
		if (v == par[i][v])
			find = ind[i][u];

		int nv = par[i][v], Tin = max(tin[i][v], tin[i][u]), Tout = min(tout[i][v], tout[i][u]);
		upd(nv, Tin, Tout, add, find);		
	}
}

ll get() {
	assert(fans.size());
	return (--fans.end())->dist;
}

void run() {
	build();
	ll last = 0;

	while (q--) {
		int ind;
		ll c;
		cin >> ind >> c;
		ind = (ll) (ind + last) % (n - 1);
		c = (c + last) % w;
		upd(ind, c);
		last = get();
		ans.push_back(last);
	}
}

void write() {
	for (auto i : ans) {
		cout << i << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}