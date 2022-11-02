#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct edge{
	int v, cost;
	edge() {
	}
	edge(int a, int b) {
		v = a, cost = b;
	}
};

int n, k;
vector<vector<edge> > g;

void read() {
	cin >> n >> k;
	g.assign(n, {});
	for (int i = 0; i < n - 1; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		g[u].push_back({v, cost});
		g[v].push_back({u, cost});
	}
}

vector<vector<int> > dp;

void dfs(int v, int p, int c) {
	for (auto i : g[v]) {
		if (i.v != p) {
			dfs(i.v, v, i.cost);
		}
	}
	vector<pair <int, int> > have;
	for (auto i : g[v]) {
		if (i.v != p) {
			have.push_back({dp[i.v][1] - dp[i.v][0], i.v});
		}
	}
	sort(have.begin(), have.end());
	reverse(have.begin(), have.end());
	dp[v][0] = 0;
	dp[v][1] = c;
	for (auto i : g[v]) {
		if (i.v != p) {
			dp[v][0] += dp[i.v][0];
			dp[v][1] += dp[i.v][0];
		}
	}
	for (int i = 0; i < min((int)have.size(), k); i++) {
		dp[v][0] += max(0LL, have[i].first); 
	}
	for (int i = 0; i < min((int)have.size(), k - 1); i++) {
		dp[v][1] += max(0LL, have[i].first); 
	}
}

void run() {
	dp.assign(n, vector<int> (2, 0));
	dfs(0, 0, 0);
}

void write() {
	cout << dp[0][0] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		read();
		run();
		write();
	}
	return 0;
}