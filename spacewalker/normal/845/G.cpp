#include <bits/stdc++.h>

using namespace std;

vector<int> eweights;
vector<pair<int, int>> elinks;
vector<bool> isTreeEdge;
vector<vector<pair<int, int>>> graph;
vector<int> pathxor;

void fillData(int v, int cxor) {
	pathxor[v] = cxor;
	for (auto n_id : graph[v]) {
		if (pathxor[n_id.first] == -1) {
			isTreeEdge[n_id.second] = true;
			fillData(n_id.first, cxor ^ eweights[n_id.second]);
		}
	}
}

int getMinXor(vector<int> &basis, int i, int curCost) {
	if (i == basis.size()) return curCost;
	else return min(getMinXor(basis, i + 1, curCost), getMinXor(basis, i + 1, curCost ^ basis[i]));
}

int bitIndex(int x) {
	if (x == 1) return 0;
	else return bitIndex(x >> 1) + 1;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	graph = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < m; ++i) {
		int x, y, w; scanf("%d %d %d", &x, &y, &w);
		eweights.push_back(w);
		elinks.emplace_back(--x, --y);
		graph[x].emplace_back(y, i);
		graph[y].emplace_back(x, i);
	}
	pathxor = vector<int>(n, -1);
	isTreeEdge = vector<bool>(m);
	fillData(0, 0);
	vector<int> toFilter;
	for (int i = 0; i < m; ++i) {
		if (!isTreeEdge[i]) {
			int elemToAdd = pathxor[elinks[i].first] ^ pathxor[elinks[i].second] ^ eweights[i];
			if (elemToAdd == 0) continue;
			toFilter.push_back(elemToAdd);
		}
	}
	sort(begin(toFilter), end(toFilter));
	map<int, int> bitKiller;
	for (int x : toFilter) {
		while (x > 0 && bitKiller.count(bitIndex(x)) > 0) {
			x ^= bitKiller[bitIndex(x)];
		}
		if (x > 0) bitKiller[bitIndex(x)] = x;
	}
	vector<int> basis;
	for (auto b_x : bitKiller) basis.push_back(b_x.second);
	printf("%d\n", getMinXor(basis, 0, pathxor[n-1]));
	return 0;
}