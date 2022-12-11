#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct UFDS {
	vector<int> p;
	ll cPairs;
	UFDS() {}
	UFDS(int n) : p(n, -1), cPairs(0) {}
	int find(int i) {
		return (p[i] < 0 ? i : p[i] = find(p[i]));
	}
	void join(int i, int j) {
		i = find(i), j = find(j);
		if (i == j) return;
		if (p[i] > p[j]) swap(i,j);
		cPairs += (ll)p[i] * p[j];
		p[i] += p[j]; p[j] = i;
	}
};

int main() {
	int n, q; scanf("%d %d", &n, &q);
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < n - 1; ++i) {
		int x, y, w; scanf("%d %d %d", &x, &y, &w);
		--x; --y;
		edges.emplace_back(w, x, y);
	}
	sort(begin(edges), end(edges));
	UFDS yeet(n);
	map<int, ll> ans;
	ans[0] = 0;
	for (auto [w, x, y] : edges) {
		yeet.join(x, y);
		ans[-w] = yeet.cPairs;
	}
	while (q--) {
		int x; scanf("%d", &x);
		auto iter = ans.lower_bound(-x);
		printf("%lld ", iter->second);
	}
	printf("\n");
	return 0;
}