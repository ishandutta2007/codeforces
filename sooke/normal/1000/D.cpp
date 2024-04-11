#include <cstdio>
#define Maxn 1001
#define M(x) ((x) % 998244353)

int n, a[Maxn], f[Maxn][Maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			f[i][j] = M(f[i - 1][j] + f[i - 1][j + 1]);
		}
		if (a[i] > 0 && a[i] < n) {
			f[i][a[i]] = M(f[i][a[i]] + f[i - 1][0] + 1);
		}
	}
	printf("%d\n", f[n][0]);
	return 0;
}

// By Sooke.
// CF1000D Yet Another Problem On a Subsequence.