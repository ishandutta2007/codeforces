#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<pair<int, int>> elist;
vector<pair<int, int>> coverPaths;
vector<int> pathEnd;

void computeCoverPaths(int v, int p) {
	vector<int> ptConn;
	for (auto c_id : tree[v]) {
		int c = c_id.first;
		if (c != p) {
			computeCoverPaths(c, v);
			ptConn.push_back(pathEnd[c]);
		}
	}
	for (int i = 0; i + 1 < ptConn.size(); i += 2) {
		coverPaths.emplace_back(ptConn[i], ptConn[i + 1]);
	}
	if (ptConn.size() % 2 == 0) pathEnd[v] = v;
	else pathEnd[v] = ptConn.back();
	if (p == -1 && pathEnd[v] != v) coverPaths.emplace_back(v, pathEnd[v]);

}

vector<int> subParent, subEdgeToPar;
vector<int> biasVertex;

void calculateSub(int v, int p) {
	for (auto c_id : tree[v]) {
		if (c_id.first != p) {
			calculateSub(c_id.first, v);
			subParent[c_id.first] = v;
			subEdgeToPar[c_id.first] = c_id.second;
		}
	}
}

int findAnswer(int guess) {
	int nonBiased = -1;
	for (auto neigh_id : tree[guess]) {
		if (biasVertex[neigh_id.second] != guess) {
			nonBiased = neigh_id.first;
		}
	}
	if (nonBiased == -1) return guess;
	else return findAnswer(nonBiased);
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d %d", &x, &y); --x; --y;
		tree[x].emplace_back(y, i);
		tree[y].emplace_back(x, i);
		elist.emplace_back(x, y);
	}
	pathEnd = vector<int>(n, -1);
	computeCoverPaths(0, -1);	
	biasVertex = vector<int>(n - 1, -1);
	for (auto x_y : coverPaths) {
		printf("? %d %d\n", x_y.first + 1, x_y.second + 1);
		fflush(stdout);
		int w; scanf("%d", &w);
		if (w == -1) return 0;
		--w;
		subEdgeToPar = subParent = vector<int>(n, -1);
		calculateSub(w, -1);
		vector<int> pathElems{x_y.first, x_y.second};
		for (int v : pathElems) {
			for (int cur = v; cur != w; cur = subParent[cur]) {
				biasVertex[subEdgeToPar[cur]] = subParent[cur];
			}
		}
	}
	printf("! %d\n", findAnswer(0) + 1);
	return 0;
}