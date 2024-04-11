#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <utility>
#include <cmath>

using namespace std;

struct BinaryLifter {
	vector<vector<pair<int, int>>> tree;
	vector<vector<int>> antable, anpst;
	vector<int> rootDist, depth;
	int n, ROOT;
	void fillInfo(int v, int p, int wToPar) {
		antable[0][v] = p;
		rootDist[v] = (v == ROOT ? 0 : rootDist[p] + wToPar);
		anpst[0][v] = wToPar;
		depth[v] = (v == ROOT ? 0 : depth[p] + 1);
		for (int js = 1; js < antable.size(); ++js) {
			if (antable[js-1][v] != -1 and antable[js-1][antable[js-1][v]] != -1) {
				antable[js][v] = antable[js-1][antable[js-1][v]];
				anpst[js][v] = anpst[js-1][v] + anpst[js-1][antable[js-1][v]];
			}
		}
		for (auto c_w : tree[v]) {
			if (c_w.first != p) fillInfo(c_w.first, v, c_w.second);
		}
	}
	BinaryLifter(vector<vector<pair<int, int>>> &t, int r) : tree(t), n(t.size()), ROOT(r) {
		antable = anpst = vector<vector<int>>(log2(n) + 1, vector<int>(n, -1));
		rootDist = depth = vector<int>(n);
		// printf("here\n");
		fillInfo(ROOT, -1, 0);
	}
	BinaryLifter() {}
	int LCA(int u, int v) {
		if (depth[v] > depth[u]) swap(u, v);
		if (depth[u] > depth[v]) {
			for (int js = antable.size() - 1; js >= 0; --js) {
				if (antable[js][u] != -1 and depth[antable[js][u]] >= depth[v]) {
					u = antable[js][u];
				}
			}
		}
		// printf("equalized: %d %d\n", u, v);
		if (u == v) return u;
		for (int js = antable.size() - 1; js >= 0; --js) {
			if (antable[js][u] != -1 and antable[js][u] != antable[js][v]) {
				// printf("taking size %d to %d %d\n", (1 << js), u, v);
				u = antable[js][u], v = antable[js][v];
			}
		}
		// printf("ans to LCA call: %d\n", antable[0][u]);
		return antable[0][u];
	}
	int pathDist(int u, int v) {
		// printf("LCAQ %d %d = %d\n", u, v, LCA(u, v));
		// printf("depths %d %d %d\n", depth[u], depth[v], depth[LCA(u, v)]);
		return depth[u] + depth[v] - 2*depth[LCA(u, v)];
	}
	int farthestOnDist(int v, int k) {
		for (int js = antable.size() - 1; js >= 0; --js) {
			if (antable[js][v] != -1 and anpst[js][v] <= k) {
				k -= anpst[js][v];
				v = antable[js][v];
			}
		}
		return v;
	}
};

vector<vector<pair<int, int>>> tree;
vector<int> deepIST, deepOutST;

void fillDeepIST(int v, int p) {
	for (auto c_w : tree[v]) {
		if (c_w.first != p) fillDeepIST(c_w.first, v);
	}
	for (auto c_w : tree[v]) {
		if (c_w.first != p) deepIST[v] = max(deepIST[v], deepIST[c_w.first] + c_w.second);
	}
}

void fillDeepOST(int v, int p) {
	multiset<int> childVals;
	for (auto c_w : tree[v]) if (c_w.first != p) childVals.insert(deepIST[c_w.first] + c_w.second);
	for (auto c_w : tree[v]) {
		if (c_w.first != p) {
			childVals.erase(childVals.find(deepIST[c_w.first] + c_w.second));
			deepOutST[c_w.first] = max(deepOutST[c_w.first], c_w.second + max(deepOutST[v], (childVals.empty() ? 0 : *childVals.rbegin())));
			childVals.insert(deepIST[c_w.first] + c_w.second);
			fillDeepOST(c_w.first, v);
		}
	}
}

BinaryLifter blft;

vector<bool> impt;
vector<int> icct;
vector<vector<int>> icList;

void fillListInfo(int v, int p) {
	for (auto c_w : tree[v]) {
		if (c_w.first != p) {
			fillListInfo(c_w.first, v);
			icct[v] += icct[c_w.first];
		}
	}
	if (impt[v] and icct[v] == 0) {
		++icct[v];
		icList[v].push_back(v);
	}
	for (auto c_w : tree[v]) {
		if (c_w.first != p) icList[v].insert(icList[v].end(), icList[c_w.first].begin(), icList[c_w.first].end());
	}
	if (icct[v] > 2) icList[v].clear();
}

int main() {
	int n, k; scanf("%d %d", &n, &k); --k;
	tree = vector<vector<pair<int, int>>>(n);
	deepIST = deepOutST = icct = vector<int>(n);
	impt = vector<bool>(n, false);
	icList = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		tree[--u].emplace_back(--v, d);
		tree[v].emplace_back(u, d);
	}
	if (n == 1) printf("0\n");
	if (n == 2) {
		printf("%d\n", (k == 0 ? tree[0][0].second : 0));
	}
	if (n <= 2) return 0;
	int ROOT = -1;
	for (int i = 0; i < n; ++i) {
		if (tree[i].size() > 1) ROOT = i; 
	}
	blft = BinaryLifter(tree, ROOT);
	// printf("blft initialized rooted at %d\n", ROOT);
	fillDeepIST(ROOT, -1);
	fillDeepOST(ROOT, -1);
	// for (int i = 0; i < n; ++i) printf("ost %d %d i %d\n", i, deepOutST[i], deepIST[i]);
	int lo = 0;
	int hi = 1111111111;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		// printf("testing mid %d\n", mid);
		fill(impt.begin(), impt.end(), false);
		fill(icct.begin(), icct.end(), 0);
		for (int i = 0; i < n; ++i) icList[i].clear();
		for (int i = 0; i < n; ++i) if (tree[i].size() == 1) impt[blft.farthestOnDist(i, mid)] = true;
		fillListInfo(ROOT, -1);
		for (int i = 0; i < n; ++i) {
			if (icct[i] == 1) icList[i].push_back(i);
		}
		bool passes = false;
		for (int i = 0; i < n; ++i) {
			passes = (passes or (deepOutST[i] <= mid and 
				(icct[i] == 0 or (icct[i] <= 2 and blft.pathDist(icList[i][0], icList[i][1]) <= k and blft.LCA(icList[i][0], icList[i][1]) == i))));
			// printf("%d (op %d) has %d impt children\n", i, deepOutST[i], icct[i]);
			// if (icct[i] > 0) printf("they are %d %d at dist %d\n", icList[i][0], icList[i][1], blft.pathDist(icList[i][0], icList[i][1]));
		}
		if (passes) hi = mid;
		else lo = mid + 1;
	}
	printf("%d\n", lo);
	return 0;
}