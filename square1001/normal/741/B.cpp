#include <set>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
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

int N, M, W, wt[1009], vt[1009], x, y;
int main() {
	scanf("%d%d%d", &N, &M, &W);
	for (int i = 0; i < N; i++) scanf("%d", &wt[i]);
	for (int i = 0; i < N; i++) scanf("%d", &vt[i]);
	unionfind uf(N);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &x, &y); x--, y--;
		uf.unite(x, y);
	}
	set<int> s;
	for (int i = 0; i < N; i++) s.insert(uf.root(i));
	vector<int> w, v; vector<vector<int> > x;
	for (int i : s) {
		w.push_back(0);
		v.push_back(0);
		x.push_back(vector<int>());
		for (int j = 0; j < N; j++) {
			if (uf.root(j) == i) {
				w.back() += wt[j];
				v.back() += vt[j];
				x.back().push_back(j);
			}
		}
	}
	vector<vector<int> > dp(w.size() + 1, vector<int>(W + 1));
	for (int i = 0; i < w.size(); i++) {
		for (int j = 0; j <= W; j++) dp[i + 1][j] = dp[i][j];
		for (int j = W; j >= w[i]; j--) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
		}
		for (int j : x[i]) {
			for (int k = W; k >= wt[j]; k--) {
				dp[i + 1][k] = max(dp[i + 1][k], dp[i][k - wt[j]] + vt[j]);
			}
		}
	}
	printf("%d\n", dp[w.size()][W]);
	return 0;
}