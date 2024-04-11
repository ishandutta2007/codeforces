#include <bits/stdc++.h>
using namespace std;
#define N 111
typedef long long LL;
#define mod 1000000007

int n, k;
long long m, x[N], c[N][N], a[N][N], b[N*N], d[N*N];

LL expmod(LL a, LL b) {
	b %= (mod - 1);
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	cin >> n >> m >> k;
    c[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
	for (int i = 1; i <= n; i ++) {
		x[i] = m / n;
		if (m % n >= i) x[i] ++;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) a[i][j] = expmod(c[n][j], x[i]);
	}

	for (int j = 0; j <= n; j ++) b[j] = a[1][j];
	for (int i = 2; i <= n; i ++) {
        for (int j = 0; j <= n * n; j ++) d[j] = 0;
        for (int j = 0; j <= n * n; j ++) {
			for (int k = 0; k <= n; k ++) if (j + k <= n * n) {
				d[j+k] = (d[j+k] + b[j] * a[i][k]) % mod;
			}
        }
        for (int j = 0; j <= n * n; j ++) b[j] = d[j];
	}
	cout << b[k] << endl;
	return 0;
}