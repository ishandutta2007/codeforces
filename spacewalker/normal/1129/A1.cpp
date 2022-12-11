#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;

int circleDist(int i, int j) {
	if (i <= j) return j - i;
	else return j - i + n;
}

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> candies(n);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		--a; --b;
		candies[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		sort(candies[i].begin(), candies[i].end(), [&i] (int x, int y) {
			return circleDist(i, x) < circleDist(i, y);
		});
	}
	vector<ll> worstDist(n);
	for (int i = 0; i < n; ++i) {
		if (candies[i].empty()) continue;
		else worstDist[i] = (ll(candies[i].size()) - 1) * n + circleDist(i, *candies[i].begin());
		// printf("wd %d %lld %d %d\n", i, worstDist[i], circleDist(i, *candies[i].begin()), *candies[i].begin());
	}
	// for (int x : worstDist) printf("W %d\n", x);
	for (int i = 0; i < n; ++i) {
		ll ans = 0;
		for (int j = 0; j < n; ++j) {
			if (worstDist[j] > 0) ans = max(ans, circleDist(i, j) + worstDist[j]);
		}
		printf("%lld ", ans);
	}
	printf("\n");
	return 0;
}