#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vCat;

bool isLinearPath(int i, int j, int k) {
	if (i == j || j == k) return true;
	return vCat[j][i] != vCat[j][k];
}

void attAnswerFind(vector<int> &subgraph, vector<pair<int, int>> &eList) {
//	printf("subgraph");
//	for (int x : subgraph) printf(" %d", x);
//	printf("\n");
	if (subgraph.size() == 1) return;
	if (subgraph.size() == 2) {
		eList.emplace_back(subgraph[0], subgraph[1]);
		return;
	}
	int a = subgraph[0], b = subgraph[1];
	for (int i = 2; i < subgraph.size(); ++i) {
		if (isLinearPath(a, subgraph[i], b)) b = subgraph[i];
	}
//	printf("found edge %d %d\n", a, b);
	eList.emplace_back(a, b);
	vector<int> firstHalf, secondHalf;
	for (int v : subgraph) {
		if (isLinearPath(a, b, v)) firstHalf.push_back(v);
		else secondHalf.push_back(v);
	}
	attAnswerFind(firstHalf, eList);
	attAnswerFind(secondHalf, eList);
}

vector<vector<int>> attTree;
vector<int> comps;

void populate(int v, int p, int fillC, int blockV) {
	if (v == blockV) return;
//	printf("%d comp %d\n", v, fillC);
	comps[v] = fillC;
	for (int nxt : attTree[v]) {
		if (nxt == p) return;
		populate(nxt, v, fillC, blockV);
	}
}

int main() {
	int n; scanf("%d", &n);
	vCat = vector<vector<int>>(n, vector<int>(n, -1));
	for (int i = 0; i < n; ++i) {
		char burner = 0;
		vector<vector<int>> comps;
		while (burner != '\n') {
			int k; scanf("%d", &k);
			comps.emplace_back();
			for (int i = 0; i < k; ++i) {
				scanf("%c", &burner);
				int x; scanf("%d", &x); --x;
				comps.back().push_back(x);
			}
			scanf("%c", &burner);
		}
		for (int j = 0; j < comps.size(); ++j) {
			for (int x : comps[j]) vCat[i][x] = j;
		}
	}
	vector<int> complete(n);
	vector<pair<int, int>> attEList;
	for (int i = 0; i < n; ++i) complete[i] = i;
	attAnswerFind(complete, attEList);
	attTree = vector<vector<int>>(n);
	for (auto a_b : attEList) {
		attTree[a_b.first].push_back(a_b.second);
		attTree[a_b.second].push_back(a_b.first);
	}
	bool tugma = true;
	for (int i = 0; i < n; ++i) {
//		printf("starting from %d\n", i);
		comps.assign(n, -1);
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (comps[j] == -1) populate(j, -1, vCat[i][j], i);
		}
		if (comps != vCat[i]) tugma = false;
	}
	if (tugma) {
		printf("%d\n", n - 1);
		for (auto a_b : attEList) printf("%d %d\n", a_b.first + 1, a_b.second + 1);
	} else {
		printf("-1\n");
	}
	return 0;
}