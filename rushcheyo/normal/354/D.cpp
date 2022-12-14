#include <bits/stdc++.h>
using namespace std;

const int M = 100005, L = 800;
int n, m, dp[2][L + 5], cnt[L + 5];
pair<int, int> p[M];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x - y + 1, y);
	}
	sort(p + 1, p + 1 + m);
	for (int i = 1, k = 1; i <= n; i++) {
		int l = min(L, n - i + 1);
		memset(cnt, 0, sizeof cnt);
		memset(dp[i & 1], 0, sizeof dp[i & 1]);
		for (; k <= m && p[k].first == i; k++)
			cnt[min(n - i + 1 - p[k].second + 1, l + 1)]++;
		for (int j = l; j >= 0; j--) cnt[j] += cnt[j + 1];
		for (int j = 0, mi = m * 3; j <= l; j++) {
			mi = min(mi, dp[i - 1 & 1][j]);
			dp[i & 1][j] = mi + j * (j + 1) / 2 + (j ? 2 : 0) + cnt[j + 1] * 3;
			if (dp[i - 1 & 1][j + 1])
				dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j + 1] + cnt[j + 1] * 3);
		}
	}
	printf("%d\n", min(dp[n & 1][0], dp[n & 1][1]));
	return 0;
}