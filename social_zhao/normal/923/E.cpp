#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, P = 998244353, G = 3, iG = 332748118;
int n, m, f[N], g[N], r[N];
int fac[N], inv[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

void NTT(int *A, int lim, int type) {
	for(int i = 0; i < lim; i++) if(i < r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < lim; mid <<= 1) {
		int Wn = qpow(type == 1? G : iG, (P - 1) / (mid << 1));
		for(int i = 0; i < lim; i += mid << 1) {
			int w = 1;
			for(int j = 0; j < mid; j++, w = w * Wn % P) {
				int x = A[i + j], y = A[i + mid + j] * w % P;
				A[i + j] = (x + y) % P, A[i + mid + j] = (x - y + P) % P;
			}
		}
	}
	if(type == -1) {
		int ilim = qpow(lim, P - 2);
		for(int i = 0; i < lim; i++) A[i] = A[i] * ilim % P;
	}
}

signed main() {
	n = get(), m = get();
	init();
	for(int i = 0; i <= n; i++) f[n - i] = get() * fac[i] % P, g[i] = inv[i];
	int lim = 1, l = 0;
	while(lim <= n * 2) lim <<= 1, l++;
	for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	NTT(f, lim, 1), NTT(g, lim, 1);
	for(int i = 0; i < lim; i++) f[i] = f[i] * g[i] % P;
	NTT(f, lim, -1);
	for(int i = 0; i <= n; i++) f[n - i] = f[n - i] * qpow(qpow(i + 1, m), P - 2) % P;
	for(int i = n + 1; i < lim; i++) f[i] = 0;
	memset(g, 0, sizeof(g));
	for(int i = 0; i <= n; i++) g[i] = inv[i] * ((i & 1)? (P - 1) : 1) % P;
	NTT(f, lim, 1), NTT(g, lim, 1);
	for(int i = 0; i < lim; i++) f[i] = f[i] * g[i] % P;
	NTT(f, lim, -1);
	for(int i = 0; i <= n; i++) printf("%lld ", f[n - i] * inv[i] % P);
	return 0;
}