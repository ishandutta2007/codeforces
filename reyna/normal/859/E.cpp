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

const int N = (int) 1e6 + 5, mod = (int) 1e9 + 7;

int dp[N][2], dead[N], par[N];
vector<int> adj[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
int unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 1;
	par[u] = v;
	dead[v] |= dead[u];
	return 0;
}
int dfs(int v, int p = -1) {
	int res = 1;
	for (int u : adj[v]) if (u != p) {
		res += dfs(u, v);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, res = 1;
	cin >> n;
	for (int j = 0; j < N; ++j) par[j] = j;
	for (int j = 0; j < n; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (unite(u, v)) {
			dead[find(v)] = 1;	
			if (u != v) {
				res = res * 2 % mod;	
			}
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int v = 0; v < 2 * n; ++v) {
		if (find(v) == v && !dead[v]) {
			res = (LL) res * dfs(v) % mod;
			dead[v] = 1;
		}
	}
	cout << res << '\n';
}