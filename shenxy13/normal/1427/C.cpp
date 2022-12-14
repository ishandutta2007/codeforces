#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int r, n;
	scanf("%d %d", &r, &n);
	int t[n + 1], x[n + 1], y[n + 1], dp[n], sf[n];
	t[0] = 0;
	x[0] = y[0] = 1;
	for (int i = 1; i <= n; ++i) scanf("%d %d %d", &t[i], &x[i], &y[i]);
	dp[n] = sf[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = (i != 0);
		for (int j = i + 1; j <= min(n, i + 2 * r); ++j) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i]) dp[i] = max(dp[i], dp[j] + (i != 0));
		}
		if (i + 2 * r <= n) dp[i] = max(dp[i], sf[i + 2 * r] + (i != 0));
		sf[i] = max(sf[i + 1], dp[i]);
	}
	printf("%d", dp[0]);
	return 0;
}