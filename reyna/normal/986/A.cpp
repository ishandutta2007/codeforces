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
const int N = (int) 1e5 + 5, mod = (int) 0;
int d[N], q[N], a[N];
vector<int> adj[N], all[N], res[N];
int32_t main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for (int j = 0; j < n; ++j) cin >> a[j], --a[j], all[a[j]].push_back(j);
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int col = 0; col < k; ++col) {
		memset(d, 63, sizeof d);
		int h = 0, t = 0;
		for (int x : all[col]) d[x] = 0, q[t++] = x;
		while (h < t) {
			int v = q[h++];
			for (int u : adj[v]) if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q[t++] = u;
			}
		}
		for (int u = 0; u < n; ++u) res[u].pb(d[u]);
	}
	for (int v = 0; v < n; ++v) {
		sort(ALL(res[v]));
		int ans = 0;
		for (int j = 0; j < s; ++j) ans += res[v][j];
		cout << ans << ' ';
	}
	
	
}