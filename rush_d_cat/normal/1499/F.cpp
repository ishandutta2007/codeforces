#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N = 5000 + 10;

int n, k;
vector<int> g[N];

int f[N][N], down[N];
void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}
void dfs(int u, int p) {
	f[u][1] = 1; down[u] = 1;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		int tmp[N] = {0};
		for (int x = 1; x <= down[u]; x ++) {
			if (x - 1 > k) continue;
			for (int y = 1; y <= down[v]; y ++) {
				add(tmp[x], 1LL * f[u][x] * f[v][y] % MOD);
				if (x + y - 1 <= k) {
					add(tmp[max(x, y + 1)], 1LL * f[u][x] * f[v][y] % MOD);
				}	
			}
		}
		down[u] = max(down[u], down[v] + 1);
		for (int i = 1; i <= down[u]; i ++)
			f[u][i] = tmp[i];
	}
	/*
	printf("down[%d] = %d\n", u, down[u]);
	for (int i = 1; i <= down[u]; u ++) {
		printf("f[%d][%d] = %d\n", u,i,f[u][i]);
	}
	*/
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 1; i < n; i ++) {
		int u, v; 
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}	

	dfs(1, 1);
	int ans = 0;
	for (int i = 1; i <= k + 1; i ++) 
		add(ans, f[1][i]);
	cout << ans << endl;
}