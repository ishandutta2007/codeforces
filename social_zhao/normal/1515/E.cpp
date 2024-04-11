#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 405;
int n, P;
int g[N], fac[N], inv[N];
int f[N][N]; // f[i][j]: 1~i j  

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	g[1] = 1;
	for(int i = 2; i <= n; i++) g[i] = g[i - 1] * 2 % P;
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int n, int m) { return n >= m? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

signed main() {
	n = get(), P = get();
	init(n);
	for(int i = 1; i <= n; i++) {
		f[i][i] = g[i];
		for(int j = 1; j < i; j++) {
			for(int k = 1; k < j; k++) {
				f[i][j] = (f[i][j] + f[i - k - 1][j - k] * g[k] % P * C(j, k) % P) % P;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = (ans + f[n][i]) % P;
	printf("%lld\n", ans);
	return 0;
}