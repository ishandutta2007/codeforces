#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
int dp[N][2], sum[N][2], ans[N];

int dfs(int p, int k, int f) {
	if (dp[p][k] != -1) return dp[p][k];
	dp[p][k] = k;
	sum[p][k] = k ? g[p].size() : 1;
	if (k) {
		for (int i: g[p]) {
			if (i == f) continue;
			dp[p][k] += dfs(i, 0, p);
			sum[p][k] += sum[i][0];
		}
	} else {
		for (int i: g[p]) {
			if (i == f) continue;
			if (dfs(i, 0, p) > dfs(i, 1, p)) {
				dp[p][k] += dp[i][0];
				sum[p][k] += sum[i][0];
			} else if (dfs(i, 0, p) < dfs(i, 1, p)) {
				dp[p][k] += dp[i][1];
				sum[p][k] += sum[i][1];
			} else {
				dp[p][k] += dp[i][0];
				sum[p][k] += min(sum[i][0], sum[i][1]);
			}
		}
	}
	return dp[p][k];
}

void dfs1(int p, int k, int f) {
	ans[p] = k ? g[p].size() : 1;
	if (k) {
		for (int i: g[p]) {
			if (i == f) continue;
			dfs1(i, 0, p);
		}
	} else {
		for (int i: g[p]) {
			if (i == f) continue;
			if (dp[i][0] > dp[i][1]) dfs1(i, 0, p);
			else if (dp[i][0] < dp[i][1]) dfs1(i, 1, p);
			else if (sum[i][0] < sum[i][1]) dfs1(i, 0, p);
			else dfs1(i, 1, p);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (n == 2) {
		cout << "2 2\n1 1\n";
		return 0;
	}
	memset(dp, -1, sizeof dp);
	dfs(1, 0, 0);
	dfs(1, 1, 0);
	g[0].push_back(1);
	dfs1(0, 0, 0);
	if (dp[1][0] > dp[1][1]) cout << dp[1][0] << ' ' << sum[1][0] << '\n';
	else if (dp[1][0] < dp[1][1]) cout << dp[1][1] << ' ' << sum[1][1] << '\n';
	else if (sum[1][0] < sum[1][1]) cout << dp[1][0] << ' ' << sum[1][0] << '\n';
	else cout << dp[1][1] << ' ' << sum[1][1] << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}