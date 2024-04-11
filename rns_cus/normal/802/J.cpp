#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, dp[N];
vector <int> v[N], w[N];

void dfs(int x, int p = -1) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		if (y == p) continue;
		dfs(y, x);
		dp[x] = max(dp[x], dp[y] + z);
	}
}

int main() {
//	freopen("j.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(y), w[x].push_back(z);
		v[y].push_back(x), w[y].push_back(z);
	}
	dfs(0);
	printf("%d\n", dp[0]);
	return 0;
}