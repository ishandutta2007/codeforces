#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> alive;
vector<int> subtreeSize, maxChildSize, ans, vtv;

void getSizes(int v, int p) {
	vtv.push_back(v);
	subtreeSize[v] = 1;
	maxChildSize[v] = 0;
	for (int u : tree[v]) {
		if (alive[u] and u != p) {
			getSizes(u, v);
			subtreeSize[v] += subtreeSize[u];
			maxChildSize[v] = max(subtreeSize[u], maxChildSize[v]);
		}
	}
	// printf("vertex %d has ss %d mcs %d\n", v, subtreeSize[v], maxChildSize[v]);
}

int cDecompose(int pRoot, int level) {
	// root the subtree
	if (!alive[pRoot]) return -1;
	// getSizes(pRoot, -1);
	int viableCentroid = -1;
	getSizes(pRoot, -1);
	for (int v : vtv) {
		if (maxChildSize[v] <= vtv.size()/2 and vtv.size() - subtreeSize[v] <= vtv.size()/2) {
			viableCentroid = v;
			break;
		}
	}
	alive[viableCentroid] = false;
	ans[viableCentroid] = level;
	vtv.clear();
	// printf("%d centroid of comp\n", viableCentroid);
	for (int neigh : tree[viableCentroid]) {
		cDecompose(neigh, level + 1);
		// printf("%d child of %d\n", pChild, viableCentroid);
	}
	return viableCentroid;
}

int main() {
	int n; scanf("%d", &n);
	vtv.reserve(n);
	tree = vector<vector<int>>(n);
	subtreeSize = ans = maxChildSize = vector<int>(n);
	alive = vector<bool>(n, true);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		tree[--a].push_back(--b);
		tree[b].push_back(a);
	}
	int cdRoot = cDecompose(0, 0);
	// printf("root is %d\n", cdRoot);
	for (int i = 0; i < n; ++i) printf("%c ", char(ans[i] + 'A'));
	printf("\n");
	return 0;
}