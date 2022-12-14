//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

int sz[N], szup[N], a[N], sub[N], dp[N], n, k;
vector<int> adj[N];
void dfs_down(int v, int lim, int p = -1) {
	sz[v] = sub[v] = 1;
	int sum = 0;
	for (int u : adj[v]) if (u != p) {
		dfs_down(u, lim, v);
		sz[v] += sz[u];
		sum += sz[u];
		sub[v] += sub[u];
	}
	dp[v] = sum + 1;
	for (int u : adj[v]) if (u != p) {
		if (sz[u] == 0) {
			sz[v] = 0;
		}
		dp[v] = max(dp[v], sum + 1 + dp[u] - sz[u]);
	}
	if (a[v] < lim)
		sz[v] = 0, dp[v] = 0;
	if (sz[v] == sub[v])
		dp[v] = sz[v];
//	cout << v << ' ' << dp[v] << ' ' << sz[v] << ' ' << sub[v] << endl;
}

bool flag = 0;

void dfs_up(int v, int lim, int upsz = 0, int upstay = 0, int p = -1) {
	int sum = 0, mx0 = 0, mx1 = 0;
	if (a[v] < lim)
		upsz = 0, upstay = 0;
//	cout << v << ' ' << upsz << ' ' << upstay << endl;
	for (int u : adj[v]) if (u != p) {
		sum += sz[u];
		if (dp[u] - sz[u] >= mx0)
			mx1 = mx0, mx0 = dp[u] - sz[u];
		else if (dp[u] - sz[u] >= mx1)
			mx1 = dp[u] - sz[u];
	}
//	cout << " hi " << v << ' ' << mx0 << ' ' << mx1 << endl;
	for (int u : adj[v]) if (u != p) {
		if (a[v] < lim) {
			dfs_up(u, lim, 0, 0, v);
		} else {
			int nxupstay = upstay + sum - sz[u];
			if (upsz == n - sub[v]) {
				if (mx0 == dp[u] - sz[u])
					smax(nxupstay, upstay + sum + mx1 - sz[u]);
				else
					smax(nxupstay, upstay + sum + mx0 - sz[u]);
			}
			if (mx0 == dp[u] - sz[u])
				smax(nxupstay, sum + mx1 - sz[u]);
			else
				smax(nxupstay, sum + mx0 - sz[u]);
			dfs_up(u, lim, upsz + sum - sz[u] + 1, nxupstay + 1, v);
		}
	}
	if (a[v] >= lim) {
//		cout << v << ' ' << sum + upstay + 1 << ' ' << sum << ' ' << upstay << ' ' << n - sub[v] << ' ' << upsz << ' ' << upsz + sum + 1 + mx0 << ' ' << mx0 << endl;
		if (sum + upstay + 1 >= k)
			flag = 1;
		if (n - sub[v] == upsz && upsz + sum + 1 + mx0 >= k)
			flag = 1;
	}
}

bool check(int lim) {
	flag = 0;
	dfs_down(0, lim);
	dfs_up(0, lim);
	return flag;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), k = read();
	rep(i, n)
		cin >> a[i];
	rep(i, n - 1) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
//	cout << check(4) << " hi " << endl;;
//	return 0;
	int bl = 0, br = 1e6 + 6;
	while (bl < br - 1) {
		int bm = (bl + br) >> 1;
		if (check(bm))
			bl = bm;
		else
			br = bm;
	}
	cout << bl << endl;
}