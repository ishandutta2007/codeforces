#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> pts(n);
	int minX = INF, minY = INF; 
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &pts[i].first, &pts[i].second);
	}
	for (int i = n - 1; i >= 0; --i) {
		pts[i].first -= pts[0].first, pts[i].second -= pts[0].second;
	}
	while (true) {
		bool allDiv2 = true;
		for (int i = 0; i < n; ++i) {
			if (pts[i].first % 2 != 0) allDiv2 = false;
			if (pts[i].second % 2 != 0) allDiv2 = false;
		}
		if (!allDiv2) break;
		for (int i = 0; i < n; ++i) {
			pts[i].first /= 2;
			pts[i].second /= 2;
		}
	}
//	printf("corrected coefficients:\n");
//	for (int i = 0; i < n; ++i) printf("%d %d\n", pts[i].first, pts[i].second);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if ((pts[i].first % 2 != 0) != (pts[i].second % 2 != 0)) ans.push_back(i);
	}
	if (ans.empty()) {
		for (int i = 0; i < n; ++i) {
			if (pts[i].first % 2 != 0) ans.push_back(i);
		}
	}
	printf("%lu\n", ans.size());
	for (int x : ans) printf("%d\n", x + 1);
	return 0;
}