#include <bits/stdc++.h>

using namespace std;

int a[3005];
int dp[3005][3005];

void solve() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			dp[i][j] = 3000;
		}
		int cnt = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (j + a[j] >= i) {
				dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt++);
			}
		}
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[n - 1][n - 1]);
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