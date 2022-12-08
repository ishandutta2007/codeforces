#include <bits/stdc++.h>

using namespace std;

int fa[5][1005];

int find(int x, int y) {
	return fa[y][x] == x ? x : fa[y][x] = find(fa[y][x], y);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m1, m2;
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			fa[i][j] = j;
		}
	}
	while (m1--) {
		int x, y;
		scanf("%d%d", &x, &y);
		fa[0][find(y, 0)] = find(x, 0);
	}
	while (m2--) {
		int x, y;
		scanf("%d%d", &x, &y);
		fa[1][find(y, 1)] = find(x, 1);
	}
	int ans = 0;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (find(i, 0) != find(j, 0) && find(i, 1) != find(j, 1)) {
				++ans;
				fa[0][find(j, 0)] = find(i, 0);
				fa[1][find(j, 1)] = find(i, 1);
				v.emplace_back(i, j);
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; ++i) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}