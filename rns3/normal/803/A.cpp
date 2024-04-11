#include <stdio.h>

#define N 110

int n, k, a[N][N] = {0};

int main() {
	scanf("%d %d", &n, &k);
	if (k > n * n) {
		puts("-1");
		return 0;
	}
	int i = 1, j = 2;
	for (int i = 1; i <= n && k; i ++) {
		for (int j = 1; j <= n && k; j ++) {
			if (a[i][j]) continue;
            if (i == j) {
				a[i][i] = 1;
				k --;
            }
            else {
				if (k == 1) {
					for (int t = 1; t <= n; t ++) if (a[t][t] == 0) {
						a[t][t] = 1;
						k = 0;
						break;
					}
				}
				else {
					a[i][j] = 1;
					a[j][i] = 1;
					k -= 2;
				}
            }
		}
	}
	for (i = 1; i <= n; i ++) {
		for (j = 1; j < n; j ++) printf("%d ", a[i][j]);
		printf("%d\n", a[i][n]);
	}
	return 0;
}