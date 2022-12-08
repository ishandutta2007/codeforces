#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, k, P, lim, f[N], g[N];
int fac[N], inv[N], iv[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = 1ll * res * ((y & 1)? x : 1) % P, x = 1ll * x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % P;
	iv[0] = iv[1] = 1;
	for(int i = 2; i <= n; i++) iv[i] = 1ll * (P - P / i) * iv[P % i] % P;
}

void FWT(int *A, int type) {
	for(int j = 0; j < 19; j++)
		for(int i = 0; i < lim; i++)
			if((i >> j) & 1) A[i] = (A[i] + 1ll * type * A[i ^ (1 << j)]) % P;
}

void Ln(int *A) {
	static int tmp[19];
	tmp[0] = 0;
	for(int i = 1; i < 19; i++) {
		tmp[i] = 0;
		for(int j = 0; j < i; j++) tmp[i] = (tmp[i] + 1ll * j * tmp[j] % P * A[i - j]) % P;
		tmp[i] = (A[i] - 1ll * tmp[i] * iv[i]) % P;
	}
	for(int i = 0; i < 19; i++) A[i] = (tmp[i] + P) % P;
}

void Exp(int *A) {
	static int tmp[19];
	tmp[0] = 1;
	for(int i = 1; i < 19; i++) {
		tmp[i] = 0;
		for(int j = 1; j <= i; j++) tmp[i] = (tmp[i] + 1ll * j * A[j] % P * tmp[i - j]) % P;
		tmp[i] = 1ll * tmp[i] * iv[i] % P;
	}
	for(int i = 0; i < 19; i++) A[i] = (tmp[i] + P) % P;
}

void qpow(int *A, int k) { // A = A ^ k
	static int tmpA[19][N], der[19];
	for(int i = 0; i < lim; i++) {
		for(int j = 0; j < 19; j++)
			if(j == __builtin_popcount(i)) tmpA[j][i] = A[i];
			else tmpA[j][i] = 0;
	}
	for(int i = 0; i < 19; i++) FWT(tmpA[i], 1);
	for(int i = 0; i < lim; i++) {
		for(int j = 0; j < 19; j++) der[j] = tmpA[j][i];
		Ln(der);
		for(int j = 0; j < 19; j++) der[j] = 1ll * der[j] * k % P;
		Exp(der);
		for(int j = 0; j < 19; j++) tmpA[j][i] = der[j] % P; 
	}
	for(int i = 0; i < 19; i++) FWT(tmpA[i], -1);
	for(int i = 1; i < lim; i++) A[i] = tmpA[__builtin_popcount(i)][i];
}

int solve() {
	lim = 1;
	while(lim <= n) lim <<= 1;
	for(int i = 0; i < lim; i++) f[i] = inv[i];
	qpow(f, k);
	return 1ll * f[n] * fac[n] % P;
}

main() {
	n = get(), k = get(), P = get();
	init(n);
	int ans = qpow(k, n);
	if(n % 2 == 0) ans -= solve();
	cout << (ans % P + P) % P;
	return 0;
}