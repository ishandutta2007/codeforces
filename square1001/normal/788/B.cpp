#include <set>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a, b, c[1000009], par[1000009]; bool deg[1000009];
int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }
void unite(int x, int y) { par[root(x)] = root(y); }
bool same(int x, int y) { return root(x) == root(y); }
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) par[i] = i;
	int loop = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--, b--;
		deg[a] = deg[b] = true;
		if (a == b) loop++;
		else {
			c[a]++; c[b]++;
			unite(a, b);
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (deg[i]) s.insert(root(i));
	}
	if (s.size() != 1) printf("0\n");
	else {
		long long ret = 0;
		for (int i = 0; i < n; i++) ret += 1LL * c[i] * (c[i] - 1) / 2;
		printf("%lld\n", ret + 1LL * loop * (m - loop) + 1LL * loop * (loop - 1) / 2);
	}
	return 0;
}