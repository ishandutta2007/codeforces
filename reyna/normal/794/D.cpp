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
const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> adj[N], all[N];
pair<vector<int>, int> sr[N];
int par[N], n, m, num[N], deg[N], g[N], es[N], et[N];
map<int, int> have[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) { par[find(u)] = find(v); }
void dfs(int v, int d = 1) {
	num[v] = d;
	for (int u : adj[v]) if (!num[u]) {
		if (have[u][v] != (long long) SZ(all[u]) * SZ(all[v])) {
			cout << "NO\n";
			exit(0);
		}
		dfs(u, d + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int &u = es[j], &v = et[j];
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int j = 0; j < n; ++j) {
		adj[j].push_back(j);
		sort(adj[j].begin(), adj[j].end());
		sr[j] = mp(adj[j], j);
		adj[j].clear();
	}
	sort(sr, sr + n);
	g[sr[0].second] = 0;
	for (int j = 1; j < n; ++j) {
		if (sr[j].first == sr[j - 1].first) {
			g[sr[j].second] = g[sr[j - 1].second];	
		} else {
			g[sr[j].second] = g[sr[j - 1].second] + 1;
		}
	}
	int cnt = 1 + g[sr[n - 1].second];
	for (int j = 0; j < N; ++j) par[j] = j;
	for (int j = 0; j < m; ++j) {
		int u = es[j], v = et[j];
		if (g[u] != g[v]) {
			unite(g[u], g[v]);
			have[g[u]][g[v]]++;
			have[g[v]][g[u]]++;
			if (have[g[u]][g[v]] == 1) {
				adj[g[u]].push_back(g[v]);
				adj[g[v]].push_back(g[u]);
				deg[g[u]]++;
				deg[g[v]]++;
			}
		} else {
			have[g[u]][g[u]]++;				
		}
	}
	for (int j = 0; j < n; ++j) all[g[j]].push_back(j);
	for (int j = 0; j < cnt; ++j) {
		if (par[j] != par[0]) {
//			cout << "NO\n";
//			return 0;
		}
	}
	for (int j = 0; j < cnt; ++j) {
		if (deg[j] >= 3) {
			cout << "NO\n";
			return 0;
		}
		int sz = SZ(all[j]);
		if ((long long) sz * (sz - 1) / 2 != have[j][j]) {
			cout << "NO\n";
			return 0;
		}
/*		for (int u : adj[j]) if (u != j) {
			if ((long long) sz * (long long) SZ(all[u]) != have[j][u]) {
				cout << "NO\n";
				return 0;
			}
		} */
	}
	for (int j = 0; j < cnt; ++j) {
		if (deg[j] <= 1) {
			dfs(j);
			break;
		}
	}
	for (int j = 0; j < cnt; ++j) num[j] += N;
	for (int j = 0; j < m; ++j) {
		int u = es[j], v = et[j];
		u = g[u];
		v = g[v];
		if (abs(num[u] - num[v]) > 1) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int j = 0; j < n; ++j) {
		cout << num[g[j]] << ' ';	
	}
}