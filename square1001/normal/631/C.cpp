#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, q, a[200009], b[200009], t[200009], r[200009];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < q; i++) scanf("%d %d", &t[i], &r[i]);
	vector<int> g; g.push_back(q - 1);
	for (int i = q - 2; i >= 0; i--) {
		if (r[i] > r[g.back()]) {
			if (t[i] == t[g.back()]) g.back() = i;
			else g.push_back(i);
		}
	}
	sort(a, a + r[g.back()]);
	for (int i = r[g.back()]; i < n; i++) b[i] = a[i];
	int lc = 0, rc = r[g.back()];
	for (int i = g.size() - 1; i >= 1; i--) {
		if (t[g[i]] == 1) {
			for (int j = r[g[i - 1]]; j < r[g[i]]; j++) b[j] = a[rc - (r[g[i]] - j)];
			rc -= r[g[i]] - r[g[i - 1]];
		}
		else {
			for (int j = r[g[i - 1]]; j < r[g[i]]; j++) b[j] = a[lc + (r[g[i]] - j) - 1];
			lc += r[g[i]] - r[g[i - 1]];
		}
	}
	for (int i = 0; i < r[g[0]]; i++) b[i] = a[i + lc];
	if (t[g[0]] == 2) reverse(b, b + r[g[0]]);
	for (int i = 0; i < n; i++) printf("%d ", b[i]);
	return 0;
}