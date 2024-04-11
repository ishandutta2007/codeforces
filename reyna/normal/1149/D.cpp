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

const int N = (int) 72, mod = (int) 0;
int ma[N][N], px[N], mb[N][N], par[N], sz[N], rev[N];
vector<pair<int, int>> adj[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) {
	par[find(u)] = find(v);	
}
int res[N], mark[N], q[N * N], dp[1 << 18][N], add_mask[N];
int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	memset(ma, 63, sizeof ma);
	memset(mb, 63, sizeof mb);
	for (int j = 0; j < n; ++j) par[j] = j, ma[j][j] = mb[j][j] = 0;
	for (int j = 0; j < m; ++j) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].push_back(mp(v, w));
		adj[v].push_back(mp(u, w));
		if (w == a) {
			unite(u, v);
			ma[u][v] = ma[v][u] = w;	
		} else {
			mb[u][v] = mb[v][u] = w;	
		}
	}
	for (int j = 0; j < n; ++j) {
		par[j] = find(j);
		sz[par[j]]++;
	}
	int tot = 0;
	for (int j = 0; j < n; ++j)
		if (par[j] == j && sz[j] >= 4) {
			px[tot] = j;
			rev[j] = tot++;
		}
	for (int j = 0; j < n; ++j) {
		if (sz[par[j]] >= 4) {
			add_mask[j] = 1 << rev[par[j]];	
		}
	}
	memset(dp, 63, sizeof dp);
	dp[add_mask[0]][0] = 0;
	for (int mask = 0; mask < 1 << tot; ++mask) {
		int h = 0, t = 0;
		for (int v = 0; v < n; ++v) q[t++] = v, mark[v] = 1;
		while (h != t) {
			int v = q[h++];
			mark[v] = 0;
			if (dp[mask][v] < 1e9) {
				for (auto e : adj[v]) {
					int u = e.first, w = e.second;
					if (par[u] == par[v] && w == b) continue;
					if (par[u] != par[v]) {
						if (!(mask & add_mask[u])) {
							if (dp[mask | add_mask[u]][u] > dp[mask][v] + w) {
								dp[mask | add_mask[u]][u] = dp[mask][v] + w;
								if (!add_mask[u] && !mark[u]) {
									mark[u] = 1;
									q[t++] = u;
								}
							}
						}
					} else {
						if (dp[mask][u] > dp[mask][v] + w) {
							dp[mask][u] = dp[mask][v] + w;	
							if (!mark[u]) {
								mark[u] = 1;
								q[t++] = u;
							}
						}
					}
				}
			}
		}
	}
	memset(res, 63, sizeof res);
	for (int mask = 0; mask < 1 << tot; ++mask)
		for (int v = 0; v < n; ++v)
			res[v] = min(res[v], dp[mask][v]);
	for (int j = 0; j < n; ++j)
		cout << res[j] << ' ';
	cout << endl;
}