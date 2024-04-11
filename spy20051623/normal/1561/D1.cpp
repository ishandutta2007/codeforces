#include <bits/stdc++.h>

using namespace std;

long long dp[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	dp[n] = 1;
	long long sum = 0;
	for (int i = n; i > 1; --i) {
		dp[i] += sum;
		dp[i] %= m;
		int s = sqrt(i), t = i / s;
		for (int j = 2; j <= s; ++j) {
			dp[i / j] += dp[i];
		}
		for (int j = 1; j < t; ++j) {
			int k = i / j - i / (j + 1);
			dp[j] += dp[i] * k;
		}
		sum += dp[i];
		sum %= m;
	}
	dp[1] += sum;
	dp[1] %= m;
	printf("%lld\n", dp[1]);
	return 0;
}