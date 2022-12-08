#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1000005, P = 1e9 + 7, inv2 = (P + 1) / 2;
int fac[N], inv[N];
int n, m, k;

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

int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }
void inc(int &x, int y) { x = (x + y) % P; }

void solve() {
	n = get(), m = get(), k = get();
	int ans = 0;
	if(n == m) return cout << n * k % P << endl, void();
	for(int i = 1; i <= m; i++) 
		inc(ans, C(n - i - 1, m - i) * qpow(inv2, n - i) % P * i % P);
	cout << ans * k % P << endl;
}

main() {
	init(1000000);
	int T = get();
	while(T--) solve();
	return 0;
}