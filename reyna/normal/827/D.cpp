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

const int N = (int) 1e6 + 6, L = 20, mod = (int) 0, oo = (int) 2e9;
int h[N], up[N], ans[N], mark[N], es[N], et[N], ew[N], par[N], ed_up[N], go[N][L], mn[N][L];
pair<int, int> sr[N];
vector<int> adj[N];
int find(int x) { return up[x] == x ? x : up[x] = find(up[x]); }
int fx(int x) { return par[x] == x ? x : par[x] = fx(par[x]); }
int unite(int u, int v) {
	u = fx(u), v = fx(v);
	if (u == v) return 0;
	par[u] = v;
	return 1;
}
#define par go
pair<int, int> lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	int res = oo;
	for (int j = 0; j < L; ++j)
		if ((h[u] - h[v]) >> j & 1) {
			res = min(res, mn[u][j]);
			u = par[u][j];
		}
	if (u == v) return mp(v, res);
	for (int b = L - 1; b >= 0; --b)
		if (par[u][b] != par[v][b]) {
			res = min(res, mn[u][b]);
			res = min(res, mn[v][b]);
			u = par[u][b];
			v = par[v][b];
		}
	res = min(res, mn[v][0]);
	res = min(res, mn[u][0]);
	return mp(par[v][0], res);
}
#undef par
void dfs_init(int v, int p = 0, int ep = -1) {
	go[v][0] = p;
	mn[v][0] = (ep == -1 ? (int) -oo : -ew[ep]);
	ed_up[v] = ep;
	h[v] = h[p] + 1;
	for (int j = 1; j < L; ++j)
		go[v][j] = go[go[v][j - 1]][j - 1], mn[v][j] = min(mn[v][j - 1], mn[go[v][j - 1]][j - 1]);
	for (int e : adj[v]) if (e != ep) {
		int u = es[e] ^ et[e] ^ v;
		dfs_init(u, v, e);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int v = 0; v < n; ++v) par[v] = v, up[v] = v;
	for (int e = 0; e < m; ++e) {
		ans[e] = oo;
		int &u = es[e], &v = et[e], &w = ew[e];
		cin >> u >> v >> w;
		--u, --v;
		sr[e] = mp(w, e);	
	}
	sort(sr, sr + m);
	for (int j = 0; j < m; ++j) {
		int e = sr[j].second;
		int u = es[e], v = et[e], w = ew[e];
		if (unite(u, v)) {
			mark[e] = 1;
			adj[u].push_back(e);
			adj[v].push_back(e);
		}
	}
	dfs_init(0);
	for (int j = 0; j < m; ++j) {
		int e = sr[j].second;
		int u = es[e], v = et[e], w = ew[e];	
		if (!mark[e]) {
			auto cur = lca(u, v);
			ans[e] = min(ans[e], cur.second);
			int p = cur.first;
			while (u != v) {
				u = find(u);
				v = find(v);
				if (u == v) break;
				if (h[u] > h[v]) swap(u, v);
				if (h[v] < h[p]) assert(0);
				int ed = ed_up[v];
				ans[ed] = min(ans[ed], w);
				up[v] = find(go[v][0]);
				v = find(v);
			}
		}
	}
	for (int v = 0; v < n; ++v) up[v] = v;
	reverse(sr, sr + m);
	for (int j = 0; j < m; ++j) {
		int e = sr[j].second;
		int u = es[e], v = et[e], w = ew[e];	
		if (!mark[e]) {
			auto cur = lca(u, v);
			ans[e] = -cur.second;
			int p = cur.first;
			while (u != v) {
				u = find(u);
				v = find(v);
				if (u == v) break;
				if (h[u] > h[v]) swap(u, v);
				if (h[v] < h[p]) assert(0);
				int ed = ed_up[v];
				ans[ed] = min(ans[ed], w);
				up[v] = find(go[v][0]);
				v = find(v);
			}
		}
	}
	for (int e = 0; e < m; ++e) {
		int o = ans[e];
		if (o > oo - 10) {
			o = 0;
		}
		cout << o - 1 << ' ';
	}
}