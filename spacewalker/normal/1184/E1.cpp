#include <bits/stdc++.h>

using namespace std;

struct unionfind {
	int n; vector<int> p;
	unionfind(int n) : n(n), p(n, -1) {}
	int find(int i) {
		return (p[i] < 0 ? i : p[i] = find(p[i]));
	}
	void join(int a, int b) {
		int ar = find(a), br = find(b);
		if (ar == br) return; 
		if (p[ar] > p[br]) swap(ar, br);
		p[ar] += p[br], p[br] = ar;
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<pair<int, pair<int, int>>> elist;
	for (int i = 0; i < m; ++i) {
		int a, b, e; scanf("%d %d %d", &a, &b, &e);
		--a; --b;
		elist.emplace_back(e, make_pair(a, b));
	}
	auto firstEdge = elist[0];
	int firstu, firstv;
	tie(firstu, firstv) = elist[0].second;
	sort(begin(elist), end(elist));
	unionfind cfing(n);
	for (auto edge : elist) {
		if (edge == firstEdge) continue;
		cfing.join(edge.second.first, edge.second.second);
		if (cfing.find(firstu) == cfing.find(firstv)) {
			printf("%d\n", edge.first);
			return 0;
		}
	}
	printf("1000000000\n");
	return 0;
}