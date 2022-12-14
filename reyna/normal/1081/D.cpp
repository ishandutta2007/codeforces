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
int k, o[N], res[N], eu[N], ev[N], ew[N], par[N], g[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
int unite(int u, int v, int w) {
	u = find(u);
	v = find(v);
	if (u == v) return -1;
	g[v] += g[u];
	if (g[v] == k) {
		return w;			
	}
	par[u] = v;
	return -1;
}
int cmp(int x, int y) { return ew[x] < ew[y]; }
int xk[N];
int main() {
	for (int j = 0; j < N; ++j) par[j] = j, g[j] = 0, res[j] = 1e9 + 1;
	int n, m;
	cin >> n >> m >> k;
	for (int j = 0; j < k; ++j) {
		int &x = xk[j];
		cin >> x;
		--x;
		g[x] = 1;
	}
	for (int j = 0; j < m; ++j) {
		o[j] = j;
		int &u = eu[j], &v = ev[j], &w = ew[j];
		cin >> u >> v >> w;
		--u, --v;
	}
	sort(o, o + m, cmp);
	for (int i = 0; i < m; ++i) {
		int e = o[i];
		int u = eu[e], v = ev[e], w = ew[e];
		int x = unite(u, v, w);
		if (x >= 0) {
			for (int j = 0; j < k; ++j) cout << x << ' ';
			return 0;
		}
	}
	for (int j = 0; j < k; ++j) cout << res[xk[j]] << ' ';
}