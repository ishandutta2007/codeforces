#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int dp[1000005];
int cnt[1000005];
int sum[1000005];

void init() {
	for (int i = 1; i <= 1000000; ++i) {
		for (int j = 1; j * i <= 1000000; ++j) {
			++cnt[i * j];
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	init();
	dp[0] = 1;
	dp[1] = 1;
	sum[0] = 1;
	sum[1] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 2; i < 1000005; ++i) {
		dp[i] = (sum[i - 1] + cnt[i] - 1) % mod;
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
	printf("%d", dp[n]);
	return 0;
}