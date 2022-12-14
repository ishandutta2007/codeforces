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
int sz[N], deg[N], s[N], mark[N], col[N], eu[N], ev[N], en;
vector<int> out[N], in[N], tp;
void add_edge(int u, int v) {
	out[u].pb(v);
	in[v].pb(u);
	eu[en] = u;
	ev[en] = v;
	en++;
}
void dfs(int v) {
	if (mark[v]++) return;
	for (int u : out[v]) dfs(u);
	tp.pb(v);
}
void sfd(int v, int c) {
	if (mark[v]++) return;
	col[v] = c;
	for (int u : in[v]) sfd(u, c);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, h;
	cin >> n >> m >> h;
	for (int j = 0; j < n; ++j) cin >> s[j];
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if ((s[u] + 1) % h == s[v]) {
			add_edge(u, v);	
		}
		if ((s[v] + 1) % h == s[u]) {
			add_edge(v, u);
		}
	}
	for (int j = 0; j < n; ++j) if (!mark[j]) dfs(j);
	memset(mark, 0, sizeof mark);
	reverse(ALL(tp));
	int cnt = 0;
	for (auto x : tp) if (!mark[x]) sfd(x, cnt++);
	for (int j = 0; j < n; ++j) out[j].clear(), in[j].clear();
	for (int e = 0; e < en; ++e) {
		int u = eu[e], v = ev[e];
		u = col[u];
		v = col[v];
		if (u != v) {
			deg[u]++;
		}
	}
	for (int v = 0; v < n; ++v) sz[col[v]]++;
	int mn = 1e9, id = -1;
	for (int v = 0; v < cnt; ++v) {
		if (deg[v] == 0 && mn > sz[v]) {
			mn = sz[v];	
			id = v;
		}
	}
	cout << mn << endl;
	for (int v = 0; v < n; ++v) if (col[v] == id) cout << v + 1 << ' ';
}