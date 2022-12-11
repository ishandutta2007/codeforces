#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> withPTake, withoutPTake;
vector<int> childToTake;

void getSetSizes(int v, int p) {
	int childCount = 0;
	for (int nxt : tree[v]) {
		if (nxt == p) continue;
		getSetSizes(nxt, v);
		withPTake[v] += withoutPTake[nxt];
		++childCount;
	}
	if (childCount == 0) return;
	int bias = -22;
	for (int nxt : tree[v]) {
		if (nxt == p) continue;
		int cValue = withPTake[nxt] - withoutPTake[nxt];
		if (cValue > bias) {
			bias = cValue;
			childToTake[v] = nxt;
		}
	}
	withoutPTake[v] = withPTake[v] + bias + 1;
}

void makeEList(int v, int p, vector<pair<int, int>> &ans, bool canTakeHere) {
	for (int nxt : tree[v]) {
		if (nxt == p) continue;
		if (nxt == childToTake[v]) {
			if (canTakeHere) {
				ans.emplace_back(v, childToTake[v]);
				makeEList(nxt, v, ans, false);
			} else makeEList(nxt, v, ans, true);
		} else {
			makeEList(nxt, v, ans, true);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		--x; --y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	withPTake = withoutPTake = vector<int>(n);
	childToTake = vector<int>(n, -1);
	getSetSizes(0, -1);
	printf("%d\n", 2 * (n - withoutPTake[0]));
	// construct the answer
	vector<pair<int, int>> indEdges;
	makeEList(0, -1, indEdges, true);
	vector<int> ans(n);
	iota(begin(ans), end(ans), 0);
	vector<bool> touched(n, false);
	for (auto [u, v] : indEdges) {
		swap(ans[u], ans[v]);
		touched[u] = touched[v] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (!touched[i]) {
			int nxt = tree[i][0];
			swap(ans[i], ans[nxt]);
		}
	}
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]+1);
	printf("\n");
	return 0;
}