#include <bits/stdc++.h>
using namespace std;
#define N 505

int n, m, mod, a[N];
long long f[2][N][N], c[N][N];
char s[N];

void prepare() {
	c[0][0] = 1;
	for (int i = 1; i < N; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}
}

int main() {
//	freopen("f.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &mod);
	prepare();
	for (int i = 1; i <= m; i ++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j ++) a[j] += s[j] - '0';
	}
	int zero = 0, one = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 0) zero ++;
		else if (a[i] == 1) one ++;
		else if (a[i] > 2) {
			puts("0"); return 0;
		}
	}
	f[m%2][zero][one] = 1;
	for (int i = m; i < n; i ++) {
		int I = i % 2, II = (i + 1) % 2;
		for (int j = 0; j <= n; j ++) {
			for (int k = 0; k <= n; k ++) if (f[I][j][k]) {
				if (j >= 2) {
					f[II][j-2][k+2] = (f[II][j-2][k+2] + c[j][2] * f[I][j][k]) % mod;
				}
				if (k >= 2) {
					f[II][j][k-2] = (f[II][j][k-2] + c[k][2] * f[I][j][k]) % mod;
				}
				if (j && k) {
					f[II][j-1][k] = (f[II][j-1][k] + c[j][1] * c[k][1] * f[I][j][k]) % mod;
				}
			}
		}
	}
	printf("%I64d\n", f[n%2][0][0]);
	return 0;
}