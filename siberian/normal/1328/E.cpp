#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
const int MAXN = 2e5 + 10;
int m;
vector<int> g[MAXN];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

const int MAXLOG = 20;
int tin[MAXN], tout[MAXN], h[MAXN], timer = 0;
int dp[MAXN][MAXLOG];

void dfs(int v, int p, int len) {
	tin[v] = timer++;
	dp[v][0] = p;
	for (int i = 1; i < MAXLOG; i++)
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	h[v] = len++;
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v, len);
		}
	}
	tout[v] = timer++;
}

bool is_upper(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
	if (is_upper(v, u)) return v;
	if (is_upper(u, v)) return u;
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (!is_upper(dp[v][i], u)) {
			v = dp[v][i];
		}
	}
	return dp[v][0];
}

int dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(v, u)];
}

void solve() {
	int k;
	cin >> k;
	vector<int> a(k);
	for (auto &i : a) {
		cin >> i;
		i--;
	}
	int x = *min_element(all(a), [&] (int x, int y) {return h[x] > h[y];});
	for (auto i : a) {
		int l = lca(i, x);
		if (l == i) continue;
		if (is_upper(i, x)) continue;
		if (dist(i, l) <= 1) continue;
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

void run() {
	dfs(0, 0, 0);
	while (m--) {
		solve();
	}
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}