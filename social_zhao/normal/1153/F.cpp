#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5005, P = 998244353, G = 3, iG = 332748118;
int n, k, len, invl, ans;
int r[N], pw1[N], pw2[N], fac[N], inv[N], f[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int n, int m) { return (n >= m)? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

void NTT(int *A, int type, int lim) {
	for(int i = 0; i < lim; i++) if(i < r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < lim; mid <<= 1) {
		int Wn = qpow(type == 1? G : iG, (P - 1) / (mid << 1));
		for(int i = 0; i < lim; i += mid << 1) {
			int w = 1;
			for(int j = 0; j < mid; j++, w = w * Wn % P) {
				int x = A[i + j], y = w * A[i + mid + j] % P;
				A[i + j] = (x + y) % P, A[i + mid + j] = (x - y + P) % P;
			}
		}
	}
	if(type == -1) {
		int inv = qpow(lim, P - 2);
		for(int i = 0; i < lim; i++) A[i] = A[i] * inv % P;
	}
}

void GetInt(int *A, int deg) {
	for(int i = deg; i > 0; i--) 
		A[i] = A[i - 1] * qpow(i, P - 2) % P;
	A[0] = 0;
}

main() {
	n = get(), k = get(), len = get(), invl = qpow(len, P - 2);
	init(n);
	int lim = 1, l = 0;
	while(lim <= n << 1) lim <<= 1, ++l;
	for(int i = 1; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	
	for(int t = 0; t < lim; t++) {
		int x = qpow(G, (P - 1) / lim * t);
		int d1 = 2 * x * (P + len - x) % P * invl % P * invl % P, d2 = (1 - d1 + P) % P;
		pw1[0] = pw2[0] = 1;
		for(int i = 1; i <= n; i++) 
			pw1[i] = pw1[i - 1] * d1 % P, pw2[i] = pw2[i - 1] * d2 % P;
		for(int i = k; i <= n; i++) 
			f[t] = (f[t] + C(n, i) * pw1[i] % P * pw2[n - i] % P) % P;
	}
	
	NTT(f, -1, lim);
	
	GetInt(f, 2 * n + 1);
	
	for(int i = 0; i <= 2 * n + 1; i++) 
		ans = (ans + f[i] * qpow(len, i) % P) % P;
	
	printf("%lld\n", ans);
	return 0;
}