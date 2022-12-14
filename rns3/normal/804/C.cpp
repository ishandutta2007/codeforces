#include <bits/stdc++.h>
using namespace std;

#define N 303030

int n;

int s[N];
vector <int> v[N], u[N];
int col[N];
bool vis[N];
int q[N];

int c[N], id[N];

int main() {
	//freopen("r.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &s[i]);
		u[i].resize(s[i]);
		for (int j = 0; j < s[i]; j ++) scanf("%d", &u[i][j]);
	}
	for (int i = 1, x, y; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0, rt = -1;
	for (int i = 1; i <= n; i ++) if (s[i] > ans) {
		rt = i, ans = s[i];
	}
	ans = max(ans, 1);
	for (int j = 0; j < s[rt]; j ++) col[u[rt][j]] = j + 1;
	int e = 0;
	vis[rt] = 1;
	q[++e] = rt;
	int cnt, cntt;
	for (int f = 1; f <= e; f ++) {
		int x = q[f];
		for (int i = 0, y; i < v[x].size(); i ++) {
			y = v[x][i];
			if (vis[y]) continue;
			cnt = 0;
			cntt = 0;
			for (int j = 0, z; j < u[y].size(); j ++) {
				z = u[y][j];
				if (col[z]) c[++cnt] = col[z];
				else id[++cntt] = z;
			}
			sort(c + 1, c + cnt + 1);
			int now = 1;
			for (int j = 1, i = 1; j <= cntt; j ++) {
				while (i <= cnt && now == c[i]) {
					while (i <= cnt && now == c[i]) i ++;
					now ++;
				}
				col[id[j]] = now;
				now ++;
			}
			q[++e] = y;
			vis[y] = 1;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= m; i ++) printf("%d ", max(1, col[i]));
	puts("");

	return 0;
}