#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define K 40

typedef long long ll;

int n, ans, dp[N];
const int mod = 1e9 + 7;
ll x[N];
typedef pair <ll, int> pli;
vector <pli> v[N];
vector <int> adj[N];

void dfs(int u, int pa = 0) {
	int sz = v[pa].size(); dp[u] = dp[pa] + 1;
	v[u].push_back(pli(x[u], u));
	for (int i = 0, j = 0; i < sz; i = j) {
		while (j < sz && __gcd(x[u], v[pa][j].first) == v[u].back().first) j ++;
		if (j < sz) v[u].push_back(pli(__gcd(x[u], v[pa][j].first), v[pa][j].second));
	}
	sz = v[u].size();
	for (int i = 0; i < sz; i ++) {
		int d = (i < sz - 1) ? dp[v[u][i+1].second] : 0;
		ans = (ans + v[u][i].first % mod * (dp[v[u][i].second] - d)) % mod;
	}
	for (auto v : adj[u]) if (v != pa) dfs(v, u);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &x[i]);
	for (int i = 1, u, v; i < n; i ++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	printf("%d\n", ans);

	return 0;
}