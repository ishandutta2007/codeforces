#include <bits/stdc++.h>

using namespace std;

int a[1005][1005];
int sum[1005];
long long sum2[1005];

long long sqr(int x) {
	return 1LL * x * x;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int m, k;
	scanf("%d%d", &m, &k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
			sum2[i] += sqr(a[i][j]);
		}
	}
	int w = 0, c, d;
	if (sum[1] - sum[0] != sum[2] - sum[1]) {
		if (sum[3] - sum[2] == sum[4] - sum[3]) {
			if (sum[2] - sum[1] == sum[4] - sum[3])w = 0;
			else w = 1;
		} else w = 2;
	} else {
		for (int i = 1; i <= k; ++i) {
			if (sum[i] - sum[i - 1] != sum[1] - sum[0]) {
				w = i;
				break;
			}
		}
	}
	long long c2;
	if (w < 3) {
		c = sum[4] - sum[3];
		d = sum[w] - (sum[w + 1] - c);
		c2 = sum2[4] + sum2[4] - sum2[3] - sum2[5];
	} else {
		c = sum[1] - sum[0];
		d = sum[w] - (sum[w - 1] + c);
		c2 = sum2[1] + sum2[1] - sum2[0] - sum2[2];
	}
	if (w == 0) {
		for (int i = 0; i < m; ++i) {
			if (2 * sum2[1] - sum2[0] - sum2[2] + sqr(a[0][i]) - sqr(a[0][i] - d) == c2) {
				printf("%d %d\n", w, a[0][i] + d);
				fflush(stdout);
				return 0;
			}
		}
	} else if (w == k - 1) {
		for (int i = 0; i < m; ++i) {
			if (2 * sum2[w - 1] - sum2[w] - sum2[w - 2] + sqr(a[w][i]) - sqr(a[w][i] - d) == c2) {
				printf("%d %d\n", w, a[k - 1][i] + d);
				fflush(stdout);
				return 0;
			}
		}
	} else {
		for (int i = 0; i < m; ++i) {
			if (2 * sum2[w] - sum2[w - 1] - sum2[w + 1] - 2 * sqr(a[w][i]) + 2 * sqr(a[w][i] - d) == c2) {
				printf("%d %d\n", w, a[w][i] - d);
				fflush(stdout);
				return 0;
			}
		}
	}
	return 0;
}