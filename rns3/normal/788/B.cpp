#include <bits/stdc++.h>
using namespace std;

#define N 1010101

int n, m;
vector <int> v[N];

bool vis[N], di[N];
int q[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int i = 1, x, y; i <= m; i ++) {
		scanf("%d %d", &x, &y);
		di[x] = di[y] = 1;
		if (x == y) cnt ++;
		else v[x].push_back(y), v[y].push_back(x);
	}
	int rt = 1;
	while (!di[rt]) rt ++;
	int e = 0;
	vis[rt] = 1;
	q[++e] = rt;
	for (int f = 1; f <= e; f ++) {
		int x = q[f];
		for (int i = 0, y; i < v[x].size(); i ++) {
			y = v[x][i];
			if (vis[y]) continue;
			q[++e] = y;
			vis[y] = 1;
		}
	}
	bool flag = 1;
	for (int i = 1; i <= n; i ++) if (!vis[i] && di[i]) flag = 0;
	if (!flag) {
		puts("0");
		return 0;
	}
	long long ans = 0;
	ans += 1ll * cnt * (cnt - 1) / 2;
	ans += 1ll * cnt * (m - cnt);
	for (int i = 1; i <= n; i ++) ans += 1ll * v[i].size() * (v[i].size() - 1) / 2;
	printf("%I64d\n", ans);

	return 0;
}