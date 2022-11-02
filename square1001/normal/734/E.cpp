#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

class UnionFind {
private:
	unsigned size_; std::vector<unsigned> par, rank;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	unsigned size() { return size_; }
	unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};

int n; vector<vector<int> > G;
std::vector<int> shortest_path_bfs(std::vector<std::vector<int> > &G, int s) {
	std::queue<int> que; que.push(s);
	std::vector<int> ret(G.size(), std::numeric_limits<int>::max()); ret[s] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : G[u]) {
			if (ret[i] == std::numeric_limits<int>::max()) {
				ret[i] = ret[u] + 1;
				que.push(i);
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);
	vector<int> a(n - 1), b(n - 1);
	UnionFind uf(n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a[i], &b[i]); a[i]--, b[i]--;
		if(d[a[i]] == d[b[i]]) uf.unite(a[i], b[i]);
	}
	vector<int> roots(n);
	for (int i = 0; i < n; i++) roots[i] = uf.root(i);
	sort(roots.begin(), roots.end());
	roots.erase(unique(roots.begin(), roots.end()), roots.end());
	G.resize(roots.size());
	for (int i = 0; i < n - 1; i++) {
		if (d[a[i]] != d[b[i]]) {
			int ptr1 = lower_bound(roots.begin(), roots.end(), uf.root(a[i])) - roots.begin();
			int ptr2 = lower_bound(roots.begin(), roots.end(), uf.root(b[i])) - roots.begin();
			G[ptr1].push_back(ptr2);
			G[ptr2].push_back(ptr1);
		}
	}
	if (G.size() == 1) printf("0\n");
	else {
		vector<int> ret = shortest_path_bfs(G, 0);
		int pos = max_element(ret.begin(), ret.end()) - ret.begin();
		vector<int> res = shortest_path_bfs(G, pos);
		int val = *max_element(res.begin(), res.end());
		cout << (val + 1) / 2 << endl;
	}
	return 0;
}