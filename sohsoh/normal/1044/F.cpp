#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll LOG = 20;

int n, q;

namespace segment {
	pll sg[MAXN << 2];
	int lz[MAXN << 2];

	inline pll merge(pll a, pll b) {
		if (a.X != b.X) return min(a, b);
		return {a.X, a.Y + b.Y};
	}

	void build(int l = 1, int r = n, int v = 1) {
		if (l == r) sg[v] = {0, 1};
		else {
			int mid = (l + r) >> 1;
			build(l, mid, v << 1);
			build(mid + 1, r, v << 1 | 1);
			sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
		}
	}

	inline void push(int v) {
		sg[v].X += lz[v];
		if ((v << 1 | 1) < (MAXN << 2)) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		} 

		lz[v] = 0;
	}

	void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
		push(v);
		if (ql > r || qr < l) return;
		if (ql <= l && qr >= r) {
			lz[v] += val;
			push(v);
			return;
		}

		int mid = (l + r) >> 1;
		update(ql, qr, val, l, mid, v << 1);
		update(ql, qr, val, mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

int tin[MAXN], tout[MAXN], t, par[MAXN][LOG], H[MAXN];
vector<int> adj[MAXN];
set<pll> st;

void dfs(int v, int p) {
	tin[v] = ++t;
	par[v][0] = p;
	H[v] = H[p] + 1;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);

	tout[v] = t;
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

inline int LCA(int u, int v) {
	if (H[v] < H[u]) swap(v, u);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	segment::build();
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);

		int w = 0;
		if (st.find(make_pair(u, v)) == st.end()) {
			st.insert(make_pair(u, v));
			w = 1;
		} else {
			st.erase(make_pair(u, v));
			w = -1;
		}

		int lca = LCA(u, v);
		if (H[u] > H[v]) swap(u, v);
		if (lca == u) {
			int tu = Par(v, H[v] - H[u] - 1);
			segment::update(tin[tu], tout[tu], w);
			segment::update(tin[v], tout[v], -w);
		} else {
			segment::update(1, n, w);
			segment::update(tin[v], tout[v], -w);
			segment::update(tin[u], tout[u], -w);
		}

		cout << (segment::sg[1].X == 0 ? segment::sg[1].Y : 0) << endl;
	}
	return 0;
}