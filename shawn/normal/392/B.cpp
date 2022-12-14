#include <bits/stdc++.h>

using namespace std;

long long n, a[3][3], f[41][3][3][3];
long long F(long long n, long long i, long long j, long long k) {
	long long &re = f[n][i][j][k];
	if (n == 1) return re = min(a[i][k], a[i][j] + a[j][k]);
	if (~re) return re;
	re = F(n - 1, i, k, j) + a[i][k] + F(n - 1, j, i, k);
	re = min(re, F(n - 1, i, j, k) + a[i][j] + F(n - 1, k, j, i) + a[j][k] + F(n - 1, i, j, k));
	return re;
}

int main() {
	memset(f, -1, sizeof f);
	for (int i = 0; i < 3; i ++) for (int j = 0; j < 3; j ++) scanf("%d", &a[i][j]);
	scanf("%d", &n);
	printf("%lld\n", F(n, 0, 1, 2));
	return 0;
}