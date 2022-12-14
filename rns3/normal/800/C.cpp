#include <bits/stdc++.h>
using namespace std;

#define N 202020

int n, m, d[N], c[N], go[N];
bool vis[N];

vector <int> v[N];
vector <int> q[N];

int ans[N], link[N];

void dfs(int x) {
	if (v[x].size() == 0) {
		ans[x] = q[x].size();
		return;
	}
	ans[x] = q[x].size();
	for (int i = 0, y; i < v[x].size(); i ++) {
		y = v[x][i];
		dfs(y);
		if (ans[x] < q[x].size() + ans[y]) link[x] = y, ans[x] = q[x].size() + ans[y];
	}
}

int r[N], a[N], b[N];

int extended_euclid(int a, int b, int &x, int &y) {
	if (!b) {x = 1, y = 0; return a;}
	int rlt = extended_euclid(b, a % b, y, x);
	y -= (a / b) * x;
	return rlt;
}


int calc(int a, int b) {
	int x, y, d = extended_euclid(a, m, x, y);
	if (b % d) return -1;
	return (1ll * x * (b / d) % m + m) % m;
}


int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1, a; i <= n; i ++) scanf("%d", &a), vis[a] = 1;
	int e = 0;
	for (int i = 1; i <= m; i ++) if (m % i == 0) c[++e] = i, go[i] = e;
	for (int i = 1; i <= e; i ++) for (int j = i + 1; j <= e; j ++) if (c[j] % c[i] == 0) v[j].push_back(i);
	for (int i = 0; i < m; i ++) {
		d[i] = __gcd(i, m);
		if (!vis[i]) q[go[d[i]]].push_back(i);
	}
	dfs(e);
	int gas = 0;
	for (int x = e; x; x = link[x]) r[++gas] = x;
	int cnt = 0;
	for (int k = gas; k >= 1; k --) for (int i = 0; i < q[r[k]].size(); i ++) a[++cnt] = q[r[k]][i];
	int old = 1;
	for (int i = 1; i <= cnt; i ++) {
		b[i] = calc(old, a[i]);
		old = a[i];
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++) printf("%d ", b[i]);

	return 0;
}