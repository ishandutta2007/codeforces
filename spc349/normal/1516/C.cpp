#include <bits/stdc++.h>
using namespace std;

int a[110];
bitset <200000> dp;

int main() {
	int n; cin >> n;
	int sum = 0;
	dp[0] = 1;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i], dp |= dp << a[i];
	if (!dp[sum / 2]) {
		printf("0\n");
		return 0;
	}
	while (1) {
		if (sum & 1) {
			printf("0\n");
			return 0;
		}
		for (int i = 0; i < n; i++) if (a[i] & 1) return 0 * printf("1\n%d\n", i + 1);
		sum >>= 1; for (int i = 0; i < n; i++) a[i] >>= 1;
	}
	return 0;
}