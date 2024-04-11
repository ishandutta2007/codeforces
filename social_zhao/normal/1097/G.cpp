#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, K = 205, P = 1e9 + 7;
int n, k, S[K << 1][K << 1], fac[K << 1], inv[K << 1];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int f[N][K][2], sze[N], tmp[K][2], ans;

// 0: 
// 1:  

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
int C(int n, int m) { return n >= m? 1ll * fac[n] * inv[m] % P * inv[n - m] % P : 0; }
void inc(int &x, int y) { x = (x + y) % P; }

int qpow(int x, int y) {
	int res = 1;
	while(y) res = 1ll * res * ((y & 1)? x : 1) % P, x = 1ll * x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	S[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % P;
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % P;
}

void dfs(int u, int lst) {
	f[u][0][1] = sze[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u);
		for(int a = 0; a <= sze[u] && a <= k; a++)
			for(int b = 0; b <= sze[v] && a + b <= k; b++) {
				if(a == 0) inc(tmp[b][0], (f[v][b][0] + f[v][b][1]) % P);
				if(a == 0) inc(tmp[b + 1][0], 1ll * (f[v][b][0] + f[v][b][1]) * (b + 1) % P);
				for(int p = 0; p < 2; p++)
					for(int q = 0; q < 2; q++) {
						inc(tmp[a + b][1], 1ll * f[u][a][p] * f[v][b][q] % P * C(a + b, a) % P);
						inc(tmp[a + b + 1][1], 1ll * f[u][a][p] * f[v][b][q] % P * C(a + b, a) % P * (a + b + 1) % P);
					}
			}
		sze[u] += sze[v];
		for(int a = 0; a <= sze[u] && a <= k; a++) 
			inc(f[u][a][0], tmp[a][0]), inc(f[u][a][1], tmp[a][1]), tmp[a][0] = tmp[a][1] = 0;
	}
	for(int i = 0; i <= k; i++) 
		inc(ans, 1ll * S[k][i] * f[u][i][1] % P);
}

main() {
	n = get(), k = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	init(k << 1);
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}