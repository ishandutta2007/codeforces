#include <bits/stdc++.h>
using namespace std;

#define N 303030

int a[N];
vector <int> v[N];
vector <int> id[N];

int cnt[N], d[N], q[N];

bool vis[N];

pair <int, int> p[N];

int main() {
	//freopen("r.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i]);
	for (int i = 1, x, y; i <= m; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		id[x].push_back(i);
		v[y].push_back(x);
		id[y].push_back(i);
	}
	bool flag = 0;
	int dd = 0;
	for (int i = 1; i <= n && !flag; i ++) {
		if (d[i] == -1) flag = 1;
		else dd += d[i];
	}
	if (!flag && (dd % 2) == 1) {
		puts("-1");
		return 0;
	}
	int rt = 1;
	for (int i = 1; i <= n; i ++) {
		if (d[i] == -1) {
			rt = i;
			break;
		}
	}
	int e = 0;
	q[++e] = rt;
	vis[rt] = 1;
	p[rt] = make_pair(0, 0);
	for (int f = 1; f <= e; f ++) {
		int now = q[f];
		for (int i = 0, cur; i < v[now].size(); i ++) {
			cur = v[now][i];
			if (vis[cur]) continue;
			q[++e] = cur;
			vis[cur] = 1;
			p[cur] = make_pair(now, id[now][i]);
		}
	}
	vector <int> ans;
	for (int i = e; i >= 1; i --) {
		if (d[q[i]] != -1 && d[q[i]] % 2 != cnt[q[i]] % 2) {
			ans.push_back(p[q[i]].second);
			cnt[p[q[i]].first] ++;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) printf("%d%c", ans[i], (i == (int)(ans.size()) - 1) ? '\n' : ' ');

	return 0;
}