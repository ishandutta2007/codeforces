#include <bits/stdc++.h>
using namespace std;

#define N 202

bool vis[N], col[N];
vector <int> v[N];
queue <int> q;
int n, dp[N];
pair <int, int> edge[N];

void clr(bool* a, int n) {
	for (int i = 0; i <= n; i ++) a[i] = 0;
}

void get_col(int x) {
	vis[x] = 1; col[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i]]) get_col(v[x][i]);
}

int bfs(int x) {
	while (!q.empty()) q.pop();
	q.push(x); vis[x] = 1; dp[x] = 0;
	int rlt = 0;
	while (!q.empty()) {
		x = q.front(); q.pop();
		rlt = dp[x];
		for (int i = 0; i < v[x].size(); i ++) {
			if (vis[v[x][i]]) continue;
			dp[v[x][i]] = dp[x] + 1;
			q.push(v[x][i]); vis[x] = 1;
		}
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) scanf("%d %d", &edge[i].first, &edge[i].second);
	int ans = 0;
	for (int k = 1; k < n; k ++) {
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 1; i < n; i ++) if (i != k) {
			int a = edge[i].first, b = edge[i].second;
			v[a].push_back(b); v[b].push_back(a);
		}
		clr(vis, n);
		clr(col, n);
		get_col(1);
		int A = 0, B = 0;
		for (int i = 1; i <= n; i ++) {
			clr(vis, n);
			if (col[i]) A = max(A, bfs(i));
			else B = max(B, bfs(i));
		}
		ans = max(ans, A * B);
	}
	printf("%d\n", ans);
	return 0;
}