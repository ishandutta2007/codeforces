#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009]; long long dp[200009][2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i >= 1) a[i] += a[i - 1];
	}
	long long r[2] = { -a[n - 1], -a[n - 1] }, ret = a[n - 1];
	for (int i = n - 2; i >= 1; i--) {
		dp[i][0] = r[1] + a[i];
		dp[i][1] = r[0] + a[i];
		r[0] = min(r[0], -dp[i][0]);
		r[1] = min(r[1], -dp[i][1]);
		ret = max(ret, dp[i][0]);
	}
	printf("%lld\n", ret);
	return 0;
}