#include <bits/stdc++.h>
using namespace std;

#define N 2000010

int n, rt, k, u, v, cnt[N];
long long ans;

bool uni[N], vis[N];
vector <int> vec[N];

void dfs(int u) {
	vis[u] = 1;
	cnt[u] = uni[u];
	for (int i = 0, sz = vec[u].size(); i < sz; i ++) if (!vis[vec[u][i]]) {
		dfs(vec[u][i]);
		cnt[u] += cnt[vec[u][i]];
	}
	ans += min(cnt[u], 2 * k - cnt[u]);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 2 * k; i ++) {
		scanf("%d", &u);
		uni[u] = 1;
	}
	for (int i = 1; i < n; i ++) {
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	printf("%I64d\n", ans);
	return 0;
}