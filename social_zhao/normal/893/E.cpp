#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5, P = 1e9 + 7;
int x, y, fac[N], inv[N];

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

int C(int n, int m) { return n > m? fac[n] * inv[m] % P * inv[n - m] % P : 0; }
int put(int n, int m) { return C(n + m - 1, m - 1); }

void solve() {
	x = get(), y = get();
	int res = qpow(2, y - 1); 
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			int cnt = 0;
			while(x % i == 0) cnt++, x /= i;
			res = res * put(cnt, y) % P;
		}
	}
	if(x > 1) res = res * put(1, y) % P;
	printf("%lld\n", res);
}

signed main() {
	init(2e6);
	int T = get();
	while(T--) solve();
	return 0;
}