#include <bits/stdc++.h>
using namespace std;

#define N 202020

int n, m;

int x[N], y[N], w[N];
bool chk[N];

vector <int> v[N];

bool cmp(int i, int j) {
	return w[i] < w[j];
}

int root[N];

void init(int n) {
	for (int i = 1; i <= n; i ++) root[i] = i;
}

int find_root(int h) {
	return h == root[h] ? h : root[h] = find_root(root[h]);
}

int fa[N], we[N], dp[N];

void dfs(int a, int c, int cost, int depth) {
	fa[a] = c;
	we[a] = cost;
	dp[a] = depth;
	for (int i = 0, b; i < v[a].size(); i ++) {
		b = x[v[a][i]] + y[v[a][i]] - a;
		if (b == c) continue;
		dfs(b, a, w[v[a][i]], depth + 1);
	}
}

const int K = 17;

int f[N][K], d[N][K];

void prep() {
	for (int i = 1; i <= n; i ++) f[i][0] = fa[i], d[i][0] = we[i];
	for (int k = 0; k < K - 1; k ++)
		for (int i = 1; i <= n; i ++)
			f[i][k+1] = f[f[i][k]][k], d[i][k+1] = max(d[f[i][k]][k], d[i][k]);
}

int calc(int x, int y) {
	int rlt = 0;
	if (dp[x] < dp[y]) swap(x, y);
	for (int k = K - 1; k >= 0; k --) {
		if (dp[x] >= dp[y] + (1 << k)) {
			rlt = max(rlt, d[x][k]);
			x = f[x][k];
		}
	}
	if (x == y) return rlt;
	for (int k = K - 1; k >= 0; k --) {
		if (f[x][k] != f[y][k]) {
			rlt = max(rlt, d[x][k]);
			x = f[x][k];
			rlt = max(rlt, d[y][k]);
			y = f[y][k];
		}
	}
	rlt = max(rlt, d[x][0]);
	x = f[x][0];
	rlt = max(rlt, d[y][0]);
	y = f[y][0];
	return rlt;
}

int id[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d %d %d", &x[i], &y[i], &w[i]), id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	long long tot = 0;
	init(n);
	for (int j = 1, X, Y, i; j <= m; j ++) {
		i = id[j];
		X = find_root(x[i]), Y = find_root(y[i]);
		if (X == Y) continue;
		tot += w[i];
		root[Y] = X;
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
		chk[i] = 1;
	}
	dfs(1, 0, 0, 0);
	prep();
	long long ans;
	for (int i = 1; i <= m; i ++) {
		if (chk[i]) ans = tot;
		else ans = tot + w[i] - calc(x[i], y[i]);
		printf("%I64d\n", ans);
	}


	return 0;
}