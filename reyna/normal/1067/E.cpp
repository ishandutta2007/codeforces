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

const int N = (int) 5e5 + 5, mod = (int) 998244353;
int n, dp[N][2][2], p2[N], ip2[N], odp[2][2], res, sz[N];
vector<int> adj[N];
int pw(int a, int b) { return b == 0 ? 1 : pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
void sadd(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
}
void dfs(int v, int p = -1) {
	dp[v][1][0] = 1;
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u] + 1;
			memcpy(odp, dp[v], sizeof odp);
			memset(dp[v], 0, sizeof odp);
			for (int use = 0; use <= 1; ++use) {
				for (int ua = 0; ua <= 1; ++ua)
					for (int ub = 0; ub <= 1; ++ub) {
						for (int va = 0; va <= 1; ++va)
							for (int vb = 0; vb <= 1; ++vb) {
								if (!use) {
									sadd(dp[v][va][vb], (LL) odp[va][vb] * dp[u][ua][ub] % mod);
								} else {
									int nva = ub & va;
									int nvb = ua | vb;
									sadd(dp[v][nva][nvb], (LL) odp[va][vb]  * dp[u][ua][ub] % mod);
									if (ua && vb) {
										res = (res - odp[va][vb] * (LL) dp[u][ua][ub] % mod * p2[n - 1 - sz[v]] % mod + mod) % mod;	
									}
								}
							}
					}
			}
		}
	}
	for (int b = 0; b <= 1; ++b) {
		res = (res - dp[v][1][b] * (LL) p2[n - 1 - sz[v] - (p != -1)] % mod + mod) % mod;
	}
}

int main() {
	p2[0] = ip2[0] = 1;
	p2[1] = 2;
	ip2[1] = pw(2, mod - 2);
	for (int j = 2; j < N; ++j) {
		p2[j] = p2[j - 1] * 2 % mod;
		ip2[j] = ip2[j - 1] * (LL) ip2[1] % mod;
	}
	ios_base::sync_with_stdio(0);
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 2 << endl;
		return 0;
	}
	res = n;
	for (int j = 0; j < n - 1; ++j) res = (res + res) % mod;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	cout << res << endl;
}