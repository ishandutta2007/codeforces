#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5, P = 998244353, inv2 = (P + 1) / 2;
int n, lim, x, y, z, a[N], b[N], c[N], mul, offset;
int cnta[N], cntb[N], cntc[N], cntd[N], p[N], q[N], r[N], ans[N];
int tmp[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void FWT(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++) {
				int x = A[i + j], y = A[i + mid + j];
				A[i + j] = (x + y) * type % P, A[i + mid + j] = (x - y + P) * type % P;
			}
}

main() {
	n = get(), lim = 1 << get();
	x = get(), y = get(), z = get();
	mul = qpow(z, n);
	x = x * qpow(z, P - 2) % P, y = y * qpow(z, P - 2) % P;
	for(int i = 1; i <= n; i++) {
		a[i] = get(), b[i] = get(), c[i] = get();
		offset ^= c[i], a[i] ^= c[i], b[i] ^= c[i];
	}
	
	for(int i = 1; i <= n; i++) p[a[i]]++;
	FWT(p, 1);
	for(int i = 1; i <= n; i++) q[b[i]]++;
	FWT(q, 1);
	for(int i = 1; i <= n; i++) r[a[i] ^ b[i]]++;
	FWT(r, 1);
	for(int i = 0; i < lim; i++) {
		p[i] = (n + p[i]) * inv2 % P;
		q[i] = (n + q[i]) * inv2 % P;
		r[i] = (n + r[i]) * inv2 % P;
	}
	
	for(int i = 0; i < lim; i++) {
		cntb[i] = (n + r[i] - p[i] - q[i] + P + P) * inv2 % P;
		cntc[i] = (n + p[i] - q[i] - r[i] + P + P) * inv2 % P;
		cntd[i] = (n + q[i] - p[i] - r[i] + P + P) * inv2 % P;
		cnta[i] = (n - cntb[i] - cntc[i] - cntd[i] + P + P + P) % P;
		ans[i] = qpow(1 + x + y, cnta[i]) * qpow(1 - x - y, cntb[i]) % P * qpow(1 + x - y, cntc[i]) % P * qpow(1 - x + y, cntd[i]) % P;
		ans[i] = (ans[i] + P) % P;
	}
	
	FWT(ans, inv2);
	for(int i = 0; i < lim; i++) {
		int res = ans[i ^ offset] * mul % P;
		cout << res << " ";
	}
	return 0;
}