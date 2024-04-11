#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		int n, m, x, y;
		scanf("%d %d", &n, &m);
		vector<int> revlist[n];
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			revlist[y - 1].push_back(x - 1);
		}
		vector<int> ans;
		int dp[n];
		fill_n(dp, n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j: revlist[i]) dp[i] = max(dp[i], dp[j] + 1);
			if (dp[i] == 2) dp[i] = -1, ans.push_back(i + 1);
		}
		printf("%lu\n", ans.size());
		if (ans.size()) printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); ++i) printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}