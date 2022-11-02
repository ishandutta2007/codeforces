#include <vector>
#include <numeric>
#include <algorithm>

class unionfind {
private:
	int size_;
	std::vector<int> parent;
	std::vector<int> rank;
public:
	unionfind() : size_(0), parent(std::vector<int>()), rank(std::vector<int>()) {};
	unionfind(int size__) : size_(size__), parent(std::vector<int>(size_)), rank(std::vector<int>(size_, 0)) {
		std::iota(parent.begin(), parent.end(), 0);
	}
	int size() { return size_; }
	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) parent[x] = y;
		else if (rank[x] > rank[y]) parent[y] = x;
		else parent[y] = x, rank[x]++;
	}
};

#include <map>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, p, c[200009], l, r; vector<int> t[200009];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	unionfind uf(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &l, &r); l--, r--;
		uf.unite(l, r);
	}
	for (int i = 0; i < n; i++) t[uf.root(i)].push_back(i);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		map<int, int> w;
		for (int j : t[i]) w[c[j]]++;
		int res = 0;
		for (pair<int, int> j : w) res = max(res, j.second);
		ret += t[i].size() - res;
	}
	printf("%d\n", ret);
	return 0;
}