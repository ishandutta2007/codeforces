#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N], ans;
bool vis[N];
vector <int> v[N], w[N];
long long f[N];

void dfs(int x) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		f[y] = max(f[y], f[x] + z);
		if (f[y] > a[y]) vis[y] = 1;
		dfs(y);
	}
}

void DFS(int x) {
	if (vis[x]) return;
	ans ++;
	for (int i = 0; i < v[x].size(); i ++) DFS(v[x][i]);
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(i), w[x].push_back(y);
	}
	dfs(1);
	DFS(1);
	printf("%d\n", n - ans);
	return 0;
}