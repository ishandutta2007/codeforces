#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> ii;
struct UFDS {
	int ds;
	vector<int> parent, rankof;
	UFDS(int N) {
		ds = N;
		for (int i = 0; i < N; ++i) parent.push_back(i), rankof.push_back(0);
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		else return parent[i] = find_parent(parent[i]);
	}
	bool union_set(int p, int q) {
		int pp = find_parent(p), pq = find_parent(q);
		if (pp == pq) return false;
		--ds;
		if (rankof[pp] == rankof[pq]) ++rankof[pp];
		if (rankof[pp] > rankof[pq]) parent[pq] = pp;
		else parent[pp] = pq;
		return true;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	ii ranges[n];
	for (int i = 0; i < n; ++i) scanf("%d %d", &ranges[i].first, &ranges[i].second);
	sort(ranges, ranges + n);
	set<ii> pq;
	UFDS s(n);
	for (int i = 0; i < n; ++i) {
		while (!pq.empty() && pq.begin() -> first < ranges[i].first) pq.erase(pq.begin());
		for (set<ii>::iterator it = pq.begin(); it != pq.end() && it -> first < ranges[i].second; ++it) {
			if (!s.union_set(i, it -> second)) {
				printf("NO");
				return 0;
			}
		}
		pq.insert(ii(ranges[i].second, i));
	}
	printf(s.ds == 1 ? "YES" : "NO");
	return 0;
}