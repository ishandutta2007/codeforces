#include <cstdio>
int n, m, a[150009], b[150009], par[150009], c[150009], s[150009];
int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }
void unite(int x, int y) { par[root(x)] = root(y); }
bool same(int x, int y) { return root(x) == root(y); }
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		unite(a[i], b[i]);
	}
	for (int i = 0; i < n; i++) s[root(i)]++;
	for (int i = 0; i < m; i++) c[root(a[i])]++;
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (c[i] != 1LL * s[i] * (s[i] - 1) / 2) f = false;
	}
	printf(f ? "YES\n" : "NO\n");
	return 0;
}