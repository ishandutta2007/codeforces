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

const int N = (int) 1e5 + 7, L = 20, M = 1e7 + 7, mod = (int) 1e9 + 7;
int res[N], a[N], h[N], par[N][L], pr[M], qu[N], qv[N], qx[N], have[M];
vector<int> adj[N];
vector<pair<int, int>> qp[N];
void dfs_init(int v, int p = 0) {
	par[v][0] = p;
	h[v] = h[p] + 1;
	for (int j = 1; j < L; ++j)
		par[v][j] = par[par[v][j - 1]][j - 1];
	for (int u : adj[v]) if (u != p) {
		dfs_init(u, v);
	}
}
int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	for (int j = 0; j < L; ++j)
		if (h[u] - h[v] >> j & 1)
			u = par[u][j];
	if (u == v) return v;
	for (int j = L - 1; j >= 0; --j)
		if (par[u][j] != par[v][j])
			u = par[u][j], v = par[v][j];
	return par[v][0];
}
int pw(int a, int b) {
	if (b == 0) return 1;
	return (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod;
}
void add(int v, int coeff) {
	{
		int tmp = a[v];
		while (tmp != 1) {
			int p = pr[tmp];
			int cnt = 0;
			while (tmp % p == 0) {
				tmp /= p;
				++cnt;
			}
			int z = pw(p, cnt);
			have[z] += coeff;
		}
	}
}
void dfs_query(int v, int p = 0) {
	add(v, 1);
	for (auto q : qp[v]) {
		int id = q.x, coeff = q.y;
		{
			int tmp = qx[id];
			while (tmp != 1) {
				int px = pr[tmp], cnt = 0;
				while (tmp % px == 0) {
					tmp /= px;
					++cnt;
				}
				int power = 0;
				int z = 1, cp = 0;
				while ((LL) z * px < M) {
					++cp;
					z *= px;
					power += min(cp, cnt) * have[z];
				}
				res[id] = (LL) res[id] * (coeff == 1 ? pw(px, power) : pw(pw(px, power * 2), mod - 2)) % mod;
			}
		}
	}
	for (int u : adj[v]) if (u != p)
		dfs_query(u, v);
	add(v, -1);
}

int main() {
	for (int j = 2; j < M; ++j)
		if (pr[j] == 0)
			for (int i = j; i < M; i += j)
				pr[i] = j;
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs_init(0);
	for (int j = 0; j < n; ++j) cin >> a[j];
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		res[j] = 1;
		int &u = qu[j],	&v = qv[j], &x = qx[j];
		cin >> u >> v >> x;
		--u, --v;
		int p = lca(u, v);
		qp[u].push_back(mp(j, 1));
		qp[v].push_back(mp(j, 1));
		if (p != 0) {
			p = par[p][0];
			qp[p].push_back(mp(j, -2));
		}
	}
	dfs_query(0);
	for (int j = 0; j < q; ++j)
		cout << res[j] * (LL) pw(__gcd(qx[j], a[lca(qu[j], qv[j])]), mod - 2) % mod << '\n';
}