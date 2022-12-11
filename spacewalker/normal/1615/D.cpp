#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<pair<int, int>> elist;
vector<int> ewts;
vector<int> xorFromRoot, depth; // unknown edges are 0 here

void getXORs(int v, int p, int cxor, int cDepth) {
	xorFromRoot[v] = cxor;
	depth[v] = cDepth;
	for (auto [u, eid] : tree[v]) {
		if (p == u) continue;
		getXORs(u, v, cxor ^ (ewts[eid] == -1 ? 0 : ewts[eid]), cDepth+1);
	}
}

struct UnionFinder {
	vector<int> p, d, highest;
	UnionFinder() {}
	UnionFinder(int n, vector<int> &iDepths) : p(n, -1), d(iDepths), highest(n, -1) {
		iota(begin(highest), end(highest), 0);
	}
	int find(int i) {
		return (p[i] < 0 ? i : p[i] = find(p[i]));
	}
	int getRep(int i) { // rep in terms of tree height, NOT due to internal union find rep
		return highest[find(i)];
	}
	void join(int i, int j) {
		i = find(i), j = find(j);
		if (i == j) return;
		if (p[i] > p[j]) swap(i, j);
		if (d[j] < d[i]) {
			d[i] = d[j]; highest[i] = highest[j];
		}
		p[i] += p[j]; p[j] = i;
	}
};

vector<vector<int>> readyQueries;
UnionFinder uf;
// BOTH (u, v) and (v, u) must be in this set for the function to work
void getLCAs(int v, int p, vector<vector<int>> &queries, map<pair<int, int>, int> &ans) {
	for (int x : queries[v]) {
		readyQueries[x].push_back(v);
	}
	for (int x : readyQueries[v]) {
		ans[make_pair(x, v)] = uf.getRep(x);
		ans[make_pair(v, x)] = uf.getRep(x);
	}
	for (auto [u, eid] : tree[v]) {
		if (p == u) continue;
		getLCAs(u, v, queries, ans);
		uf.join(u, v);
	}
}

void solve() {
	int n, m; scanf("%d %d", &n, &m);	
	tree.assign(n, vector<pair<int, int>>());
	ewts.assign(n - 1, -1);
	elist.assign(n - 1, make_pair(0, 0));
	for (int i = 0; i < n - 1; ++i) {
		int x, y, v; scanf("%d %d %d", &x, &y, &v); --x; --y;
		tree[x].emplace_back(y, i);
		tree[y].emplace_back(x, i);
		elist[i] = {x, y};
		ewts[i] = v;
	}
	vector<pair<int, int>> elfPaths; vector<int> elfVals;
	for (int i = 0; i < m; ++i) {
		int a, b, p; scanf("%d %d %d", &a, &b, &p); --a; --b;
		elfPaths.emplace_back(a, b); elfVals.emplace_back(p);
	}
	// one: get XORs
	xorFromRoot.assign(n, 0);
	depth.assign(n, 0);
	getXORs(0, -1, 0, 0);
	// two: get LCAs
	vector<vector<int>> queries(n);
	for (auto [x, y] : elfPaths) {
		queries[x].emplace_back(y);
		queries[y].emplace_back(x);
	}
	readyQueries.clear();
	readyQueries.resize(n);
	uf = UnionFinder(n, depth);
	map<pair<int, int>, int> oLCA;
	getLCAs(0, -1, queries, oLCA);
	
	vector<int> srcPathXOR(m);
	for (int i = 0; i < m; ++i) {
		auto [u, v] = elfPaths[i];
		int x = oLCA[elfPaths[i]];
		srcPathXOR[i] = xorFromRoot[u] ^ xorFromRoot[v];
	}
	// check what the parities on the unknown edges need to be
	vector<int> unkParity(m);
	for (int i = 0; i < m; ++i) {
		if (__builtin_popcount(srcPathXOR[i]) % 2 != elfVals[i]) {
			unkParity[i] = 1;	
		}
		// printf("%d %d current xor %d unk %d\n", elfPaths[i].first + 1, elfPaths[i].second + 1, srcPathXOR[i], unkParity[i]);
	}
	vector<vector<pair<int, int>>> unkParGraph(n);
	for (int i = 0; i < n-1; ++i) {
		auto [u, v] = elist[i];
		if (ewts[i] != -1) {
			unkParGraph[u].emplace_back(v, 0);
			unkParGraph[v].emplace_back(u, 0);
		}
	}
	for (int i = 0; i < m; ++i) {
		auto [u, v] = elfPaths[i];
		unkParGraph[u].emplace_back(v, unkParity[i]);
		unkParGraph[v].emplace_back(u, unkParity[i]);
	}
	vector<int> unkValues(n, -1); // PER VERTEX
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (unkValues[i] != -1) continue;
		q.push(i);
		unkValues[i] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto [nxt, ew] : unkParGraph[cur]) {
				if (unkValues[nxt] == -1) {
					unkValues[nxt] = ew ^ unkValues[cur];
					q.push(nxt);
				} else if (unkValues[nxt] != (ew ^ unkValues[cur])) {
					printf("NO\n");
					return;
				}
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n - 1; ++i) {
		auto [u, v] = elist[i];
		int finalWeight = (ewts[i] == -1 ? 
			unkValues[u] ^ unkValues[v] : ewts[i]);
		printf("%d %d %d\n", u + 1, v + 1, finalWeight);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		solve();
	}
}