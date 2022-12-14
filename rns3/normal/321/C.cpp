#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, son[N], mx[N], nodes, node[N], col[N];
vector <int> v[N];
bool del[N], vis[N];

void dfs(int x) {
	node[++nodes] = x;
	vis[x] = 1;
	son[x] = 1, mx[x] = 0;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		dfs(y);
		son[x] += son[y];
		mx[x] = max(mx[x], son[y]);
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int C = 'A'; C <= 'Z'; C ++) {
		memcpy(vis, del, sizeof vis);
		int cnt = 0;
		for (int i = 1; i <= n; i ++) if (!vis[i]) {
			nodes = 0;
			dfs(i);
			int mn = n, rt = 0;
			for (int j = 1; j <= nodes; j ++) {
				mx[node[j]] = max(mx[node[j]], nodes - son[node[j]]);
				if (mx[node[j]] < mn) mn = mx[node[j]], rt = node[j];
			}
			del[rt] = 1, col[rt] = C;
			cnt ++;
		}
		if (!cnt) break;
	}
	for (int i = 1; i <= n; i ++) printf("%c%c", col[i], i < n ? ' ' : '\n');
	return 0;
}