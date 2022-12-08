#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
vector<int> ig[N], og[N];
int dp[N];

int dfs(int p) {
	if (dp[p] != -1) return dp[p];
	if (og[p].size() <= 1) return dp[p] = 1;
	dp[p] = 0;
	for (int i: og[p]) if (ig[i].size() > 1) dp[p] = max(dp[p], dfs(i));
	return ++dp[p];
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		og[x].push_back(y);
		ig[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = -1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dfs(i));
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}