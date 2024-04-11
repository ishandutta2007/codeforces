#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005, S = 1000, P = 1e9 + 7, sgn[] = {1, P - 1};
int n, m, ans;
int fac[S + 5], inv[S + 5];
int f[N][N][2][2], g[N];

int qpow(int x, int y) {
	int res(1);
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i <= S; i++) fac[i] = fac[i - 1] * i % P;
	inv[S] = qpow(fac[S], P - 2);
	for(int i = S; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int x, int y) { return x < y? 0 : fac[x] * inv[y] % P * inv[x - y] % P; }

signed main() {
	n = get(), m = get();
	init();
	f[1][0][0][0] = f[1][1][0][1] = 1;
	for(int i = 2; i <= n; i++) {
		f[i][0][0][0] = 1;
		for(int j = 1; j <= i; j++) {
			if(i != n) {
				(f[i][j][0][0] += f[i - 1][j - 1][0][0]) %= P;
				(f[i][j][1][0] += f[i - 1][j - 1][0][1]) %= P;
				(f[i][j][0][1] += f[i - 1][j - 1][0][0] + f[i - 1][j - 1][1][0]) %= P;
				(f[i][j][1][1] += f[i - 1][j - 1][0][1] + f[i - 1][j - 1][1][1]) %= P;
				(f[i][j][0][0] += f[i - 1][j][0][0] + f[i - 1][j][1][0]) %= P;
				(f[i][j][1][0] += f[i - 1][j][0][1] + f[i - 1][j][1][1]) %= P;
			}
			else {
				(f[i][j][0][0] += f[i - 1][j - 1][0][0]) %= P;
				(f[i][j][1][0] += f[i - 1][j - 1][0][1]) %= P;
				(f[i][j][0][0] += f[i - 1][j][0][0] + f[i - 1][j][1][0]) %= P;
				(f[i][j][1][0] += f[i - 1][j][0][1] + f[i - 1][j][1][1]) %= P;
			}
		}
	}
	for(int i = 0; i <= n; i++) g[i] = (f[n][i][0][0] + f[n][i][1][0]) * fac[n - i] % P;
	for(int i = m; i <= n; i++) ans = (ans + sgn[(i - m) & 1] * C(i, m) % P * g[i] % P) % P;
	printf("%lld\n", ans);
	return 0;
}