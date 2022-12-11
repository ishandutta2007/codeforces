#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
using namespace std;

struct wEdge {
	int u, v, w;
	wEdge() {}
};

struct UnionFind {
	vector<int> par, rank;
	int n;
	UnionFind(int n) : par(n), rank(n), n(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return (par[x] = find(par[x]));
	}
	void join(int i, int j) {
		i = find(i); j = find(j);
		if (i == j) return;
		if (rank[i] >= rank[j]) {
			if (rank[i] == rank[j]) ++rank[i];
			par[j] = i;
		} else par[i] = j;
	}
};

vector<vector<pair<int, int>>> compAdj;
vector<int> low, disc;
vector<bool> isBridge, bridgeExempt;
int t;

void prepareBridgeFind(int cs, int ect) {
	// printf("PREP %d V %d E\n", cs, ect);
	compAdj = vector<vector<pair<int, int>>>(cs);
	low = disc = vector<int>(cs, -1);
	isBridge = bridgeExempt = vector<bool>(ect);
	t = 0;
}

void checkBridges(int i, int p, int edgeTo) {
	// printf("CHECKB %d\n", i);
	disc[i] = t;
	low[i] = t++;
	for (auto next_id : compAdj[i]) {
		if (disc[next_id.first] == -1) {
			checkBridges(next_id.first, i, next_id.second);
			low[i] = min(low[i], low[next_id.first]);
		} else if (next_id.first != p) {
			low[i] = min(low[i], disc[next_id.first]);
		}
	}
	// printf("%d ABOUT EXIT\n", i);
	if (low[i] >= disc[i] and p != -1 and !bridgeExempt[edgeTo]) {
		// printf("BRIDGE FLAG\n");
		isBridge[edgeTo] = true;
	}
	// printf("%d EXIT\n", i);
}

void fillBridgeInfo() {
	for (int i = 0; i < compAdj.size(); ++i) {
		if (disc[i] == -1) checkBridges(i, -1, -1);
	}
}

int temp() {
	int n, m; scanf("%d %d", &n, &m);
	vector<wEdge> eList(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &eList[i].u, &eList[i].v, &eList[i].w);
		--eList[i].u; --eList[i].v;
	}
	vector<int> sorted(m);
	vector<pair<int, int>> compEList(m);
	for (int i = 0; i < m; ++i) sorted[i] = i;
	sort(sorted.begin(), sorted.end(), [&eList] (int i, int j) {return eList[i].w < eList[j].w;});
	vector<int> ans(m);
	UnionFind sama(n);
	// printf("EDGE PROC\n");
	for (int i = 0, j = 0; i < m; i = j) {
		while (j < m and eList[sorted[i]].w == eList[sorted[j]].w) ++j;
// 		printf("CHUNK %d %d ON %d\n", i, j - 1, eList[sorted[i]].w);
		unordered_map<int, int> coordComp;
		int curCompI = 0;
		for (int ei = i; ei < j; ++ei) {
			int nu = sama.find(eList[sorted[ei]].u), nv = sama.find(eList[sorted[ei]].v);
			// printf("nu %d nv %d\n", nu, nv);
			if (coordComp.count(nu) == 0) coordComp[nu] = curCompI++;
			if (coordComp.count(nv) == 0) coordComp[nv] = curCompI++;
// 			printf("=> %d %d\n", coordComp[nu], coordComp[nv]);
		}
		prepareBridgeFind(coordComp.size(), j - i);
		for (int ei = i; ei < j; ++ei) compEList[ei] = make_pair(coordComp[sama.find(eList[sorted[ei]].u)], coordComp[sama.find(eList[sorted[ei]].v)]);
		for (int ei = i; ei < j; ++ei) if (compEList[ei].first > compEList[ei].second) swap(compEList[ei].first, compEList[ei].second);
		map<pair<int, int>, int> eCounts;
		// printf("ECOUNT\n");
		for (int ei = i; ei < j; ++ei) ++eCounts[compEList[ei]];
		for (int ei = i; ei < j; ++ei) {
		  //  printf("COMP %d %d\n", compEList[ei].first, compEList[ei].second);
			if (eCounts[compEList[ei]] > 1) bridgeExempt[ei - i] = true;
			// printf("COMP EDGE %d %d\n", compEList[ei].first, compEList[ei].second);
			compAdj[compEList[ei].first].emplace_back(compEList[ei].second, ei - i);
			compAdj[compEList[ei].second].emplace_back(compEList[ei].first, ei - i);
		}
// 		continue;
		fillBridgeInfo();
		// printf("HEREE\n");
		for (int ei = i; ei < j; ++ei) {
			if (compEList[ei].first == compEList[ei].second) {ans[sorted[ei]] = -1;}
			else if (isBridge[ei - i]) ans[sorted[ei]] = 1;
			sama.join(eList[sorted[ei]].u, eList[sorted[ei]].v);
		}
	}
	for (int e : ans) {
		if (e == -1) printf("none\n");
		else if (e == 1) printf("any\n");
		else printf("at least one\n");
	}
	return 0;
}

int main() {
	temp();
	return 0;
}