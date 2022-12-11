#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	if (n > k * (k - 1)) {
		printf("NO\n");
		return 0;
	}
	vector<pair<int, int>> ans;
	for (int bg = 2; bg <= k && ans.size() <= n; ++bg) {
		for (int gc = 1; gc < bg && ans.size() <= n; ++gc) {
			ans.emplace_back(bg, gc);
			ans.emplace_back(gc, bg);
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}