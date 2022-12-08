#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 998244353, sgn[] = { 1, P - 1 };
int n, m, fac[N], inv[N];

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

int C(int n, int m) { return n >= m? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

int S(int n, int m) {
	int res = 0;
	for(int i = 0; i <= m; i++) res = (res + sgn[i & 1] * C(m, i) % P * qpow(m - i, n)) % P;
	return res;
}

signed main() {
	n = get(), m = get();
	init(n);
	if(n <= m) { cout << 0; return 0; }
	int res = C(n, n - m) * S(n, n - m) % P;
	if(m) res = res * 2 % P;
	cout << res;
	return 0;
}