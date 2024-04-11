#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

struct best {
	int max = 0, min = 1e9;
};

struct who {
	best max, min;
};


vector<who> dp;
vector<int> sz;
vector<vector<int>> g;

void dfssz(int v, int p = -1) {
	if (p != -1 && g[v].size() == 1) {
		sz[v] = 1;
	}
	else {
		sz[v] = 0;
		for (auto u : g[v]) {
			if (u != p) {
				dfssz(u, v);
				sz[v] += sz[u];
			}
		}
	}
}

void dfs(int v, int p = -1) {
	if (p != -1 && g[v].size() == 1) {
		dp[v] = { {1, 1}, {1, 1} };
	}
	else {
		int maxmin = 0, minmax = 0;
		dp[v] = { {0, sz[v]}, {1, (int)1e9} };
		for (auto u : g[v]) {
			if (u != p) {
				dfs(u, v);
				dp[v].max.max = max(dp[v].max.max, dp[u].min.max + sz[v] - sz[u]);
				dp[v].max.min -= sz[u] - dp[u].min.min;

				dp[v].min.max += dp[u].max.max - 1;
				dp[v].min.min = min(dp[v].min.min, dp[u].max.min);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1 1";
		return 0;
	}
	g.resize(n + 1);
	sz.resize(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dp.resize(n + 1);
	dfssz(1);
	dfs(1);
	cout << dp[1].max.max << " " << dp[1].max.min;
	return 0;
}