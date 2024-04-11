#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, c, z, p[500009], imos[2000009]; vector<int> w[500009];
void dfs(int d, int l, int r) {
	z++;
	while (l < r && p[l] == d) l++;
	if (l == r) {
		z--;
		return;
	}
	for (int i = l; i < r; i++) {
		if (p[i] == d) return;
	}
	int cnt = 0;
	for (int i = l + 1; i < r; i++) {
		if (w[i - 1][d] > w[i][d]) cnt++;
	}
	if (cnt >= 2) return;
	int pl = c - w[l][d], pr = 2 * c - w[r - 1][d];
	if (cnt == 1) {
		pr -= c;
		if (pl >= pr) return;
	}
	imos[pl]++; imos[pr]--;
	int pre = l;
	for (int i = l + 1; i <= r; i++) {
		if (i == r || w[i][d] != w[i - 1][d]) {
			dfs(d + 1, pre, i);
			pre = i;
		}
	}
}
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]); w[i].resize(p[i]);
		for (int j = 0; j < p[i]; j++) scanf("%d", &w[i][j]), w[i][j]--;
	}
	dfs(0, 0, n);
	for (int i = 1; i <= 2 * c; i++) imos[i] += imos[i - 1];
	bool f = false;
	for (int i = 0; i < c; i++) {
		imos[i] += imos[i + c];
		if (imos[i] == z) {
			printf("%d\n", i);
			f = true;
			break;
		}
	}
	if (!f) printf("-1\n");
	return 0;
}