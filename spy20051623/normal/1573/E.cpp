#include <bits/stdc++.h>

using namespace std;

int a[3005];
vector<int> v[3005];
int dp[3005][3005];

int dfs(int l, int r) {
	if (l >= r) return dp[l][r] = 0;
	if (dp[l][r] != -1) return dp[l][r];
	dp[l][r] = dfs(l + 1, r);
	for (int i: v[a[l]]) {
		if (i > l && i <= r) {
			dp[l][r] = max(dp[l][r], 1 + dfs(l + 1, i - 1) + dfs(i, r));
		}
	}
	return dp[l][r];
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		v[i].clear();
		memset(dp[i], -1, (n + 5) << 2);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	printf("%d\n", n - 1 - dfs(0, n - 1));
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}