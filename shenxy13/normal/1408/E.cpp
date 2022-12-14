#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, ii> iii;
struct UFDS {
	vector<int> parent, rankof;
	UFDS(int N) {
		for (int i = 0; i < N; ++i) parent.push_back(i), rankof.push_back(0);
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find_parent(parent[i]);
	}
	bool union_set(int p, int q) {
		p = find_parent(p), q = find_parent(q);
		if (p == q) return false;
		if (rankof[p] == rankof[q]) ++rankof[p];
		if (rankof[p] > rankof[q]) parent[q] = p;
		else parent[p] = q;
		return true;
	}
};
int main() {
	int m, n, s, A;
	scanf("%d %d", &m, &n);
	long long a[m], b[n], ans = 0;
	for (int i = 0; i < m; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
	priority_queue<iii> pq;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &s);
		for (int j = 0; j < s; ++j) {
			scanf("%d", &A);
			pq.push(iii(a[i] + b[A - 1], ii(i, m + A - 1)));
		}
	}
	UFDS sets(m + n);
	while (!pq.empty()) {
		iii a = pq.top();
		pq.pop();
		if (!sets.union_set(a.second.first, a.second.second)) ans += a.first;
	}
	printf("%lld", ans);
	return 0;
}