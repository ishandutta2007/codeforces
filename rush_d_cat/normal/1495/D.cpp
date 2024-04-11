
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400 + 10;
const int INF = 1e8;
const LL MOD = 998244353;
 
int n, m;
int f[N][N];
 
vector<int> g[N];
vector< pair<int,int> > edges;
 
int deg[N];
int par[N];
int find(int x) {
	return par[x]==x?x:par[x]=find(par[x]);
}
LL res[N][N];
void solve(int u, int v) {
	for (int i = 1; i <= n; i ++) deg[i] = 0, par[i] = i;
 
	int cpath = 0;
	for (auto e: edges) {
		int x = e.first, y = e.second;
		if (f[u][x] == f[u][y]) continue;
		if (f[v][x] == f[v][y]) continue;
		if (f[u][x] > f[u][y]) swap(x, y); 
		if (f[u][x] + 1 == f[u][y] && f[v][x] + 1 == f[v][y]) {
			par[find(x)] = find(y);
			deg[y] ++;
		}
 
		if (f[u][x] + 1 == f[u][y] && f[v][x] == f[v][y] + 1 && f[u][x] + 1 + f[v][y] == f[u][v]) {
			cpath ++;
			par[find(x)] = find(y);
		}
	}	
	if (cpath != f[u][v]) return;
 
	for (int i = 1; i <= n; i ++) {
		if (find(i) != find(1)) return;
	}
	LL ans = 1;
	for (int i = 1; i <= n; i ++)
		if (f[u][i] + f[v][i] > f[u][v])
		ans = ans * deg[i] % MOD;
	res[u][v] = res[v][u] = ans;
} 
 
int main() {
	for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++)
		f[i][j] = (i==j?0:INF);
 
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v;
		f[u][v] = f[v][u] = 1; 
		edges.push_back(make_pair(u, v));
	}
 
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
 
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			solve(i, j);
		}
	}
 
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			printf("%lld%c", res[i][j], " \n"[j==n]);
		}
	}
}