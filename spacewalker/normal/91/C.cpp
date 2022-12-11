#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
constexpr int MOD = 1000000009;

int pow2[300000];

struct UnionFind {
	vector<int> par, rank;
	int n, compCount;
	UnionFind(int n) : par(n, 0), rank(n, 0), n(n), compCount(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int i) {
		if (par[i] == i) return i;
		else return (par[i] = find(par[i]));
	}
	void join(int i, int j) {
		i = find(i), j = find(j);
		if (i == j) return;
		--compCount;
		if (rank[i] >= rank[j]) {
			if (rank[i] == rank[j]) ++rank[i];
			par[j] = i;
		} else par[i] = j;
	}
};

int main() {
	pow2[0] = 1;
	for (int i = 1; i < 300000; ++i) pow2[i] = (pow2[i-1] << 1) % MOD;
	int n, m; scanf("%d %d", &n, &m);
	UnionFind sama(n);
	for (int e = 1; e <= m; ++e) {
		int a, b; scanf("%d %d", &a, &b); --a; --b;
		sama.join(a, b);
		printf("%d\n", (pow2[e - n + sama.compCount] + (MOD - 1)) % MOD);
	}
	return 0;
}