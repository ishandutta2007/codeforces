#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, q, l[100009], r[100009], p[100009]; bool ans[100009]; vector<int> query[100009];
int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int> > v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l[i], &r[i]); l[i]--; r[i]--;
		query[r[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (i >= 1) {
			for (int j = 0; j < m; j++) {
				if (v[i - 1][j] > v[i][j]) p[j] = i;
			}
		}
		int z = *min_element(p, p + m);
		for (int j : query[i]) {
			if (l[j] >= z) ans[j] = true;
		}
	}
	for (int i = 0; i < q; i++) puts(ans[i] ? "Yes" : "No");
	return 0;
}