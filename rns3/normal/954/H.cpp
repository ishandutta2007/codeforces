#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define M 10005

const int mod = 1e9 + 7;
int u[N][M];
int n, m, a[N], b[N] = {1}, c[N] = {1}, d[N] = {1}, e[N];

int expmod(int a, int b, int mod) {
	int res = 1;
	for ( ; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}

int dunc(int k, int e) {
    if (k + e > n) return 0;
    return 1ll * c[k+e-1] * d[k-1] % mod;
}

int main() {
	scanf("%d", &n);
    for (int i = 1; i < n; i ++) scanf("%d", &a[i]), b[i] = expmod(a[i], mod - 2, mod);
    for (int i = 1; i < n; i ++) c[i] = 1ll * c[i-1] * a[i] % mod;
    for (int i = 1; i < n; i ++) d[i] = 1ll * d[i-1] * b[i] % mod;
    int m = 2 * n - 2;
    for (int i = 2; i <= n; i ++) {
        u[i][1] = 1;
        for (int j = 2; j <= m; j ++) {
            u[i][j] = (u[i-1][j-1] + 1ll * dunc(i-1, j-1) * (a[i-1] - 1) % mod * b[i-1]) % mod;
        }
    }
    int ans;
    for (int i = 1; i <= m; i ++) {
        ans = 0;
        for (int j = 1; j <= n; j ++) {
            ans = (ans + 1ll * c[j-1] * (u[j][i] + dunc(j, i))) % mod;
        }
        if (ans & 1) printf("%d\n", ans + mod >> 1);
        else printf("%d\n", ans >> 1);
    }
}