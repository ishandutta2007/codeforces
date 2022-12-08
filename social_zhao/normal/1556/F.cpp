#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 15, P = 1e9 + 7;
int n, a[N], g[N][1 << N], f[1 << N], cnt[1 << N], all;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

int G(int a, int b) {
	int res = 1;
	for(int i = 1; i <= n; i++)
		if(a >> (i - 1) & 1) res = res * g[i][b] % P;
	return res;
}

signed main() {
	n = get(), all = (1 << n) - 1;
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i < 1 << n; i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for(int s = 0; s < 1 << n; s++)
		for(int i = 1; i <= n; i++) {
			g[i][s] = 1;
			for(int j = 1; j <= n; j++)
				if(!(s >> (i - 1) & 1) && (s >> (j - 1) & 1)) 
					g[i][s] = g[i][s] * a[i] % P * qpow(a[i] + a[j], P - 2) % P;
		}
	int ans = 0;
	for(int i = 1; i < 1 << n; i++) {
		int res = 0;
		for(int j = (i - 1) & i; j; j = (j - 1) & i) 
			res = (res + f[j] * qpow(G(j, all ^ i), P - 2)) % P;
		f[i] = (1 - res) * G(i, all ^ i) % P;
		ans = (ans + f[i] * cnt[i]) % P;
	}
	printf("%lld\n", (ans + P) % P);
	return 0;
}