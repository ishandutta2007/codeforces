#include <bits/stdc++.h>
using namespace std;
#define N 505

int n, x, y;
long long a[N][N], sr[N], sc[N], d1, d2;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	if (n == 1) {
		puts("1"); return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%I64d", &a[i][j]);
			if (!a[i][j]) x = i, y = j;
			sr[i] += a[i][j];
			sc[j] += a[i][j];
			if (i == j) d1 += a[i][j];
			if (i + j == n + 1) d2 += a[i][j];
		}
	}
	long long sum = x > 1 ? sr[1] : sr[2];
	a[x][y] = sum - sr[x];
	if (a[x][y] <= 0) {
		puts("-1"); return 0;
	}
	memset(sr, 0, sizeof sr);
	memset(sc, 0, sizeof sc);
	d1 = d2 = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			sr[i] += a[i][j];
			sc[j] += a[i][j];
			if (i == j) d1 += a[i][j];
			if (i + j == n + 1) d2 += a[i][j];
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (sr[i] != sum || sc[i] != sum) {
			puts("-1"); return 0;
		}
	}
	if (d1 != sum || d2 != sum) {
		puts("-1"); return 0;
	}
	printf("%I64d\n", a[x][y]);
	return 0;
}