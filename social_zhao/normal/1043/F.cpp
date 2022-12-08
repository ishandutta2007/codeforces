#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, P = 998244353;
int fac[N], inv[N], n, a[N], cnt[N], vis[N], mx, f[N];

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

int calc(int k) {
	for(int i = mx; i >= 1; i--) {
		f[i] = C(cnt[i], k);
		for(int j = i + i; j <= mx; j += i) f[i] = (f[i] - f[j]) % P;
	}
	return f[1];
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), vis[a[i]]++, mx = max(mx, a[i]);
	init(n);
	for(int i = 1; i <= mx; i++)
		for(int j = i; j <= mx; j += i)
			cnt[i] += vis[j];
	for(int t = 1; t <= 7; t++) {
		if(calc(t)) { cout << t << endl; return 0; } 
	}
	cout << -1;
	return 0;
}