#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> u;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		int maxm = 0;
		for (int j = 0; j < k; ++j) {
			int p;
			scanf("%d", &p);
			maxm = max(maxm, p - j);
		}
		u.emplace_back(maxm, k);
	}
	sort(u.begin(), u.end());
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (ans + cnt > u[i].first) cnt += u[i].second;
		else ans = u[i].first + 1 - cnt, cnt += u[i].second;
	}
	printf("%d\n", ans);
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