#include <bits/stdc++.h>

using namespace std;

int a[6], b[100005], cnt[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int &i: a) scanf("%d", &i);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) for (int j: a) v.emplace_back(b[i] - j, i);
	sort(v.begin(), v.end());
	int l = 0, r = -1, num = 0, ans = 2e9;
	while (r < (int) v.size() - 1) {
		++cnt[v[++r].second];
		if (cnt[v[r].second] == 1) ++num;
		while (cnt[v[l].second] > 1) --cnt[v[l++].second];
		if (num == n) ans = min(ans, v[r].first - v[l].first);
	}
	printf("%d\n", ans);
	return 0;
}