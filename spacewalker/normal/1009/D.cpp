#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	// printf("gcd check %d %d\n", a,b);
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	if (m < n - 1) {printf("Impossible\n"); return 0;}
	// m -= (n - 1);
	vector<pair<int, int>> edges;
	for (int i = 1; i < n; ++i) {
		--m;
		edges.emplace_back(1, i + 1);
	}
	for (int i = 2; i <= n and m > 0; ++i) {
		for (int j = 2; j < i and m > 0; ++j) {
			// printf("checking %d %d\n", i, j);
			if (gcd(i, j) == 1) {
				// printf("succ\n");
				--m;
				edges.emplace_back(i, j);
			}
		}
	}
	if (m > 0) printf("Impossible\n");
	else {
		printf("Possible\n");
		for (auto e : edges) printf("%d %d\n", e.first, e.second);
	}
	return 0;
}