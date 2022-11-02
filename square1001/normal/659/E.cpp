#include <cstdio>
int n, m, a, b[100008], par[100008], s[100008], c[100008];
int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }
void unite(int x, int y) { par[root(x)] = root(y); }
bool same(int x, int y) { return root(x) == root(y); }
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < m; i++) scanf("%d %d", &a, &b[i]), unite(--a, --b[i]);
	for (int i = 0; i < n; i++) s[root(i)]++;
	for (int i = 0; i < m; i++) c[root(b[i])]++;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] > c[i]) ret++;
	}
	printf("%d\n", ret);
	return 0;
}