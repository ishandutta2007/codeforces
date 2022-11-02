#include <cstdio>
int n, c, a, q, v[200009]; bool vis[200009];
bool solve(int x) {
	for (int i = 0; i < n; i++) vis[i] = false;
	for (int i = 0; i < x; i++) vis[v[i] - 1] = true;
	int l = 0, ret = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || vis[i]) {
			ret += (i - l + 1) / (a + 1);
			l = i + 1;
		}
	}
	return ret >= c;
}
int main() {
	scanf("%d %d %d %d", &n, &c, &a, &q);
	for (int i = 0; i < q; i++) scanf("%d", &v[i]);
	int l = 0, r = q + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (solve(m)) l = m;
		else r = m;
	}
	printf(l == q ? "-1\n" : "%d\n", l + 1);
	return 0;
}