#include <bits/stdc++.h>

using namespace std;

int fa[200005];
int r[200005];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int link(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y)swap(x, y);
	fa[y] = x;
	r[x] = max(r[x], r[y]);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fa[i] = r[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (find(x) != find(y))link(x, y);
	}
	int ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (!cur) {
			cur = i;
			while (cur != fa[cur])cur = fa[cur];
		} else {
			if (find(i) != find(cur)) {
				link(i, cur);
				++ans;
			}
		}
		if (i == r[cur])cur = 0;
	}
	printf("%d\n", ans);
	return 0;
}