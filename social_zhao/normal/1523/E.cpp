#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, P = 1e9 + 7;
int n, k, fac[N], inv[N];

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
	n = get(), k = get();
	int ans = 0; 
	for(int i = 1; i <= n; i++) //  i  
		ans = (ans + C(n - (k - 1) * (i - 1), i) * fac[i] % P * qpow(C(n, i) * fac[i] % P, P - 2) % P) % P;
	printf("%lld\n", (ans + 1) % P);
}

signed main() {
	init(100000);
	int T = get();
	while(T--) solve();
	return 0;
}