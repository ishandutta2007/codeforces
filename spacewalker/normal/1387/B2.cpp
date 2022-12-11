#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> tree;
vector<int> rootedSize, magulang;
constexpr int IROOT = 0;

void getSizes(int v, int p) {
	rootedSize[v] = 1;
	magulang[v] = p;
	for (int nxt : tree[v]) {
		if (nxt == p) continue;
		getSizes(nxt, v);
		rootedSize[v] += rootedSize[nxt];
	}
}

bool isCentroid(int v) {
	int n = tree.size();
	bool ans = true;
	for (int nxt : tree[v]) {
		if (nxt == magulang[v] && rootedSize[IROOT] - rootedSize[v] > n/2) ans = false;
		if (nxt != magulang[v] && rootedSize[nxt] > n/2) ans = false;
	}
	return ans;
}

void getComponent(int v, int p, vector<int> &comps, int cID) {
	comps[v] = cID;
	for (int nxt : tree[v]) {
		if (nxt == p) continue;
		getComponent(nxt, v, comps, cID);
	}
}

bool isValidAnswer(vector<int> &ans) {
	for (int i = 0; i < ans.size(); ++i) if (ans[i] == i) return false;
	return true;
}

bool attemptRingShuffle(vector<pair<int, int>> &ring, vector<int> &ans) {
	int rs = ring.size();
	for (int i = 0, j = rs / 2; i < rs; ++i, j = (j + 1) % rs) {
		if (ring[i].first == ring[j].first) return false;
		ans[ring[i].second] = ring[j].second;
	}
	return true;
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		--x; --y;
		tree[x].emplace_back(y);
		tree[y].emplace_back(x);
	}
	if (n == 2) {
		printf("2\n2 1\n");
		return 0;
	}
	rootedSize = vector<int>(n, 0);
	magulang = vector<int>(n, -1);
	getSizes(0, -1);
	int centroid = -1;
	for (int i = 0; i < n; ++i) if (isCentroid(i)) centroid = i;
	vector<int> centIDs(n, -1);
	for (int v : tree[centroid]) getComponent(v, centroid, centIDs, v);

	vector<int> ans(n, -1);
	// get the two exemptors
	map<int, int> cSize, represent;
	for (int i = 0; i < n; ++i) {
		if (i != centroid) {
			++cSize[centIDs[i]];
			represent[centIDs[i]] = i;
		}
	}
	vector<pair<int, int>> cBySize;
	for (auto [id, sz] : cSize) cBySize.emplace_back(sz, represent[id]);
	sort(begin(cBySize), end(cBySize));
	reverse(begin(cBySize), end(cBySize));
	int ex1 = cBySize[0].second, ex2 = cBySize[1].second;
//	printf("c %d ex %d %d\n", centroid, ex1, ex2);
	ans[centroid] = ex1;
	ans[ex1] = ex2;
	ans[ex2] = centroid;
	// throw everyone into the ring
	vector<pair<int, int>> ring;
	for (int i = 0; i < n; ++i) {
		if (i != centroid && i != ex1 && i != ex2) ring.emplace_back(centIDs[i], i);
	}
	sort(begin(ring), end(ring));
	if (!attemptRingShuffle(ring, ans)) {
//		printf("first round fail\n");
		ring.clear();
		ans.assign(n, -1);
		ans[ex1] = centroid;
		ans[centroid] = ex1;
//		printf("c %d ex %d\n", centroid, ex1);
		ex2 = -1;
		for (int i = 0; i < n; ++i) {
			if (i != centroid && i != ex1) ring.emplace_back(centIDs[i], i);
		}
		sort(begin(ring), end(ring));
		attemptRingShuffle(ring, ans);
	}
	ll maxPDist = 0;
	for (int i = 0; i < n; ++i) {
		maxPDist += 2 * min(rootedSize[i], n - rootedSize[i]);
	}
	// print the answer
	printf("%lld\n", maxPDist);
	for (int x : ans) printf("%d ", x + 1);
	printf("\n");
	return 0;
}