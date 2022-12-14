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
const long long mod2 = (LL) mod * mod;
int fpm(int a, int b) { return b != 0 ? fpm((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod: 1; }
int q[N * 10], phi[N], inv[N], h[N], mark[N], go[N], curdp[N], have[N], decr[N], ind[N], sz[N], a[N], dp[N], g[N], incr[N];
vector<int> dv[N], adj[N], all[N];
const int M = 3e5 + 5;
int b[M][64];
vector<int> ver;
void dfs_sz(int v, int p = -1) {
	if (mark[v]) return;
	sz[v] = 1;
	h[v] = (p == -1 ? 0 : h[p] + 1);
	ver.push_back(v);
	for (int u : adj[v])
		if (u != p && !mark[u])
			dfs_sz(u, v), sz[v] += sz[u];
}
int get_num(int root, int add = 0) {
	long long res = 0;
	ver.clear();
	dfs_sz(root);
	vector<int> see;
	int t = 0;
	for (int v : ver) {
		int p = a[v];
		int s = (int) all[p].size();
		if (b[p][0] == 0) {
			for (int mask = 0; mask < (1 << s); ++mask) {
				if (mask == 0) {
					b[p][0] = 1;
				} else {
					b[p][mask] = b[p][mask ^ (mask & -mask)] * all[p][ind[mask & -mask]];
				}
			}			
		}
		for (int mask = 0; mask < (1 << s); ++mask) {
/*			if (mask == 0) {
				have[mask] = 1;
			} else {
				have[mask] = have[mask ^ (mask & -mask)] * all[p][ind[mask & -mask]];
			} */
			if (!go[b[p][mask]]++) q[t++] = b[p][mask];
			int x = b[p][mask];
			dp[x] = (dp[x] + phi[p]);		
			if (dp[x] >= mod)
				dp[x] -= mod;
		}
	}
	for (int v : ver) {
		int p = a[v];
		int s = (int) all[p].size();
		for (int mask = 0; mask < (1 << s); ++mask) {	
	/*		if (mask == 0) {
				have[mask] = 1;
			} else {
				have[mask] = have[mask ^ (mask & -mask)] * all[p][ind[mask & -mask]];
			} */
			curdp[mask] = dp[b[p][mask]];
		}
		for (int j = 0; j < s; ++j)
			for (int m = 0; m < (1 << s - 1); ++m) {
				int mask = m ^ (m & (1 << j)) ^ ((m >> j & 1) << s - 1);
//				if (~mask >> j & 1) {
					curdp[mask] = (curdp[mask] - curdp[mask ^ (1 << j)]);
					if (curdp[mask] < 0) curdp[mask] += mod;	
//				}
			}
		long long cur_res = 0;
		for (int mask = 0; mask < (1 << s); ++mask) {
//			int x = b[p][mask];
//			for (int i = mask + 1; i < (1 << (int) all[p].size()); ++i) if ((i & mask) == mask) curdp[mask] = (curdp[mask] - curdp[i] + mod) % mod;
//			cout << " hi " << v << ' ' << p << ' ' << root << ' ' << add << ' ' << mask << ' ' << x << ' ' << curdp[mask] << endl;
//			for (int j = 0; j < (int) all[p].size(); ++j)
//				if (~mask >> j & 1)
//					curdp[mask] = (curdp[mask] - curdp[mask ^ (1 << j)] + mod) % mod;
			if (curdp[mask]) cur_res = (cur_res + (LL) curdp[mask] * incr[b[p][mask]]);
			if (cur_res >= mod2) cur_res -= mod2;
		}
		cur_res %= mod;
		res = (res + (LL) cur_res * phi[p] % mod * (h[v] + add)) % mod;
	}
	for (int j = 0; j < t; ++j) dp[q[j]] = 0, go[q[j]] = 0;
	return res % mod;
}
int solve(int root) {
	ver.clear();
	dfs_sz(root);
	int res = 0;
	int v = root;
	for (int u : ver) if (sz[u] >= sz[root] / 2 && sz[u] < sz[v]) v = u;
	res = (res + get_num(v)) % mod;
//	return res;
	mark[v] = 1;
	for (int u : adj[v]) if (!mark[u]) {
		int x = get_num(u, 1);
		res = (res - x + mod) % mod;
	}
	for (int u : adj[v]) if (!mark[u]) {
		res = (res + solve(u)) % mod;	
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < 18; ++j) ind[1 << j] = j;
	for (int j = 1; j <= n; ++j) inv[j] = fpm(j, mod - 2);
	for (int j = 1; j <= n; ++j) g[j] = incr[j] = decr[j] = 1;
	for (int j = 2; j <= n; ++j)
		if (!all[j].size())
			for (int i = j; i <= n; i += j) {
				all[i].push_back(j);
				g[i] *= j;
				decr[i] = (LL) decr[i] * (j - 1) % mod;
				decr[i] = (LL) decr[i] * inv[j] % mod;
				incr[i] = (LL) incr[i] * j % mod;
				incr[i] = (LL) incr[i] * inv[j - 1] % mod;
				
			}
	for (int j = 1; j <= n; ++j) phi[j] = (LL) j * decr[j] % mod;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
//	for (int j = 1; j <= n; ++j)
//		for (int i = j; i <= n; i += j)
//			dv[j].push_back(i);
	for (int j = 1; j < n; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (LL) solve(0) * fpm(((LL) n * (n - 1) / 2) % mod, mod - 2) % mod << endl;
}