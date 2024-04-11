#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int a[505];
int dp[505][505];

int dfs(int l, int r) {
	if (dp[l][r] != inf)return dp[l][r];
	if (l >= r)return dp[l][r] = 1;
	if (a[l] == a[r])dp[l][r] = dfs(l + 1, r - 1);
	for (int i = l; i < r; ++i) {
		dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i + 1, r));
	}
	return dp[l][r];
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, 63, sizeof dp);
	printf("%d\n", dfs(0, n - 1));
	return 0;
}