#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n + 1], ans[n + 1];
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		vector<int> occ[n + 1];
		for (int i = 1; i <= n; ++i) occ[i].push_back(0);
		for (int i = 1; i <= n; ++i) occ[a[i]].push_back(i);
		for (int i = 1; i <= n; ++i) occ[i].push_back(n + 1);
		fill_n(ans, n + 1, n + 1);
		for (int i = n; i > 0; --i) {
			int span = 0;
			for (int j = 1; j < occ[i].size(); ++j) span = max(span, occ[i][j] - occ[i][j - 1]);
			ans[span] = i;
		}
		for (int i = 1; i <= n; ++i) ans[i] = min(ans[i], ans[i - 1]);
		for (int i = 1; i < n; ++i) {
			if (ans[i] == n + 1) printf("-1 ");
			else printf("%d ", ans[i]);
		}
		printf("%d\n", ans[n]);
	}
	return 0;
}