#include <set>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

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

int n, x;
int main() {
	cin >> n;
	unionfind uf(n);
	for (int i = 0; i < n; i++) cin >> x, x--, uf.unite(i, x);
	set<int> s;
	for (int i = 0; i < n; i++) s.insert(uf.root(i));
	cout << s.size() << endl;
	return 0;
}