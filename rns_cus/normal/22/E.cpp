///	E : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 100100

int col[N], cnt, deg[N], root[N], n;
vector <int> v[N], rv[N], w[N];

void dfs(int x) {
	col[x] = cnt;
	if (!deg[x]) w[cnt].push_back(x);
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (col[y]) {
			if (!root[cnt]) root[cnt] = y;
			continue;
		}
		dfs(y);
	}
	for (int i = 0; i < rv[x].size(); i ++) {
		int y = rv[x][i];
		if (!col[y]) dfs(y);
	}
}

int main() {
//	freopen("e.in", "r", stdin);
//	freopen("e.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int j;
		scanf("%d", &j);
		v[i].push_back(j);
		rv[j].push_back(i);
	}
	for (int i = 1; i <= n; i ++) deg[i] = rv[i].size();
	for (int i = 1; i <= n; i ++) {
		if (!col[i]) cnt ++, dfs(i);
	}
	if (cnt > 1) for (int i = 1; i <= cnt; i ++) if (!w[i].size()) w[i].push_back(root[i]);
	int ans = 0;
	for (int i = 1; i <= cnt; i ++) ans += w[i].size();
	printf("%d\n", ans);
	if (!ans) return 0;
	for (int i = 1; i <= cnt; i ++) {
		for (int j = 1; j < w[i].size(); j ++) printf("%d %d\n", root[i], w[i][j]);
	}
	for (int i = 1; i <= cnt; i ++) {
		printf("%d %d\n", root[i], w[i%cnt+1][0]);
	}
	return 0;
}