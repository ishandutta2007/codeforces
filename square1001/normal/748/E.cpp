#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[1000009], dp[10000009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int low = 0;
	for (int i = 23; i >= 0; i--) {
		int x = low + (1 << i);
		fill(dp, dp + min(x, 10000001), 0);
		for (int j = x; j <= 10000000; j++) {
			if (j >= 2 * x) dp[j] = dp[j / 2] + dp[j - j / 2];
			else dp[j] = 1;
		}
		long long sum = 0;
		for (int j = 0; j < n; j++) sum += dp[a[j]];
		if (sum >= m) low += 1 << i;
	}
	cout << (low ? low : -1) << endl;
	return 0;
}