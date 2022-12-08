#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1505, K = 1e5 + 5, P = 1e9 + 7;
int n, m, a, b, p, k;
int Pr[N], L[N][N], R[N][N], S[N][N], fac[K], inv[K], sPL[N][N], sP[N];

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

main() {
	init(100000);
	n = get(), m = get(), a = get(), b = get(), p = a * qpow(b, P - 2) % P, k = get();
	for(int i = 0; i <= m; i++) if(i <= k) Pr[i] = C(k, i) * qpow(p, i) % P * qpow(P + 1 - p, k - i) % P;
	sP[0] = Pr[0];
	for(int i = 1; i <= m; i++) sP[i] = (sP[i - 1] + Pr[i]) % P;
	S[0][m] = L[0][m] = R[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		for(int r = 1; r <= m; r++) {
			S[i][r] = Pr[m - r] * ((L[i - 1][m] - R[i - 1][r + 1] + P) % P * sP[r - 1] % P - sPL[i - 1][r - 1] + P) % P;
			L[i][r] = (L[i][r - 1] + S[i][r]) % P;
			R[i][m - r + 1] = L[i][r];
			sPL[i][r] = (sPL[i][r - 1] + Pr[r] * L[i][r]) % P;
		}
	}
	printf("%lld\n", L[n][m]);
	return 0;
}