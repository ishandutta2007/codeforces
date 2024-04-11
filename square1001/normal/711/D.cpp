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

int n, a[200009]; vector<pair<int, int> > G[200009]; int d[200009];
int dist(int x, int y) {
	queue<int> que; d[x] = 0; que.push(x);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (pair<int, int> e : G[u]) {
			if (e.second == x) continue;
			int i = e.first;
			if (d[i] == 999999999) {
				d[i] = d[u] + 1;
				que.push(i);
			}
		}
	}
	return d[y];
}
int modpow(int a, int b, int m) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return ret;
}
const int mod = 1000000007;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]), a[i]--;
		G[i].push_back(make_pair(a[i], i));
		G[a[i]].push_back(make_pair(i, i));
	}
	fill(d, d + n, 999999999);
	UnionFind uf(n);
	int sum = 0, ret = 1;
	for (int i = 0; i < n; i++) {
		if (!uf.same(i, a[i])) uf.unite(i, a[i]);
		else {
			int t = dist(i, a[i]);
			ret = 1LL * ret * (modpow(2, t + 1, mod) + mod - 2) % mod;
			sum += t + 1;
		}
	}
	ret = 1LL * ret * modpow(2, n - sum, mod) % mod;
	cout << ret << endl;
	return 0;
}