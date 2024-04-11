#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

struct vertex {
	ll l = 0, r = 0;
};

void dfs(vector<int>& l, vector<int>& r, vector<vector<int>>& g, vector<vertex>& dp, int v, int p = -1) {
	dp[v].l = 0;
	dp[v].r = 0;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(l, r, g, dp, u, v);
			dp[v].l += max(
				abs(l[v] - l[u]) + dp[u].l,
				abs(l[v] - r[u]) + dp[u].r
			);
			dp[v].r += max(
				abs(r[v] - l[u]) + dp[u].l,
				abs(r[v] - r[u]) + dp[u].r
			);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> l(n+1), r(n+1);
		vector<vector<int>> g(n+1);
		for (int i = 1; i <= n; ++i)
			cin >> l[i] >> r[i];
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<vertex> dp(n + 1, { 0, 0 });
		dfs(l, r, g, dp, 1);
		cout << max(dp[1].l, dp[1].r) << "\n";
	}
	return 0;
}