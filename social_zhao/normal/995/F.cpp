#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3005, P = 1e9 + 7;
int n, d;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int f[N][N], s[N][N], x[N], y[N];
int iv[1000005];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

int inv(int i) { i = (i % P + P) % P; if(i <= 1000000) return iv[i]; return -(P / i) * inv(P % i) % P; }

void dfs(int u) {
	for(int i = 1; i <= n + 1; i++) f[u][i] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		dfs(v);
		for(int i = 1; i <= n + 1; i++) f[u][i] = f[u][i] * s[v][i] % P;
	}
	for(int i = 1; i <= n + 1; i++) s[u][i] = (s[u][i - 1] + f[u][i]) % P;
}

int Lagrange(int n, int d) {
//	for(int i = 1; i <= n; i++) printf("%lld %lld\n", x[i], y[i]);
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int now = 1;
		for(int j = 1; j <= n; j++) {
			if(j == i) continue;
			now = now * (d - x[j]) % P * inv(x[i] - x[j]) % P;
		}
		res = (res + y[i] * now) % P;
	}
	return (res + P) % P;
}

void init(int n) {
	iv[0] = iv[1] = 1;
	for(int i = 2; i <= n; i++) iv[i] = -(P / i) * iv[P % i] % P;
//	for(int i = 1; i <= 10; i++) printf("%lld ", iv[i]);
}

signed main() {
	init(1000000);
	n = get(), d = get();
	for(int i = 2, f; i <= n; i++) f = get(), add(f, i);
	dfs(1);
	for(int i = 1; i <= n + 1; i++) x[i] = i, y[i] = s[1][i];
	int ans = Lagrange(n + 1, d);
	printf("%lld\n", ans);
	return 0;
}