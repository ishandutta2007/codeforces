#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
int fa[N], st[N];
vector<int> g[N], s[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool dfs(int id, int p, int x, int f) {
	if (p == x) {
		s[id].push_back(p);
		return true;
	}
	for (int i: g[p]) {
		if (i != f) {
			if (dfs(id, i, x, p)) {
				st[i] ^= 1;
				st[p] ^= 1;
				s[id].push_back(p);
				return true;
			}
		}
	}
	return false;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (find(x) != find(y)) {
			g[x].push_back(y);
			g[y].push_back(x);
			fa[find(y)] = find(x);
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		dfs(i, y, x, 0);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += st[i];
	if (cnt) {
		puts("NO");
		printf("%d\n", cnt / 2);
		return 0;
	}
	puts("YES");
	for (int i = 0; i < q; ++i) {
		printf("%d\n", s[i].size());
		for (int j: s[i]) printf("%d ", j);
		puts("");
	}
	return 0;
}