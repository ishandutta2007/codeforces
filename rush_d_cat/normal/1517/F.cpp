#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300 + 10;
const LL mod = 998244353;
int n; 
vector<int> G[N];
void upd(LL &x, LL y) {
	x += y;
	if (x >= mod) x %= mod;
}
LL f[N][N<<1];
int r, dep[N];
void dfs(int u, int p) {
	dep[u] = 1;
	f[u][N - 1] = f[u][N + 1] = 1;
	for (auto v: G[u]) if (v != p) {
		dfs(v, u);
		LL g[N<<1] = {0};
		for (int x = - dep[u]; x <= dep[u]; x ++) if (x != 0) {
			for (int y = - dep[v]; y <= dep[v]; y ++) if (y != 0) {
				// merge f[u][x+N], f[v][y+N]
				if (x < 0 && y < 0) upd(g[min(x, y - 1) + N], f[u][x+N] * f[v][y+N] % mod);
				if (x < 0 && y > 0) {
					int dis = abs(x) - 1 + abs(y);
					if (r >= dis) upd(g[y+1+N], f[u][x+N] * f[v][y+N] % mod);
					else upd(g[x+N], f[u][x+N] * f[v][y+N] % mod);
				}
				if (x > 0 && y < 0) {
					int dis = abs(x) - 1 + abs(y);
					if (r >= dis) upd(g[x+N], f[u][x+N] * f[v][y+N] % mod);
					else upd(g[y-1+N], f[u][x+N] * f[v][y+N] % mod);
				}
				if (x > 0 && y > 0) {
					upd(g[min(x, y+1) + N], f[u][x+N] * f[v][y+N] % mod);
				}
			}
		}
		dep[u] = max(dep[u], dep[v] + 1);
		for (int x = - dep[u]; x <= dep[u]; x ++) 
			f[u][x + N] = g[x + N];
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	LL ans = 0;
	for (int i = 1; i < n; i ++) {
		r = i;
		dfs(1, 1);
		LL sum = 0;
		for (int x = 1; x <= dep[1]; x ++)
			upd(sum, f[1][x + N]);
		//printf("i = %d, sum = %lld\n", i, sum);
		ans += sum;
	}
	vector<LL> pw(n + 1), ipw(n + 1);
	pw[0] = ipw[0] = 1;
	for (int i = 1; i <= n; i ++) {
		pw[i] = pw[i-1] * 2 % mod;
		ipw[i] = ipw[i-1] * ((mod+1)/2) % mod;
	}
	ans = ((pw[n] * n % mod - ans) % mod + mod) % mod * ipw[n] % mod;
	ans --;
	cout << ans << endl;
}