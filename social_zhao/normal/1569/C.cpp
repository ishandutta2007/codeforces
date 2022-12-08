#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 998244353;
int n, fac[N], inv[N], a[N];

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

void solve() {
	n = get();
	int mx = 0, cfir = 0, csec = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++) cfir += a[i] == mx;
	if(cfir > 1) return printf("%lld\n", fac[n]), void();
	for(int i = 1; i <= n; i++) csec += a[i] == mx - 1;
	if(!csec) return printf("0\n"), void();
	int ans = fac[csec] * C(n, csec + 1) % P * csec % P * fac[n - csec - 1] % P;
	printf("%lld\n", ans);
}

signed main() {
	int T = get();
	init(2e5);
	while(T--) solve();
	return 0;
}