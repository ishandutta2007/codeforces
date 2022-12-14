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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 2e5 + 5;
int sz[N], bfen[N], ipw[N], mark[N], rfen[N], n, mod, k, q, val[N], kpw[N], rin[N], rout[N], bin[N], bout[N];
int pw(int a, int b) { return b != 0? pw(1ll * a * a % mod, b >> 1) * 1ll * (b & 1? a: 1) % mod: 1; }
vector<int> adj[N];
void fen_update(int m, int x, int *fen) { m++;
	while (m > 0)
		fen[m] += x, m -= m & -m;
}

int query(int m, int *fen, int res = 0) { m++;
	while (m < N)
		res += fen[m], m += m & -m;
	return res;
}

int dfs_sz(int v, int p = -1) {
	if (mark[v]) {
		return 0;
	}
	sz[v] = 1;
	for (int u : adj[v]) if (u != p)
		sz[v] += dfs_sz(u, v);
	return sz[v];
}

int m;
pair<int, int> upath[N], dpath[N];
int dpval[N], upval[N], h[N], rcnt[N], bcnt[N];
vector<int> child[N];

void get_val(int v, int p, int g, int root, int dw = 0, int up = 0) {
	if (mark[v]) {
		return;
	}
	h[v] = (p == -1? 0: h[p] + 1);
	if (g != -1)
		child[g].push_back(v);
	child[root].push_back(v);
	dpval[v] = dw;
	upval[v] = up;
	for (int u : adj[v]) if (u != p) {
//		cout << h[v] << endl;
		get_val(u, v, g != -1? g: u, root, (dw + kpw[h[v] + 1] * 1ll * val[u]) % mod, (up * 1ll * k + val[u]) % mod);
	}
}

void seg_update(int l, int r, int *fen) {
	fen_update(r - 1, 1, fen);
	fen_update(l - 1, -1, fen);
}

pair<int, int> path[N];

void get_count(int root) {
	sort(dpath, dpath + m);
	for (int i = 0; i < m; ++i) {
		int v = upath[i].second, x = upath[i].first;

		x = x * 1ll * ipw[h[v]] % mod;
		x = (x - val[root] + mod) % mod;
		int reach = q * 1ll * ipw[h[v]] % mod;
		path[i].first = (reach - x + mod) % mod;
		path[i].second = v;
		int l = lower_bound(dpath, dpath + m, make_pair((reach - x + mod) % mod, -1LL)) - dpath;
		int r = lower_bound(dpath, dpath + m, make_pair((reach - x + mod) % mod, N)) - dpath;
		seg_update(l, r, rfen);
	}
	sort(path, path + m);
	for (int i = 0; i < m; ++i) {
		int v = dpath[i].second, x = dpath[i].first;
		int l = lower_bound(path, path + m, make_pair(x, -1LL)) - path;
		int r = lower_bound(path, path + m, make_pair(x, N)) - path;
		seg_update(l, r, bfen);
	}
	for (int i = 0; i < m; ++i)
		rcnt[dpath[i].second] = query(i, rfen), bcnt[path[i].second] = query(i, bfen);
	for (int i = 0; i <= m + 2; ++i)
		rfen[i] = bfen[i] = 0;
}

void solve(int v) {
	dfs_sz(v);
	int root = v;
	bool found = 0;
	while (!found) {
		found = 1;
		for (int u : adj[v]) if (!mark[u] && sz[u] < sz[v] && sz[u] > sz[root] / 2) {
			found = 0;
			v = u;
			break;
		}
	}
	get_val(v, -1, -1, v, val[v], val[v]);
	m = 0;
	for (int ch : child[v])
		upath[m] = make_pair(upval[ch], ch), dpath[m] = make_pair(dpval[ch], ch), m++;
	get_count(v);
	for (int ch : child[v])
		rin[ch] += rcnt[ch], rout[ch] += bcnt[ch];
	for (int u : adj[v]) if (!mark[u]) {
		m = 0;
		for (int ch : child[u])
			upath[m] = make_pair(upval[ch], ch), dpath[m] = make_pair(dpval[ch], ch), m++;
		get_count(v);
		for (int ch : child[u])
			rin[ch] -= rcnt[ch], rout[ch] -= bcnt[ch];
	}
	mark[v] = 1;
	for (int u : adj[v]) if (!mark[u]) {
		child[u].clear();
		solve(u);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> mod >> k >> q;
	rep(v, n)
		cin >> val[v], val[v] %= mod;
	kpw[0] = ipw[0] = 1;
	for (int i = 1; i < N; ++i)
		kpw[i] = kpw[i - 1] * 1ll * k % mod, ipw[i] = pw(kpw[i], mod - 2);
	rep(e, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve(0);
	long long res = 0;
	for (int v = 0; v < n; ++v)
		bin[v] = n - rin[v], bout[v] = n - rout[v];
	for (int v = 0; v < n; ++v)
		res += rin[v] * 1ll * bin[v] * 2 + rout[v] * 1ll * bout[v] * 2 + rin[v] * bout[v] + rout[v] * bin[v];
	cout << n * 1ll * n * n - res / 2 << endl;
}