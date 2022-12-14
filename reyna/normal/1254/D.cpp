
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 2e5 + 5, sq = 405, mod = (int) 998244353;
int pw(int a, int b) {
	return (b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod);
}
int sz[N], par[N], tot, st[N], ed[N];
long long added[N], f[N];
vector<int> adj[N];
vector<pair<int, int>> ch[N];
void dfs_init(int v, int p = -1) {
	par[v] = p;
	sz[v] = 1;
	st[v] = tot++;
	for (int u : adj[v]) {
		if (u != p) {
			dfs_init(u, v);
			sz[v] += sz[u];
		}
	}
	ed[v] = tot;
}
long long query(int m) { ++m;
	long long res = 0;
	while (m < N) {
		res += f[m];
		m += m & -m;
	}
	return res;
}
void update(int m, long long x) { ++m;
	while (m > 0) {
		f[m] += x;
		m -= m & -m;
	}
}
void update(int l, int r, long long x) {
	update(r - 1, +x);
	update(l - 1, -x);
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs_init(0);
	for (int v = 0; v < n; ++v) {
		ch[v].push_back(mp(st[v], par[v]));
		for (int u : adj[v]) if (u != par[v]) {
			ch[v].push_back(mp(ed[u], u));	
		}
		ch[v].push_back(mp(N, par[v]));
	}
	vector<int> more;
	for (int j = 0; j < n; ++j)
		if ((int) adj[j].size() >= sq)
			more.push_back(j);
	int inv = pw(n, mod - 2);
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int v, d;
			cin >> v >> d;
			--v;
			added[v] += d;
			if ((int) adj[v].size() >= sq) {
				continue;
			}
			update(0, n, (LL) sz[v] * d);
			update(st[v], ed[v], (LL) -sz[v] * d);
			for (int u : adj[v]) if (u != par[v]) {
				update(st[u], ed[u], (LL) (n - sz[u]) * d);
			}
		} else {
			int v;
			cin >> v;
			--v;
			long long res = query(st[v]) + (LL) added[v] * n;
			for (int u : more) if (added[u]) {
				if (u != v) {
					int pos = upper_bound(ALL(ch[u]), mp(st[v], (int) 1e9)) - ch[u].begin();
					if (ch[u][pos].second == par[u]) {
						res += sz[u] * (LL) added[u];
					} else {
						int xc = ch[u][pos].second;
						res += (n - sz[xc]) * (LL) added[u];
					}
				}
			}
			cout << (res % mod * inv) % mod << '\n';
		}
	}
}