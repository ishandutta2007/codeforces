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
int n, m, d;
int a[N], b[N], r[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void NTT(int *A, int lim, int type) {
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

int tmp[N];
void GetInv(int deg, int *F, int *G) {
	if(deg == 1) { G[0] = qpow(F[0], P - 2); return; }
	GetInv((deg + 1) >> 1, F, G);
	int lim = 1, l = 0;
	while(lim < 2 * deg) lim <<= 1, l++;
	for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for(int i = 0; i < deg; i++) tmp[i] = F[i];
	for(int i = deg; i < lim; i++) tmp[i] = 0;
	NTT(tmp, lim, 1), NTT(G, lim, 1);
	for(int i = 0; i < lim; i++) G[i] = (G[i] * 2 % P - G[i] * G[i] % P * tmp[i] % P + P) % P;
	NTT(G, lim, -1);
	for(int i = deg; i < lim; i++) G[i] = 0;
}

int f[N], g[N];
void GetSqrt(int deg, int *F, int *G) {
	if(deg == 1) { G[0] = 1; return; }
	GetSqrt((deg + 1) >> 1, F, G);
	for(int i = 0; i <= deg << 1; i++) f[i] = 0;
	GetInv(deg, G, f);
	int lim = 1, l = 0;
	while(lim < deg * 2) lim <<= 1, l++;
	for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for(int i = 0; i < deg; i++) g[i] = F[i];
	for(int i = deg; i < lim; i++) g[i] = 0;
	NTT(f, lim, 1), NTT(g, lim, 1), NTT(G, lim, 1);
	for(int i = 0; i < lim; i++) G[i] = ((g[i] + G[i] * G[i] % P) * 499122177 % P * f[i] % P) % P;
	NTT(G, lim, -1);
	for(int i = deg; i < lim; i++) G[i] = 0;
}

signed main() {
	m = get(), n = get(), d = n + 1;
	for(int i = 1, x; i <= m; i++) x = get(), a[x] = -4, d = max(d, x + 1);
	a[0] = 1;
	GetSqrt(d, a, b);
	b[0] = (b[0] + 1) % P;
	memset(a, 0, sizeof(a));
	GetInv(d, b, a);
	for(int i = 1; i <= n; i++) printf("%lld\n", a[i] * 2 % P);
	return 0;
}