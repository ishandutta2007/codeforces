#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector <int> from[5010];
vector <int> dp[5010];
int tmp[5010], sz[5010];
int n, k;

void dfs(int x, int last) {
	sz[x] = 1;
	int maxd = 0; dp[x].push_back(1);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dfs(v, x), sz[x] += sz[v];
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		int sum = 0;
		for (int i = 0; i < dp[v].size(); i++) {
			sum = (sum + dp[v][i]) % mod;
		}
		int d = dp[v].size() - 1; d++, dp[v].insert(dp[v].begin(), sum);
		if (dp[v].size() > k + 1) dp[v].resize(k + 1), d = k;
		for (int i = 0; i <= max(maxd, d); i++) tmp[i] = 0;
		for (int j = 0; j <= maxd; j++) {
			for (int t = 0; t <= d; t++) {
				if (j + t > k) break;
				tmp[max(j, t)] = (tmp[max(j, t)] + 1ll * dp[x][j] * dp[v][t]) % mod;
			}
		}
		maxd = max(maxd, d);
		dp[x].resize(maxd + 1);
		for (int j = 0; j <= maxd; j++) {
			dp[x][j] = tmp[j];
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1);
	long long ans = 0;
	for (int i = 0; i < dp[1].size(); i++) {
		ans = (ans + dp[1][i]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}