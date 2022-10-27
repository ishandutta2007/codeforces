#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000 + 10;
int n, flag[N], sz[N], vis[N], in[N], nex[N];
vector<int> g[N];
void dfs(int u, int p) {
	sz[u] = 1; vis[u] = 1;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[v].push_back(u); flag[u] = 1; in[v] ++;
		nex[u] = v;
	}
	LL ans = 1;
	for (int i = 1; i <= 2 * n; i ++) {
		if (flag[i] == 0) {
			dfs(i, i);
			ans = ans * sz[i] % MOD;
		}	
	}
	for (int i = 1; i <= 2 * n; i ++) {
		if (flag[i] && in[i] == 0 && vis[i] == 0) {
			int u = i, m = 2; 
			while (vis[u] == 0) {
				vis[u] = i;
				if (u == nex[u]) {
					m = 1;
					break;
				}
				u = nex[u]; 
			}
			if (vis[u] != i) m = 1; 
			ans = ans * m % MOD;
		}
	}
	for (int i = 1; i <= 2 * n; i ++) {
		if (flag[i] && vis[i] == 0) {
			int u = i;
			if (nex[u] == u) {
				vis[u] = 1;
				continue;
			}
			while (vis[u] == 0) {
				vis[u] = 1;  u = nex[u];
			}
			ans = ans * 2 % MOD;
		}
	}
	cout << ans << endl;
}