#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5, M = 18, P = 1e9 + 7;
int n, mx, lim, s[N], f[M][1 << M], fib[N], cnt[N];
int a[N], b[N], c[N], tmp[N], ans[N];

void init() {
	fib[0] = 0, fib[1] = 1;
	for(int i = 2; i < 1 << 17; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
	for(int i = 1; i < 1 << 17; i++) cnt[i] = cnt[i >> 1] + (i & 1);
}

void AND(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++)
				(A[i + j] += type * A[i + mid + j] + P) %= P;
}

void OR(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++)
				(A[i + mid + j] += type * A[i + j] + P) %= P;
}

void XOR(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++) {
				int x = A[i + j], y = A[i + mid + j];
				A[i + j] = (x + y) * type % P, A[i + mid + j] = (x - y + P) * type % P;
			}
}

signed main() {
	n = get();
	init();
	for(int i = 1; i <= n; i++) {
		int s = get(); mx = max(mx, s);
		f[cnt[s]][s]++, b[s]++, c[s]++;
	}
	lim = 1; int l = 0;
	while(lim <= mx) lim <<= 1, l++;
	for(int i = 0; i <= l; i++) OR(f[i], 1);
	for(int i = 0; i <= l; i++) {
		for(int j = 0; j < lim; j++) tmp[j] = 0;
		for(int j = 0; j <= i; j++)
			for(int k = 0; k < lim; k++)
				tmp[k] = (tmp[k] + f[j][k] * f[i - j][k] % P) % P;
		OR(tmp, -1);
		for(int j = 0; j < lim; j++) if(cnt[j] == i) a[j] = (a[j] + tmp[j]) % P;
	}
	XOR(c, 1);
	for(int i = 0; i < lim; i++) c[i] = c[i] * c[i] % P;
	XOR(c, 500000004);
	for(int i = 0; i < lim; i++) a[i] = a[i] * fib[i] % P, b[i] = b[i] * fib[i] % P, c[i] = c[i] * fib[i] % P; 
	AND(a, 1), AND(b, 1), AND(c, 1);
	for(int i = 0; i < lim; i++) ans[i] = a[i] * b[i] % P * c[i] % P;
	AND(ans, -1);
	int res = 0;
	for(int i = 1; i < lim; i <<= 1) res = (res + ans[i]) % P;
	printf("%lld\n", res);
	return 0;
}