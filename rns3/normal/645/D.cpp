#include <bits/stdc++.h>
using namespace std;
#define M 200010
int n, m, x[M], y[M], deg[M];
vector <int> con[M];

bool check(int cnt) {
	for (int i = 1; i <= n; i++) con[i].clear(), deg[i] = 0;
	for (int i = 1; i <= cnt; i++) {
		con[x[i]].push_back(y[i]); deg[y[i]]++;
	}
	cnt = 0;
	queue <int> q;
	for (int i = 1; i <= n; i ++) if (!deg[i]) q.push(i), cnt++;
	if (cnt > 1) return 0;
	while (!q.empty()) {
		int j = q.front(); q.pop();
		cnt = 0;
		for (int i = 0; i < con[j].size(); i ++) {
			int k = con[j][i];
			deg[k] --;
			if (!deg[k]) q.push(k), cnt++;
		}
		if (cnt > 1) return 0;
	}
	return 1;
}

int main() {
//freopen("D.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d %d", &x[i], &y[i]);
	int l = 0, r = m;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid;
	}
	if (l == m) puts("-1");
	else printf("%d\n", l + 1);
}