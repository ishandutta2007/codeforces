#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rdi() read<int>()
#define rdl() read<ll>()

template<typename t> t read() {
	t x = 0; int f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int MOD = 1e9 + 7, maxn = 1e3 + 10;;

int n, k;  
int head[maxn], cnt;  
long long dp[maxn][maxn], f[maxn], ans;  

struct edge {
	int nxt, to;
}e[maxn << 1];

void insert(int u, int v) {
	e[++ cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int fa) {
	dp[u][0] = dp[u][k + 1] = 1;
	for (int E = head[u]; E; E = e[E].nxt) {
		int v = e[E].to;
		if (v == fa) continue;
		dfs(v, u);
		memset(f, 0, sizeof f);
		for (int i = 0; i <= 2 * k + 1; i ++) {
			for (int j = 0; j <= 2 * k; j ++) {
				if (i + j <= 2 * k) (f[min(i, j + 1)] += 1ll * dp[u][i] * dp[v][j] % MOD) %= MOD;
				else (f[max(i, j + 1)] += 1ll * dp[u][i] * dp[v][j] % MOD) %= MOD;
			}
		}
		memcpy(dp[u], f, sizeof f); 
	}	
}

int main() {
	n = rdi(), k = rdi();
	for (int i = 1; i < n; i ++) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	}
	dfs(1, 0); 
	for (int i = 0; i <= k; i ++) ans += dp[1][i], ans %= MOD;
	write(ans);
	return 0;
}