#include <bits/stdc++.h>
using namespace std;

#define N 202

int n, k, m, a, id[N], ans[N];
vector <int> v[N];

bool cmp(int i, int j) {
	if (v[i].size() != v[j].size()) return v[i].size() > v[j].size();
	return !v[i].empty() && *v[i].rbegin() < *v[j].rbegin();
}

int main() {
//	freopen("f.in", "r", stdin);
	scanf("%d %d %d %d", &n, &k, &m, &a);
	for (int i = 1, x; i <= a; i ++) scanf("%d", &x), v[x].push_back(i);
	if (n == 1) return puts("1"), 0;
	for (int i = 1; i <= n; i ++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i ++) {
		ans[id[i]] = 1;
		if (v[id[i]].size() > 0) {
			if (k == n) continue;
			int need = 0;
			int to = min(n, i <= k ? k + 1 : k);
			for (int j = i + 1; j <= to; j ++) {
				need += v[id[i]].size() - v[id[j]].size() + 1;
			}
			if (need > m - a) continue;
		}
		vector <int> cur = v[id[i]];
		for (int j = a + 1; j <= m; j ++) cur.push_back(j);
		swap(cur, v[id[i]]);
		int kill = 0;
		for (int j = 1; j <= n; j ++) if (j != i && cmp(id[i], id[j])) kill ++;
		if (!v[id[i]].empty() && kill >= n - k) ans[id[i]] = 2;
		else ans[id[i]] = 3;
		swap(cur, v[id[i]]);
	}
	for (int i = 1; i <= n; i ++) printf("%d%c", ans[i], i < n ? ' ' : '\n');
	return 0;
}