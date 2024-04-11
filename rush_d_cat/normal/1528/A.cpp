#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
vector<int> g[N];
int l[N], r[N];
LL dp[N][2];
void dfs(int u, int p) {
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += max(abs(l[u] - r[v]) + dp[v][1], abs(l[u] - l[v]) + dp[v][0]);
		dp[u][1] += max(abs(r[u] - r[v]) + dp[v][1], abs(r[u] - l[v]) + dp[v][0]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			g[i].clear(); 
			cin >> l[i] >> r[i];
			dp[i][0] = dp[i][1] = 0;
		}
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 1);
		cout << max(dp[1][0], dp[1][1]) << endl;
	}
}