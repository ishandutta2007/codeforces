#include <bits/stdc++.h>
using namespace std;

#define N 3010

int n, m, k, root[N], c[N], x, y;
int sz[N], ans, mx, id, t;

int find_root(int x) {
	if (x == root[x]) return x;
	return root[x] = find_root(root[x]);
}

int main() {	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i ++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i ++) root[i] = i;
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &x, &y);
		root[find_root(x)] = find_root(y);
	}
	for (int i = 1; i <= n; i ++) sz[find_root(i)] ++;
	for (int i = 1; i <= k; i ++) {
		if (mx < sz[find_root(c[i])]) {
			mx = sz[find_root(c[i])];
			id = i;
		}
	}
	ans = -m;
	t = n;
	for (int i = 1; i <= n; i ++) {
		if (i != id) {
			ans += (sz[find_root(c[i])] - 1) * sz[find_root(c[i])] / 2;
			t -= sz[find_root(c[i])];
		}
	}
	ans += t * (t - 1) / 2;
	printf("%d", ans);
}