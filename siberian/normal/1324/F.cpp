#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10;
int n;
int a[MAXN];
vector<int> g[MAXN];

int dp_down[MAXN], dp_up[MAXN];

void dfs_down(int v, int p) {
	dp_down[v] = 0;
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs_down(i, v);
		dp_down[v] += max(0, dp_down[i] + a[i]);
	}
}

void dfs_up(int v, int p) {
	int val = a[v] + dp_up[v];
	for (auto i : g[v]) {
		if (i == p) continue;
		val += max(0, dp_down[i] + a[i]);
	}
	for (auto i : g[v]) {
		if (i == p) continue;
		val -= max(0, dp_down[i] + a[i]);
		dp_up[i] = 0;
		chkmax(dp_up[i], val);
		val += max(0, dp_down[i] + a[i]);
	}

	for (auto i : g[v]) {
		if (i == p) continue;
		dfs_up(i, v);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) a[i] = 1;
		else a[i] = -1;
		dp_down[i] = dp_up[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs_down(0, -1);
	dfs_up(0, -1);


	/*cout << "dp_down = " << endl;
	for (int i = 0; i < n; i++)
		cout << dp_down[i] << " ";
	cout << endl;
	cout << "dp_up = " << endl;
	for (int i = 0; i < n; i++)
		cout << dp_up[i] << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++) {
		cout << dp_down[i] + dp_up[i] + a[i] << " ";
	}
	cout << endl;
	return 0;
}