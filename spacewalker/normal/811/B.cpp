#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {

	int n, m; scanf("%d %d", &n, &m);
	vector<int> p(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}

	for (int q = 0; q < m; ++q) {
		int l, r, xi; scanf("%d %d %d", &l, &r, &xi);
		--l; --r; --xi;
		int occur = 0;
		for (int i = l; i <= r; ++i) {
			if (p[i] < p[xi]) {
				++occur;
			}
		}

		printf("%s\n", (occur == xi - l ? "Yes" : "No"));
	}

	return 0;
}