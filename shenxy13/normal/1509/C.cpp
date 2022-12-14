#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
	scanf("%d", &n);
	long long b[n], dp[n][n];
	for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
	sort(b, b + n);
	for (int i = 0; i < n; ++i) dp[i][i] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) dp[j][i + j] = b[i + j] - b[j] + min(dp[j + 1][i + j], dp[j][i + j - 1]);
	}
	printf("%lld\n", dp[0][n - 1]);
	return 0;
}