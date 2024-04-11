#include <bits/stdc++.h>
using namespace std;
#define N 202
#define mod 1000000007

typedef long long LL;

int n, a[N], s[N];
LL c[N][N], f[N][N], ans;

void prepare() {
	c[0][0] = 1;
	for (int i = 1; i <= 200; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}
}

inline LL h(int n, int k) {return c[n+k-1][k];}

int main() {
//	freopen("d.in", "r", stdin);
	prepare();
	scanf("%d", &n);
	for (int i = 0; i <= 9; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= 9; i ++) s[i] = s[i-1] + a[i];
	int sum = s[9];
	f[0][0] = 1;
	for (int i = 1; i <= 9; i ++) {
		for (int j = s[i-1]; j <= n; j ++) {
			for (int k = a[i]; k <= n - j; k ++) {
				f[i][j+k] = (f[i][j+k] + f[i-1][j] * c[j+k][j]) % mod;
			}
		}
	}
	for (int zero = a[0]; zero <= n; zero ++) {
		for (int other = sum; other <= n - zero; other ++) {
            ans = (ans + f[9][other] % mod * h(other, zero)) % mod;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}