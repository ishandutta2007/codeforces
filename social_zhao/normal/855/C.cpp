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
int n, m, k, x;
int f[N][11][3], g[11][3];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot = 0;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int fa) {
	f[u][0][0] = k - 1, f[u][1][1] = 1, f[u][0][2] = m - k;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u);
		for(int a = 0; a <= x; a++)
			for(int b = 0; a + b <= x; b++) {
				g[a + b][0] = (g[a + b][0] + f[u][a][0] * (f[v][b][0] + f[v][b][1] + f[v][b][2]) % P) % P;
				g[a + b][1] = (g[a + b][1] + f[u][a][1] * f[v][b][0] % P) % P;
				g[a + b][2] = (g[a + b][2] + f[u][a][2] * (f[v][b][0] + f[v][b][2]) % P) % P; 
			}
		for(int j = 0; j <= x; j++) f[u][j][0] = g[j][0], f[u][j][1] = g[j][1], f[u][j][2] = g[j][2], g[j][0] = g[j][1] = g[j][2] = 0;
	}
}

signed main() {
	n = get(), m = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	k = get(), x = get(); 
	dfs(1, 0);
	int ans = 0;
	for(int i = 0; i <= x; i++)
		for(int j = 0; j <= 2; j++)
			ans = (ans + f[1][i][j]) % P;
	printf("%lld\n", ans);
	return 0;
}