#include <bits/stdc++.h>

using namespace std;

int a[2505], b[5005];
int ca, cb;

int dp[2505][5005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		if (p) {
			a[++ca] = i;
		} else {
			b[++cb] = i;
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i <= ca; ++i) {
		for (int j = 0; j <= cb; ++j) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i + 1] - b[j + 1]));
		}
	}
	printf("%d\n", dp[ca][cb]);
	return 0;
}