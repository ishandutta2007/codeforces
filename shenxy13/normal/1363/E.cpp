#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, b[200000], c[200000], z[200000];
long long a[200000], ans = 0;
vector<int> adjlist[200000];
void dfs1(int v, int p, long long minA) {
	a[v] = minA = min(minA, a[v]);
	z[v] = b[v] - c[v];
	for (int i: adjlist[v]) {
		if (i == p) continue;
		dfs1(i, v, minA);
		z[v] += z[i];
	}
}
int solve(int v, int p) {
	int sol = b[v] != c[v];
	for (int i: adjlist[v]) {
		if (i != p) sol += solve(i, v);
	}
	ans += a[v] * (sol - abs(z[v]));
	return abs(z[v]);
}
int main() {
	int u, v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld %d %d", &a[i], &b[i], &c[i]);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		adjlist[u - 1].push_back(v - 1);
		adjlist[v - 1].push_back(u - 1);
	}
	dfs1(0, -1, 1000000001);
	if (solve(0, -1)) printf("-1");
	else printf("%lld", ans);
	return 0;
}