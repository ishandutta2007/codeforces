#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 52;
const LL MOD = 1e9 + 7;
int n, p, c[N];
LL C[N][N];

LL f[N][N][N][N];

void add(LL & x, LL y) {
	x += y;
	x %= MOD;
}

void upd(int i, int j, int k, int x) {
	// [i ~ n] is done
	// j: begin with white, 0
	// k: begin with white, 1
	// x: begin with black, 0
	// y: begin with black, 1
	if (f[i][j][k][x] == 0) return;
	int y = (n - i + 1) - (j + k + x);
	// printf("%d %d %d %d %d: %lld\n", i, j, k, x, y, f[i][j][k][x]);
	if (i == 1) return;
	for (int col = 0; col < 2; col ++) {
		if (c[i - 1] == -1 || c[i - 1] == col) {
			// printf("col = %d\n", col);
			if (col == 0) {
				LL w0 = ((1LL << x) % MOD) * ((1LL << y) / 2 % MOD) % MOD;
				LL w1 = ((1LL << x) % MOD) * ((1LL << y) % MOD) % MOD - w0;
				w1 = (w1 % MOD + MOD) % MOD;
				LL P = (1LL << (j + k)) % MOD;
				(w0 *= P) %= MOD;
				(w1 *= P) %= MOD;
				// printf("w0 = %lld, w1 = %lld\n", w0, w1);
				add(f[i-1][j + 1][k][x], f[i][j][k][x] * w0);
				add(f[i-1][j][k + 1][x], f[i][j][k][x] * w1);
			}
			if (col == 1) {
				LL w0 = ((1LL << j) % MOD) * ((1LL << k) / 2 % MOD) % MOD;
				LL w1 = ((1LL << j) % MOD) * ((1LL << k) % MOD) % MOD - w0;
				w1 = (w1 % MOD + MOD) % MOD;
				LL P = (1LL << (x + y)) % MOD;
				(w0 *= P) %= MOD;
				(w1 *= P) %= MOD;
				// printf("w0 = %lld, w1 = %lld\n", w0, w1);
				add(f[i-1][j][k][x + 1], f[i][j][k][x] * w0);
				add(f[i-1][j][k][x], f[i][j][k][x] * w1);				
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}

	f[n+1][0][0][0] = 1;
	for (int i = n + 1; i >= 1; i --) {
		int tot = n - i + 1;
		for (int j = 0; j <= tot; j ++) {
			for (int k = 0; k + j <= tot; k ++) {
				for (int x = 0; k + j + x <= tot; x ++) {
					upd(i, j, k, x);
				}
			}
		}
	}
	LL ans = 0;
	for (int j = 0; j <= n; j ++) 
	for (int k = 0; k + j <= n; k ++)
	for (int x = 0; j + k + x <= n; x ++) {
		int y = n - (j + k + x);
		if ( (k+y) % 2 == p ) add(ans, f[1][j][k][x]);
	}
	cout << ans << endl;
}