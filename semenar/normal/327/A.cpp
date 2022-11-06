#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum[101];
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	int dp[101];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], sum[i - 1]) + 1 - a[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		dp[i] += sum[n] - sum[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans;

	return 0;
}