#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2002;
const LL MOD = 1e9 + 7;

int d, n;
int a[N], vis[N], flag[N];
vector<int> g[N];

LL dp[N];
LL dfs(int u, int p) {
	flag[u] = 1;
	dp[u] = 1;
	for (auto v: g[u]) {
		if (v == p) continue;
		if (vis[v] == 0) continue;
		dfs(v, u);
		dp[u] = dp[u] * (dp[v] + 1) % MOD;
	}
	return dp[u];
}

int cac(int l, int r) {
	for (int i = 1; i <= n; i ++) {
		flag[i] = 0; dp[i] = 0;
		if (a[i] <= r && a[i] >= l) vis[i] = 1; else vis[i] = 0;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[i] == 1 && flag[i] == 0) {
			dfs(i, i);
		}
	}
	for (int i = 1; i <= n; i ++) ans = (ans + dp[i]) % MOD;
	return ans;
}

int main() {
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	LL ans = 0;	
	for (int i = 1; i <= 2000; i ++) {
		ans += cac(i, i + d) - cac(i + 1, i + d);
		ans = (ans % MOD + MOD) % MOD;
	}
	cout << ans << endl;
}