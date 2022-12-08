#include <bits/stdc++.h>

using namespace std;

int l[100005];
int r[100005];
int vis[100005];
pair<long long, long long> dp[100005];
vector<int> mp[100005];

void dfs(int p) {
	if (vis[p])
		return;
	vis[p] = 1;
	long long ll = 0, rr = 0;
	for (int i : mp[p]) {
		if (!vis[i]) {
			dfs(i);
			ll += max(abs(l[p] - l[i]) + dp[i].first, abs(l[p] - r[i]) + dp[i].second);
			rr += max(abs(r[p] - l[i]) + dp[i].first, abs(r[p] - r[i]) + dp[i].second);
		}
	}
	dp[p] = make_pair(ll, rr);
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	memset(vis, 0, sizeof vis);
	dfs(1);
	printf("%lld\n", max(dp[1].first, dp[1].second));
	for (int i = 1; i <= n; ++i) {
		mp[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}