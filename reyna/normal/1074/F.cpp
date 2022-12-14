// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 4e5 + 5, L = 20, mod = (int) 0;
vector<int> adj[N];
int n, used, up[N][L], heavy[N], tot, st[N], ed[N], ch[N << 2], mn[N << 2], cntmn[N << 2], tree_pos[N], head[N], par[N], sz[N], h[N];
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		cntmn[v] = 1;
		mn[v] = 0;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	mn[v] = min(mn[l], mn[r]);
	cntmn[v] = (mn[l] == mn[v] ? cntmn[l] : 0) + (mn[r] == mn[v] ? cntmn[r] : 0);
	mn[v] += ch[v];
}
pair<int, int> query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return mp(1e9, 0);
	if (i <= b && e <= j)
		return mp(mn[v], cntmn[v]);
	int m = b + e >> 1, l = v << 1, r = l | 1;
	auto xl = query(i, j, l, b, m);
	auto xr = query(i, j, r, m, e);
	int cur_mn = min(xl.x, xr.x);
	int cur_cnt = (xl.x == cur_mn ? xl.y : 0) + (xr.x == cur_mn ? xr.y : 0);
	return mp(cur_mn + ch[v], cur_cnt);
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		mn[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mn[v] = min(mn[l], mn[r]);
	cntmn[v] = (mn[l] == mn[v] ? cntmn[l] : 0) + (mn[r] == mn[v] ? cntmn[r] : 0);
	mn[v] += ch[v];
}
void dfs_hld(int v, int p = -1) {
	par[v] = p;
	st[v] = tot++;
	up[v][0] = (p == -1 ? 0 : p);
	for (int j = 1; j < L; ++j)
		up[v][j] = up[up[v][j - 1]][j - 1];
	sz[v] = 1;
	int maxsz = 0;
	for (int u : adj[v]) if (u != p) {
		h[u] = h[v] + 1;
		dfs_hld(u, v);
		sz[v] += sz[u];
		if (maxsz < sz[u])
			heavy[v] = u, maxsz = sz[u];
	}
	ed[v] = tot;
}

void build_hld() {
	memset(h, 0, sizeof h);
	memset(heavy, -1, sizeof heavy);
	memset(par, -1, sizeof par);
	//	for (int v = 0; v < n; ++v)
	//		if (par[v] == -1)
	dfs_hld(0);
	int used = 0;
	for (int v = 0; v < n; ++v)
		if (par[v] == -1 || heavy[par[v]] != v)
			for (int u = v; u != -1; u = heavy[u])
				tree_pos[u] = used++, head[u] = v;
}
int go_up(int v, int k) {
	for (int j = 0; j < L; ++j)
		if (k >> j & 1)
			v = up[v][j];
	return v;
}
int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	u = go_up(u, h[u] - h[v]);
	if (u == v) return v;
	for (int j = L - 1; j >= 0; --j)
		if (up[u][j] != up[v][j])
			u = up[u][j], v = up[v][j];
	return up[v][0];
}

void update_hld(int u, int v, int s) {
	while (head[u] != head[v]) {
		if (h[head[u]] > h[head[v]])
			swap(u, v);
		update(tree_pos[head[v]], tree_pos[v] + 1, s);
		v = par[head[v]];
	}
	if (h[v] < h[u])
		swap(u, v);
	update(tree_pos[u], tree_pos[v] + 1, s);
}
int main() {
	int q;
	cin >> n >> q;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	build_hld();
	build();
	map<pair<int, int>, int> have;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u > v) swap(u, v);
		int s = 1;
		have[mp(u, v)] ^= 1;
		if (!have[mp(u, v)]) s = -1;
		if (h[u] > h[v]) swap(u, v);
		int p = lca(u, v);
		if (u == p) {
			int cur = go_up(v, h[v] - h[u] - 1);
			update(st[cur], ed[cur], s);
			update(st[v], ed[v], -s);
			//update_hld(go_up(v, 1), go_up(v, h[v] - h[u] - 1), s);
		} else {
			update(0, n, s);
			update(st[u], ed[u], -s);
			update(st[v], ed[v], -s);
			//update_hld(go_up(v, 1), go_up(u, 1), s);
		}
		cout << (mn[1] == 0 ? cntmn[1] : 0) << '\n';
	}
}