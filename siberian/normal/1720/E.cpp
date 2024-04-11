#include <stdio.h>

#define N	500

int max(int a, int b) { return a > b ? a : b; }

int main() {
	static int aa[N][N], kk[N * N];
	int n, k_, i, j, i1, j1, i2, j2, ij, k;

	scanf("%d%d", &n, &k_);
	k = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			scanf("%d", &aa[i][j]), aa[i][j]--;
			if (kk[aa[i][j]]++ == 0)
				k++;
		}
	if (k <= k_) {
		printf("%d\n", k_ - k);
		return 0;
	}
	for (ij = -(n - 1); ij < n; ij++) {
		i1 = i2 = max(ij, 0), j1 = j2 = i1 - ij;
		while (i1 < n && j1 < n)
			if (k == k_ || k == k_ - 1) {
				printf("1\n");
				return 0;
			} else if (k < k_ || i2 == n || j2 == n) {
				for (i = i1; i < i2; i++)
					if (kk[aa[i][j1]]++ == 0)
						k++;
				for (j = j1 + 1; j < j2; j++)
					if (kk[aa[i1][j]]++ == 0)
						k++;
				i1++, j1++;
			} else {
				for (i = i1; i <= i2; i++)
					if (--kk[aa[i][j2]] == 0)
						k--;
				for (j = j1; j < j2; j++)
					if (--kk[aa[i2][j]] == 0)
						k--;
				i2++, j2++;
			}
	}
	printf("2\n");
	return 0;
}