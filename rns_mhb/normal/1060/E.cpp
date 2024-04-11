#include<bits/stdc++.h>
using namespace std;

#define N 200020
int n;
vector<int> g[N];
typedef long long ll;

int sz[N][2];
ll sum[N][2];
ll ans;
int pa[N];

void dfs(int u, int p) {
	sz[u][0] = 1;
	pa[u] = p;
	for (auto v:g[u]) {
		if (v == p) continue;
		dfs(v, u);
		ans += (sum[v][0] + sz[v][0]) * sz[u][1] + sum[u][1] * sz[v][0];
		ans += (sum[v][1] + sz[v][1]) * (sz[u][0] - 1) + sum[u][0] * sz[v][1];
		ans += (sum[v][0] + sz[v][0]) * (sz[u][0] - 1) + sum[u][0] * sz[v][0] + 1ll * sz[v][0] * (sz[u][0] - 1);
		ans += (sum[v][1] + sz[v][1]) * sz[u][1] + sum[u][1] * sz[v][1] + 1ll * sz[v][1] * sz[u][1];
		sz[u][0] += sz[v][1];
		sz[u][1] += sz[v][0];
		sum[u][0] += sum[v][1] + sz[v][1];
		sum[u][1] += sum[v][0] + sz[v][0];
	}
	ans += sum[u][0];
	ans += sum[u][1] + sz[u][1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout<<ans / 2<<endl;
	return 0;
}