#include <bits/stdc++.h>
using namespace std;

#define N 305

const int mod = 1e9 + 7;

int n, a[N], b[N], bs;
int dp[N][N];

int C[N][N], fac[N];

void init() {
	fac[0] = 1;
	for (int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    C[0][0] = 1;
    for (int i = 1; i < N; i ++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j ++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }
    return;
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		int up = sqrt(a[i]);
        for (int x = 2; x <= up; x ++) {
			int y = x * x;
			while (a[i] % y == 0) a[i] /= y;
        }
	}
	sort(a+1, a+n+1);
    bs = 0;
    int last = 0;
    for (int i = 1; i <= n; i ++) {
        if (last == a[i]) b[bs] ++;
        else {
            last = a[i];
            b[++bs] = 1;
        }
    }
    for (int i = 1; i <= bs; i ++) a[i] = a[i-1] + b[i];
    dp[0][0] = 1;
    for (int i = 0; i < bs; i ++) {
		int up = max(0, a[i]-1);
        int sz = b[i+1], S = a[i];
        for (int j = 0; j <= up; j ++) {
            for (int x = 1; x <= b[i+1]; x ++) {
                int uq = min(x, j);
                for (int v = 0; v <= uq; v ++) {
                    (dp[i+1][j-v+sz-x] += 1ll * dp[i][j] * C[j][v] % mod * C[S+1-j][x-v] % mod * C[sz-1][x-1] % mod * fac[sz] % mod) %= mod;
                }
            }
        }
    }
    printf("%d\n", dp[bs][0]);
    return 0;
}