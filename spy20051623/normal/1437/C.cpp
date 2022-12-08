#include <bits/stdc++.h>

using namespace std;

int a[500];
int dp[500][500];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n + n; ++i) {
		for (int j = 1; j < min(i, n + 1); ++j) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(a[j] - i));
		}
		if (i <= n) dp[i][i] = dp[i - 1][i - 1] + abs(a[i] - i);
	}
	printf("%d\n", dp[n + n - 1][n]);
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