#include <bits/stdc++.h>
using namespace std;

#define N 1010101

const int K = 1 << 17;
const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

void print(int a[], int len = K) {
	for (int i = 0; i < len; i ++) printf(" %d", a[i]);puts("");
}

int rev_K = expmod(K, mod - 2);

int fib[K];

void calc_fib() {
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < K; i ++) fib[i] = (fib[i-1] + fib[i-2]) % mod;
}

int x[K], y[K], z[K], t[K], tt[K];

void fwt_xor(int a[], int len, bool fg) {
	for (int half = 1; half < len; half <<= 1) {
		for (int i = 0; i < len; i += half << 1) {
			for (int j = 0; j < half; j ++) {
				int x = a[i+j], y = a[i+j+half];
				a[i+j] = (x + y) % mod;
				a[i+j+half] = (x + mod - y) % mod;
			}
		}
	}
	if (fg) {
		for (int i = 0; i < len; i ++) a[i] = (1ll * rev_K * a[i]) % mod;
	}
}

void fwt(int a[], int len) {
	for (int half = 1; half < len; half <<= 1) {
		for (int i = 0; i < len; i += half << 1) {
			for (int j = 0; j < half; j ++) {
			//	a[i+j+half] = (a[i+j+half] + a[i+j]) % mod; /// or
				a[i+j] = (a[i+j+half] + a[i+j]) % mod; /// and
			}
		}
	}
}

void ufwt(int a[], int len) {
	for (int half = 1; half < len; half <<= 1) {
		for (int i = 0; i < len; i += half << 1) {
			for (int j = 0; j < half; j ++) {
			//	a[i+j+half] = (a[i+j+half] + mod - a[i+j]) % mod; /// or
				a[i+j] = (a[i+j] - a[i+j+half] + mod) % mod; /// and
			}
		}
	}
}

int id[100];

void calc_x() {
	x[0] = 1ll * y[0] * y[0] % mod;
	for (int n = 1; n < K; n ++) {
		for (int i = n & (n - 1); i; i = (i - 1) & n) x[n] = (x[n] + 1ll * y[i] * y[i^n]) % mod;
		x[n] = (x[n] + 2ll * y[0] * y[n]) % mod;
	}
}

void calc_z() {
	for (int i = 0; i < K; i ++) t[i] = y[i];
	fwt_xor(t, K, 0);
	for (int i = 0; i < K; i ++) z[i] = 1ll * t[i] * t[i] % mod;
	fwt_xor(z, K, 1);
}

void convert() {
	for (int i = 0; i < K; i ++) {
		x[i] = 1ll * x[i] * fib[i] % mod;
		y[i] = 1ll * y[i] * fib[i] % mod;
		z[i] = 1ll * z[i] * fib[i] % mod;
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	calc_fib();
	int n;
	scanf("%d", &n);
	for (int i = 1, now; i <= n; i ++) scanf("%d", &now), y[now] ++;
	calc_x();
	calc_z();
	convert();
	fwt(x, K);
	fwt(y, K);
	fwt(z, K);
	for (int i = 0; i < K; i ++) t[i] = 1ll * (1ll * x[i] * y[i] % mod) * z[i] % mod;
	ufwt(t, K);
	int ans = 0;
	for (int i = 1; i < K; i <<= 1) ans = (ans + t[i]) % mod;
	printf("%d\n", ans);

	return 0;
}