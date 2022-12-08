#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 998244353, G = 3, iG = 332748118;
	
int qpow(int x, int y) {
	int res(1);
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

namespace Stirling {
	int n, k, a[N], b[N];
	int r[N];
	
	void NTT(int *A, int type, int lim) {
		for(int i = 0; i < lim; i++) if(i < r[i]) swap(A[i], A[r[i]]);
		for(int mid = 1; mid < lim; mid <<= 1) {
			int Wn = qpow(type == 1? G : iG, (P - 1) / (mid << 1));
			for(int i = 0; i < lim; i += mid << 1) {
				int w = 1;
				for(int j = 0; j < mid; j++, w = w * Wn % P) {
					int x = A[i + j], y = w * A[i + mid + j] % P;
					A[i + j] = (x + y) % P;
					A[i + mid + j] = (x - y + P) % P;
				}
			}
		}
		if(type == -1) {
			int inv = qpow(lim, P - 2);
			for(int i = 0; i < lim; i++) A[i] = A[i] * inv % P;
		}
	}
	
	int tmp[N];
	void GetInv(int deg, int *F, int *G) {
		if(deg == 1) { G[0] = qpow(F[0], P - 2); return; }
		GetInv((deg + 1) >> 1, F, G);
		int l = 0, lim = 1;
		while(lim < deg + deg) lim <<= 1, l++;
		for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		for(int i = 0; i < deg; i++) tmp[i] = F[i];
		for(int i = deg; i < lim; i++) tmp[i] = 0;
		NTT(tmp, 1, lim), NTT(G, 1, lim);
		for(int i = 0; i < lim; i++) G[i] = (G[i] * 2 % P - G[i] * G[i] % P * tmp[i] % P + P) % P;
		NTT(G, -1, lim);
		for(int i = deg; i < lim; i++) G[i] = 0;
	}
	
	void GetD(int deg, int *F, int *G) {
		for(int i = 1; i < deg; i++) G[i - 1] = F[i] * i % P;
		G[deg] = 0;
	}
	
	void GetI(int deg, int *F, int *G) {
		for(int i = 1; i < deg; i++) G[i] = F[i - 1] * qpow(i, P - 2) % P;
		G[0] = 0;
	}
	
	int f[N];
	void Getln(int deg, int *A, int *G) {
		for(int i = 0; i < deg * 3; i++) G[i] = 0;
		GetInv(deg, A, f), GetD(deg, A, G);
		int lim = 1, l = 0;
		while(lim <= deg * 2) lim <<= 1, l++;
		for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		NTT(f, 1, lim), NTT(G, 1, lim);
		for(int i = 0; i < lim; i++) f[i] = f[i] * G[i] % P;
		NTT(f, -1, lim);
		GetI(lim, f, G);
		for(int i = deg; i < lim; i++) G[i] = 0;
		for(int i = 0; i < lim; i++) f[i] = 0;
	}
	
	int g[N];
	void GetExp(int deg, int *A, int *B) {
		if(deg == 1) return void(B[0] = 1);
		GetExp((deg + 1) >> 1, A, B), Getln(deg, B, g);
		for(int i = 0; i < deg; i++) g[i] = (P - g[i] + A[i]) % P;
		g[0]++;
		int lim = 1, l = 0;
		while(lim <= deg * 2) lim <<= 1, l++;
		for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		NTT(B, 1, lim), NTT(g, 1, lim);
		for(int i = 0; i < lim; i++) B[i] = B[i] * g[i] % P;
		NTT(B, -1, lim);
		for(int i = deg; i < lim; i++) B[i] = 0;
		for(int i = 0; i < lim; i++) g[i] = 0;
	}
	
	int fac[N];
	
	void initRol(int x, int y) {
		n = x + 1, k = y;
		for(int i = 0; i < n; i++) a[i] = qpow(i + 1, P - 2);
		Getln(n, a, b);
		for(int i = 0; i < n; i++) b[i] = b[i] * k % P;
		for(int i = 0; i < N; i++) a[i] = 0;
		GetExp(n, b, a);
		for(int i = n; i >= k; i--) a[i] = a[i - k];
		for(int i = 0; i < k; i++) a[i] = 0;
		fac[0] = 1; for(int i = 1; i <= max(n, k); i++) fac[i] = fac[i - 1] * i % P;
	}
	
	int GetCur(int x) {
		int inv = qpow(fac[k], P - 2);
		return a[x] * fac[x] % P * inv % P;
	}
}

int n, A, B;

signed main() {
	n = get(), A = get(), B = get();
	if(!A || !B) return 0 * printf("0\n");
	Stirling::initRol(n + 10, A + B - 2);
	int c = Stirling::GetCur(n - 1);
	for(int i = A + B - 2, j = 1; j <= A - 1; i--, j++) 
		c = c * i % P;
	for(int i = 1; i <= A - 1; i++) c = c * qpow(i, P - 2) % P;
	printf("%lld\n", c);
}