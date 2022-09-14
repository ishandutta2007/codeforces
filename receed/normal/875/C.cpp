#include <bits/stdc++.h>

using namespace std;

int c[100001], used[100001];
vector<pair<int, int>> g[100001];

int dfs(int v) {
	used[v] = 1;
	for (auto u : g[v]) {
		if (c[v] != u.second)
			continue;
		if (c[u.first] != 0 && c[u.first] != c[v])
			return 1;
		c[u.first] = c[v];
		if (!used[u.first] && dfs(u.first))
			return 1;
	}
	return 0;
}

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, t;
	scanf("%d%d", &n, &m);
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		a[i].resize(t);
		for (int j = 0; j < t; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < n - 1; i++) {
        bool flag = 1;
		for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
			if (a[i][j] < a[i + 1][j]) {
				g[a[i][j]].push_back({a[i + 1][j], 1});
                g[a[i + 1][j]].push_back({a[i][j], 2});
                flag = 0;
				break;
            }
			else if (a[i][j] > a[i + 1][j]) {
				if (c[a[i][j]] == 1 || c[a[i + 1][j]] == 2) {
					printf("No\n");
					return 0;
				}
				c[a[i][j]] = 2;
                c[a[i + 1][j]] = 1;
                flag = 0;
				break;
			}
        }
        if (flag == 1 && a[i].size() > a[i + 1].size()) {
            printf("No\n");
					return 0;
        }
	}
	for (int i = 1; i <= m; i++) {
		if (used[i] || c[i] == 0)
			continue;
		if (dfs(i)) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans += (c[i] == 2);
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++)
		if (c[i] == 2)
			printf("%d ", i);
}