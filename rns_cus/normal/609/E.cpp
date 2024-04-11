#include <bits/stdc++.h>
using namespace std;
#define N 200200
#define M 20

int n, m, a[N], b[N], c[N], id[N];
int root[N], dp[N], wei[N], fa[N][M], Max[N][M];
vector <int> v[N], w[N];
long long sum;
bool vis[N], use[N];

bool cmp(int i, int j) {return c[i] < c[j];}

int find_root(int h) {
	return root[h] == h ? h : root[h] = find_root(root[h]);
}

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		root[y] = x;
		dp[y] = dp[x] + 1;
		wei[y] = w[x][i];
		dfs(y);
	}
}

int anc(int a, int d) {
	if (!d) return a;
	int rlt = a;
	int Log = log2(d);
	for (int i = Log; i >= 0; i --) if (d & (1 << i)) rlt = fa[rlt][i];
	return rlt;
}

int lca(int a, int b) {
	int DP = 0;
	if (dp[a] > dp[b]) a = anc(a, dp[a] - dp[b]), DP = dp[b];
	else b = anc(b, dp[b] - dp[a]), DP = dp[a];
	if (a == b) return a;
	int Log = log2(DP);
	for (int i = Log; i >= 0; i --) {
		if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
	}
	return root[a];
}

int calc(int a, int d) {
	if (!d) return 0;
	int rlt = 0;
	int Log = log2(d);
	for (int i = Log; i >= 0; i --) if (d & (1 << i)) rlt = max(rlt, Max[a][i]), a = fa[a][i];
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= m; i ++) id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	for (int i = 1; i <= n; i ++) root[i] = i;
	for (int i = 1; i <= m; i ++) {
		int x = find_root(a[id[i]]), y = find_root(b[id[i]]);
        if (x == y) continue;
        use[id[i]] = 1;
        sum += c[id[i]];
        root[y] = x;
	}
	for (int i = 1; i <= m; i ++) if (use[i]) {
		v[a[i]].push_back(b[i]), w[a[i]].push_back(c[i]);
		v[b[i]].push_back(a[i]), w[b[i]].push_back(c[i]);
	}
	for (int i = 1; i <= n; i ++) root[i] = 0;
	dfs(1);
	for (int i = 1; i <= n; i ++) fa[i][0] = root[i], Max[i][0] = wei[i];
	int Log = log2(n);
	for (int j = 1; j <= Log; j ++) {
		for (int i = 1; i <= n; i ++) {
			fa[i][j] = fa[fa[i][j-1]][j-1];
			Max[i][j] = max(Max[i][j-1], Max[fa[i][j-1]][j-1]);
		}
	}
	for (int i = 1; i <= m; i ++) {
		if (use[i]) {
			printf("%I64d\n", sum); continue;
		}
		int x = lca(a[i], b[i]);
		long long ans = max(calc(a[i], dp[a[i]] - dp[x]), calc(b[i], dp[b[i]] - dp[x]));
		printf("%I64d\n", sum - ans + c[i]);
	}
	return 0;
}