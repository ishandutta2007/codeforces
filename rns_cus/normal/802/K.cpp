#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, k, dp[N];
vector <int> v[N], w[N];

void dfs(int x, int p = -1) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		if (y == p) continue;
		dfs(y, x);
		dp[x] = max(dp[x], dp[y] + z);
	}
}

int f[N], g[N], a[N], b[N], c[N], sum[N];

void DFS(int x, int p = -1) {
	vector <int> F, G;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		if (y == p) continue;
		DFS(y, x);
		F.push_back(f[y] + z);
		G.push_back(g[y] - f[y]);
	}
	int sz = F.size();
	for (int i = 1; i <= sz; i ++) a[i] = F[i-1];
	for (int i = 1; i <= sz; i ++) b[i] = G[i-1];
	for (int i = 1; i <= sz; i ++) c[i] = a[i];
	sort(c + 1, c + sz + 1);
	reverse(c + 1, c + sz + 1);
	sum[0] = 0;
	for (int i = 1; i <= sz; i ++) sum[i] = sum[i-1] + c[i];
	f[x] = sum[min(sz,k-1)];
	int rlt = 0;
	for (int i = 1; i <= sz; i ++) {
		int st = 1, en = sz + 1;
		while (en - st > 1) {
			int mid = st + en >> 1;
			if (c[mid] >= a[i]) st = mid;
			else en = mid;
		}
		if (st >= k) rlt = max(rlt, sum[k-1] + a[i] + b[i]);
		else rlt = max(rlt, sum[min(sz,k)] + b[i]);
	}
	g[x] = rlt;
}

int main() {
//	freopen("k.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i ++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(y), w[x].push_back(z);
		v[y].push_back(x), w[y].push_back(z);
	}
	if (k == 1) {
		dfs(0);
		printf("%d\n", dp[0]);
		return 0;
	}
	DFS(0);
//	for (int i = 0; i < n; i ++) printf("%d ", f[i]); puts("");
//	for (int i = 0; i < n; i ++) printf("%d ", g[i]); puts("");
	printf("%d\n", g[0]);
	return 0;
}