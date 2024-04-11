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
const int N = (int) 2e5 + 5, mod = (int) 0;
vector<int> adj[N];
int n, cnt[N][2], sz[N], h[N];
int dfs(int v, int p = -1) {
	h[v] = (p == -1 ? 0 : h[p] ^ 1);
	int res = 0;
	sz[v] = 1;
	cnt[v][h[v]] = 1;
	for (int u : adj[v]) {
		if (u != p) {
			res += dfs(u, v);	
			sz[v] += sz[u];
			res += cnt[u][0] * cnt[v][1] + cnt[u][1] * cnt[v][0];
			cnt[v][0] += cnt[u][0];
			cnt[v][1] += cnt[u][1];
		}
	}
	res += sz[v] * (n - sz[v]);
	return res;
}
int32_t main() {
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout << dfs(0) / 2 << endl;
	
}