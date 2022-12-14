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
#define int long long
#define double long double
const int N = (int) 1e5 + 5, mod = (int) 0;
map<pair<int, int>, int> mem;
int down[N], mark[N], up[N], most[N], par[N];
vector<int> adj[N], ver, all[N], sum[N];
void dfs_down(int v, int p = -1) {
	ver.push_back(v);
	mark[v] = 1;
	for (int u : adj[v]) if (u != p) {
		dfs_down(u, v);
		down[v] = max(down[v], down[u] + 1);
	}
}
void dfs_up(int v, int p = -1, int upd = 0) {
	int mx0 = upd, mx1 = -1;
	up[v] = upd;
	for (int u : adj[v]) if (u != p) {
		int val = down[u] + 1;
		if (mx0 < val)
			mx1 = mx0, mx0 = val;
		else if (mx1 < val)
			mx1 = val;
	}
	for (int u : adj[v]) if (u != p) {
		int to_send = (down[u] + 1 == mx0 ? mx1 : mx0) + 1;
		dfs_up(u, v, to_send);
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int v = 0; v < n; ++v) if (!mark[v]) {
		ver.clear();
		dfs_down(v);
		dfs_up(v);
		for (int x : ver) par[x] = v;
		for (int x : ver) {
			int dist = max(down[x], up[x]);
			all[v].push_back(dist);
			most[v] = max(most[v], dist); 
		}
		sort(ALL(all[v]));
		sum[v].resize(all[v].size() + 1);
		for (int j = sum[v].size() - 1; j >= 0; --j) {
			if (j + 1 != sum[v].size()) sum[v][j] = sum[v][j + 1];
			if (j != all[v].size()) sum[v][j] += all[v][j];
		}
	}
	cout << setprecision(10) << fixed;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u > v) swap(u, v);
		if (par[u] == par[v]) {
			cout << "-1" << '\n';
			continue;
		}
		u = par[u];
		v = par[v];
		if (u > v) swap(u, v);
		if (mem.find(mp(u, v)) != mem.end()) {
			cout << (double) mem[mp(u, v)] / (double) ((LL) all[u].size() * all[v].size()) << '\n';
			continue;
		}
		long long &res = mem[mp(u, v)];
		if (all[u].size() > all[v].size()) swap(u, v);
		int def = max(most[u], most[v]);
		for (int x : all[u]) {
			int pos = upper_bound(ALL(all[v]), def - x - 1) - all[v].begin();
			res += def * pos;
			res += sum[v][pos] + (x + 1) * (all[v].size() - pos);
			
		}
		cout << (double) res / (double) ((LL) all[u].size() * all[v].size()) << '\n';
	}
}