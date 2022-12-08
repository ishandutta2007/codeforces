#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[200005];

void solve() {
	int n;
	long long m;
	scanf("%d%lld", &n, &m);
	long long sum = 0;
	int minm = 2e9;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i].first), p[i].second = i, minm = min(minm, p[i].first);
		if (p[i].first <= m) sum += p[i].first;
	}
	sort(p + 1, p + n + 1, greater<pair<int, int>>());
	vector<int> v;
	if (sum + sum < m || minm > m) {
		puts("-1");
		return;
	}
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (p[i].first <= m) {
			v.push_back(p[i].second);
			sum += p[i].first;
			if (sum + sum >= m) break;
		}
	}
	printf("%d\n", v.size());
	for (int i: v) printf("%d ", i);
	puts("");
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