#include <bits/stdc++.h>
using namespace std;

vector <int> from[200010];
vector <int> all[200010];
vector <int> val;
int dep[200010], id[200010], a[200010];
long long dp[200010];
int N;
long long pre[200010], suc[200010];

void dfs(int x) {
	all[dep[x]].push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		dep[v] = dep[x] + 1, dfs(v);
	}
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			from[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int x; scanf("%d", &x);
			from[x].push_back(i);
		}
		for (int i = 2; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i <= n; i++) {
			all[i].clear();
		}
		dep[1] = 0, dfs(1);
		for (int i = n; i >= 0; i--) {
			if (!all[i].size()) continue;
			val.clear();
			for (auto x : all[i]) val.push_back(a[x]);
			sort(val.begin(), val.end()), val.resize(unique(val.begin(), val.end()) - val.begin());
			for (auto x : all[i]) id[x] = lower_bound(val.begin(), val.end(), a[x]) - val.begin() + 1;
			N = val.size();
			for (int i = 1; i <= N; i++) {
				pre[i] = suc[i] = -0x3f3f3f3f3f3f3f3f;
			}
			for (auto x : all[i]) {
				long long maxj = 0;
				for (int j = 0; j < from[x].size(); j++) {
					int v = from[x][j];
					maxj = max(maxj, dp[v]);
				}
				dp[x] = maxj + max(val.back() - a[x], a[x] - val[0]);
				pre[id[x]] = max(pre[id[x]], maxj - a[x]);
				suc[id[x]] = max(suc[id[x]], maxj + a[x]);
			}
			for (int i = 2; i <= N; i++) {
				pre[i] = max(pre[i], pre[i - 1]);
			}
			for (int i = N - 1; i >= 1; i--) {
				suc[i] = max(suc[i], suc[i + 1]);
			}
			for (auto x : all[i]) {
				dp[x] = max(dp[x], max(pre[id[x]] + a[x], suc[id[x]] - a[x]));
			}
		}
		printf("%I64d\n", dp[1]);
	}
	return 0;
}