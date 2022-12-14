#include <cstdio>

#define N 505

int a[N];
int dp[N][N];

int calc(int l, int r) {
	if (dp[l][r]) return dp[l][r];
	int &rlt = dp[l][r];
	if (l == r) return rlt = 1;
	rlt = r - l + 1;
	if (a[l] == a[r]) {
		if (l + 1 < r) rlt = calc(l + 1, r - 1);
		else rlt = 1;
	}
	for (int i = l; i < r; i ++) {
		int tmp = calc(l, i) + calc(i + 1, r);
		if (rlt > tmp) rlt = tmp;
	}
	return rlt;
}

main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	printf("%d\n", calc(1, n));
}