#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 150005, S = N * 30, P = 998244353, H = 29;
int n, x, ch[S][2], tot = 1, sze[S], a[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void insert(int x) {
	int u = 1; ++sze[1];
	for(int i = H; i >= 0; i--) {
		int c = x >> i & 1;
		if(!ch[u][c]) ch[u][c] = ++tot;
		u = ch[u][c], ++sze[u];
	}
}

int solve(int u, int v, int dep) {
	if(!u || !v) return qpow(2, sze[u] + sze[v]);
	if(dep == -1) return qpow(2, sze[u] + (u != v) * sze[v]);
	if(u == v) {
		if(x >> dep & 1) return solve(ch[u][0], ch[u][1], dep - 1) % P;
		else return (solve(ch[u][0], ch[u][0], dep - 1) + solve(ch[u][1], ch[v][1], dep - 1) - 1) % P;
	}
	else {
		if(x >> dep & 1) return solve(ch[u][0], ch[v][1], dep - 1) * solve(ch[u][1], ch[v][0], dep - 1) % P;
		else {
			int res = (solve(ch[u][0], ch[v][0], dep - 1) + solve(ch[u][1], ch[v][1], dep - 1) - 1) % P;
			res = (res + (qpow(2, sze[ch[u][0]]) - 1) * (qpow(2, sze[ch[u][1]]) - 1)) % P;
			res = (res + (qpow(2, sze[ch[v][0]]) - 1) * (qpow(2, sze[ch[v][1]]) - 1)) % P;
			return res;
		}
	}
}

signed main() {
	n = get(), x = get();
	for(int i = 1; i <= n; i++) a[i] = get(), insert(a[i]);
	int ans = solve(1, 1, H);
	ans = (ans % P + P) % P;
	printf("%lld\n", (ans - 1 + P) % P);
	return 0;
}

// gvdl dde