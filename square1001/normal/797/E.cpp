#include <cstdio>
int n, q, a[100009], p, k, dp[255][100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= 250; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (j + a[j] + i >= n) dp[i][j] = 1;
			else dp[i][j] = dp[i][j + a[j] + i] + 1;
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &p, &k); p--;
		if (k <= 250) printf("%d\n", dp[k][p]);
		else {
			int ret = 0;
			while (p < n) p += a[p] + k, ret++;
			printf("%d\n", ret);
		}
	}
	return 0;
}