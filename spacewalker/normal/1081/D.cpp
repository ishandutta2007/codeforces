#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct UnionFind {
	vector<int> p; int n;
	UnionFind(int n) : p(n, -1), n(n) {}
	int find(int v) {return (p[v] < 0 ? v : p[v] = find(p[v]));}
	bool join(int i, int j) {
		i = find(i), j = find(j);
		if (i == j) return false;
		if (p[i] > p[j]) swap(i, j);
		p[i] += p[j]; p[j] = i;
		return true;
	}
};

vector<vector<pair<int, int>>> mst;
vector<bool> isSpecial;

int getMaxEdgeBetween(int v, int p, int etp) {
	int runningMax = -1;
	for (auto next : mst[v]) {
		if (next.first != p) {
			runningMax = max(runningMax, getMaxEdgeBetween(next.first, v, next.second));
		}
	}
	if (runningMax > -1 || isSpecial[v]) {
		runningMax = max(runningMax, etp);
	}
	return runningMax;
}

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	isSpecial = vector<bool>(n);
	vector<int> specials(k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &specials[i]);
		isSpecial[--specials[i]] = true;
	}
	vector<pair<int, pair<int, int>>> eList;
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		eList.emplace_back(w, make_pair(u, v));
	}
	mst = vector<vector<pair<int, int>>>(n);
	sort(eList.begin(), eList.end());
	UnionFind onion(n);
	for (auto e : eList) {
		// printf("attempting to add %d %d\n", e.second.first, e.second.second);
		if (onion.join(e.second.first, e.second.second)) {
			mst[e.second.first].emplace_back(e.second.second, e.first);
			mst[e.second.second].emplace_back(e.second.first, e.first);
			// printf("in MST\n");
		}
	}
	int ans = getMaxEdgeBetween(specials[0], -1, -1);
	for (int i = 0; i < k; ++i) {
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}