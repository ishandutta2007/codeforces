#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 5e5 + 10;

vector<int> g[MAXN];
int n;
int sz[MAXN];

void dfs_sz(int v, int p) {
	sz[v] = 1;
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs_sz(i, v);
		sz[v] += sz[i];
	}
}

int ans[MAXN][2];

void calc(int v, int p, int l, int r, int flag) {
	//cout << "v = " << v << " l = " << l << " r = " << r << endl;
	int cnt = g[v].size() - flag;
	ans[v][0] = cnt + (sz[v] - 1 - cnt) * 2 + l;
	//cout << ans[v][0] << " " << ans[v][1] << endl;
	for (auto i : g[v]) {
		if (i == p) continue;
		ans[i][1] = r;
		r--;
		calc(i, v, l, l + sz[i] * 2 - 2, 1);
		l += sz[i] * 2 - 1;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs_sz(0, 0);
	/*cout << "sz = " << endl;
	for (int i = 0; i < n; i++)
		cout << sz[i] << " ";
	cout << endl;*/
	ans[0][1] = 2 * n;
	calc(0, 0, 1, 2 * n - 1, 0);
	for (int i = 0; i < n; i++)
		cout << ans[i][0] << " " << ans[i][1] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}