#include <bits/stdc++.h>
using namespace std;

#define N 202020

vector <int> v[N];

int sz[N], dp[N];

void dfs(int x, int y) {
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int z = v[x][i];
		if (y == z) continue;
		dp[z] = dp[x] + 1;
		dfs(z, x);
		sz[x] += sz[z];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	long long ans = 0;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i ++) {
		if (dp[i] & 1) a ++;
		else b ++;
	}
	ans += 1ll * a * b;
	for (int i = 2; i <= n; i ++) {
		ans += 1ll * sz[i] * (n - sz[i]);
	}
	printf("%I64d\n", ans / 2);

	return 0;
}