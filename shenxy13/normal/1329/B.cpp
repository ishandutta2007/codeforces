#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int d, m;
		scanf("%d %d", &d, &m);
		long long dp[30];
		int i;
		for (i = 29; i >= 0; --i) {
			if ((1 << i) > d) dp[i] = 0;
			else {
				dp[i] = d - (1 << i) + 1;
				break;
			}
		}
		for (--i; i >= 0; --i) {
			dp[i] = 1 << i;
			for (int j = i + 1; j < 30; ++j) dp[i] += (1 << i) * dp[j] % m, dp[i] %= m;
		}
		long long ans = 0;
		for (int i = 0; i < 30; ++i) ans = (ans + dp[i]) % m;
		printf("%lld\n", ans);
	}
	return 0;
}