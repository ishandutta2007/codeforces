#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> tree;

vector<pair<int, int>> leafRanges;
vector<int> leaves;
vector<int> depth, par;
int leafCounter = 0;

void getlinfo(int v, int p, int cDepth) {
	leafRanges[v].first = leafCounter;
	depth[v] = cDepth;
	par[v] = p;
	int childCount = 0;
	for (int u : tree[v]) {
		if (p == u) continue;
		++childCount;
		getlinfo(u, v, cDepth + 1);
		leafRanges[v].second = leafRanges[u].second;
	}
	if (childCount == 0) {
		leafRanges[v].second = leafCounter++;
		leaves.push_back(v);
	}
}

struct CrayonTree {
	int al, ar;
	int rmax, rargmax, lazy;
	CrayonTree *left, *right;
	void combine() {
		CrayonTree *from = (left->rmax > right->rmax ? left : right);
		rmax = from->rmax;
		rargmax = from->rargmax;
	}
	void propagate() {
		if (lazy != 0) {
			rmax += lazy;
			if (left) {
				left->lazy += lazy;
				right->lazy += lazy;
			}
			lazy = 0;
		}
	}
	CrayonTree(int i, int j) : al(i), ar(j), rmax(-1), rargmax(i), lazy(0),
		left(nullptr), right(nullptr) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new CrayonTree(i, k);
			right = new CrayonTree(k + 1, j);
			combine();
		}
	}
	~CrayonTree() {
		if (left) {
			delete left;
			delete right;
		}
	}
	void addRange(int i, int j, int v) {
		propagate();
		if (i <= al && ar <= j) {
			lazy += v;
			propagate();
		} else if (ar < i || j < al) return;
		else {
			left->addRange(i, j, v);
			right->addRange(i, j, v);
			combine();
		}
	}
};

vector<bool> hasRedChild;
bool checkRedChild(int v, int p) {
	for (int u : tree[v]) {
		if (u == p) continue;
		if (checkRedChild(u, v)) hasRedChild[v] = true;
	}
	return hasRedChild[v];
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	tree.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		tree[u].emplace_back(v);
		tree[v].emplace_back(u);
	}
	leafRanges.resize(n);
	par.resize(n);
	depth.resize(n);
	getlinfo(0, -1, 0);
	vector<int> leafDepths;
	for (int l : leaves) {
		leafDepths.emplace_back(depth[l]);
	}
	CrayonTree ct(0, (int)leaves.size() - 1);
	for (int i = 0; i < leaves.size(); ++i) ct.addRange(i, i, leafDepths[i]);
	vector<int> redLeaves;
	vector<bool> folded(n, false);
	folded[0] = true;
	ll ans = -1e18;
	if (k >= leaves.size()) {
		for (ll i = leaves.size(); i <= k; ++i) {
			ans = max(ans, (n - i) * i);
		}
	} // run the greedy alg to pick leaves
	ll redCount = 0, whiteCount = 1; // the root will always be white
	for (int lpick = 0; lpick < min(k, (int)leaves.size()); ++lpick) {
		int leafID = ct.rargmax;
		++redCount;
		redLeaves.push_back(leaves[leafID]);
		for (int v = leaves[leafID]; !folded[v]; v = par[v]) {
			ct.addRange(leafRanges[v].first, leafRanges[v].second, -1);
			if (v != leaves[leafID]) ++whiteCount;
			folded[v] = true;
		}
		ll maxBlueCount = (n - redCount - whiteCount);
		ll blueTake = min((whiteCount + maxBlueCount) * redCount,
			whiteCount * (redCount - maxBlueCount));
		ll blueBestCase = n / 2;
		if (blueBestCase <= maxBlueCount) {
			blueTake = min(blueTake, (whiteCount + (maxBlueCount - blueBestCase))
				* (redCount - blueBestCase));
		}
		ans = max(ans, blueTake);
	}
	printf("%lld\n", ans);
	/*
	hasRedChild.resize(n);
	for (int v : redLeaves) hasRedChild[v] = true;
	checkRedChild(0, -1);
	ll redCount = 0, blueCount = 0, whiteCount = 0;
	redCount = redLeaves.size();
	for (int i = 0; i < n; ++i) if (!hasRedChild[i]) blueCount++;
	whiteCount = (n - redCount - blueCount);
	*/
}