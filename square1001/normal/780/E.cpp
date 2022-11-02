#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, p, a, b, par[200009]; vector<int> e, g[200009];
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
void dfs(int pos, int pre) {
	for (int i : g[pos]) {
		if (i == pre) continue;
		e.push_back(pos);
		dfs(i, pos);
	}
	e.push_back(pos);
}
int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int va = root(--a);
		int vb = root(--b);
		if (va != vb) {
			par[va] = vb;
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	dfs(0, -1);
	for (int i = 0; i < p; i++) {
		int l = 1LL * i * e.size() / p, r = 1LL * (i + 1) * e.size() / p;
		printf("%d", r - l);
		for (int j = l; j < r; j++) printf(" %d", e[j] + 1); printf("\n");
	}
	return 0;
}