#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ii> edge;
struct UFDS {
	int num;
	vector<int> parent, rankof;
	UFDS(int n) {
		num = n;
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
			rankof.push_back(0);
		}
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find_parent(parent[i]);
	}
	bool union_set(int a, int b) {
		int pa = find_parent(a), pb = find_parent(b);
		if (pa == pb) return false;
		if (rankof[pa] < rankof[pb]) parent[pa] = pb;
		else {
			if (rankof[pa] == rankof[pb]) ++rankof[pa];
			parent[pb] = pa;
		}
		--num;
		return true;
	}
	inline bool is_complete() {
		return num == 1;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	long long x[n], y[n];
	ull c[n], k[n], ans = 0;
	for (int i = 0; i < n; ++i) scanf("%lld %lld", &x[i], &y[i]);
	for (int i = 0; i < n; ++i) scanf("%llu", &c[i]);
	for (int i = 0; i < n; ++i) scanf("%llu", &k[i]);
	priority_queue< edge, vector<edge>, greater<edge> > pq;
	UFDS sets(n + 1);
	for (int i = 0; i < n; ++i) pq.push(edge(c[i], ii(0, i + 1)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) pq.push(edge((k[i] + k[j]) * (llabs(x[i] - x[j]) + llabs(y[i] - y[j])), ii(i + 1, j + 1)));
		}
	}
	vector<int> power;
	vector<ii> edges;
	while (!sets.is_complete()) {
		edge a = pq.top();
		pq.pop();
		if (sets.union_set(a.second.first, a.second.second)) {
			ans += a.first;
			if (a.second.first == 0) power.push_back(a.second.second);
			else edges.push_back(a.second);
		}
	}
	printf("%llu\n", ans);
	printf("%lu\n", power.size());
	if (power.size() != 0) {
		for (int i = 0; i < power.size() - 1; ++i) printf("%d ", power[i]);
		printf("%d\n", power.back());
	}
	printf("%lu\n", edges.size());
	for (int i = 0; i < edges.size(); ++i) printf("%d %d\n", edges[i].first, edges[i].second);
	return 0;
}