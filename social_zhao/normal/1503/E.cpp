#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2030, P = 998244353;
int fac[N * 2], inv[N * 2], n, m;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P,  y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int n, int m) { return n >= m? fac[n] * inv[m] % P * inv[n - m] % P : 0; }
int Walk(int n, int m) { return C(n + m, n); }
int GetS(int x, int y) { return Walk(x - 1, y - 1) * Walk(x, m - y) % P; }

main() {
	init(4042);
	n = get(), m = get();
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for(int i = 1; i < n; i++) {
		int now = 0;
		for(int j = 2; j <= m; j++) {
			ans1 = (ans1 + now * GetS(i, j)) % P;
			ans3 = (ans3 + GetS(n - i, m - (j - 1) + 1) * GetS(i, j)) % P;
			if(j > 1) now = (now + GetS(n - i, m - (j - 1) + 1)) % P;
		}
	}
	swap(n, m);
	for(int i = 1; i < n; i++) {
		int now = 0;
		for(int j = 1; j <= m; j++) {
			ans2 = (ans2 + now * GetS(i, j)) % P;
			if(j > 1) now = (now + GetS(n - i, m - (j - 1) + 1)) % P;
		}
	}
	int ans = (ans1 * 2 + ans2 * 2 + ans3 * 2) % P;
	printf("%lld\n", ans);
	return 0;
}