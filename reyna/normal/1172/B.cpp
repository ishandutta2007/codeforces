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

const int N = (int) 1e6 + 6, mod = (int) 998244353;
vector<int> adj[N];
int sz[N], f[N];
int dfs(int v, int p = -1) {
	int cnt = 0;
	int res = 1;
	for (int u : adj[v]) if (u != p) {
		res = (LL) res * dfs(u, v) % mod;
		++cnt;
		sz[v] += sz[u];
	}
	sz[v]++;
	if (v == 0) {
		res = (LL) res * f[cnt] % mod * sz[0] % mod;
		return res;
	}
	res = (LL) res % mod * f[cnt + 1] % mod;
	return res;
	
}
int main() {
	f[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout << dfs(0) << endl;
}