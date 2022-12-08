#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], d[N << 1];
vector<int> g[N];
int sq, n, m;

int work(int x, int p) {
	int pos = lower_bound(g[m].begin(), g[m].end(), p) - g[m].begin();
	int l = max(0, pos - sq), r = min((int) g[m].size() - 1, pos + sq);
	int pp, sum = 0, cur = 0;
	if (!l) {
		d[N] = 0;
		pp = 0;
	} else {
		d[N] = g[m][l - 1] + 1;
		pp = upper_bound(g[x].begin(), g[x].end(), g[m][l - 1]) - g[x].begin();
	}
	bool ok = false;
	int minm = 0, maxm = 0;
	for (int i = l; i <= r; ++i) {
		while (pp < g[x].size() && g[x][pp] < g[m][i]) {
			if (ok && a[g[x][pp] - 1] != x && a[g[x][pp] - 1] != m) cur = max(cur, g[x][pp] - 1 - d[sum + N]);
			ok = true;
			--sum;
			minm = min(minm, sum), maxm = max(maxm, sum);
			if (d[sum + N] == -1) d[sum + N] = g[x][pp];
			else cur = max(cur, g[x][pp] - d[sum + N]);
			++pp;
		}
		if (ok && a[g[m][i] - 1] != x && a[g[m][i] - 1] != m) cur = max(cur, g[m][i] - 1 - d[sum + N]);
		ok = true;
		++sum;
		minm = min(minm, sum), maxm = max(maxm, sum);
		if (d[sum + N] == -1) d[sum + N] = g[m][i];
		else cur = max(cur, g[m][i] - d[sum + N]);
	}
	int lim;
	if (r == g[m].size() - 1) lim = n;
	else lim = g[m][r + 1] - 1;
	while (pp < g[x].size() && g[x][pp] <= lim) {
		if (ok && a[g[x][pp] - 1] != x && a[g[x][pp] - 1] != m) cur = max(cur, g[x][pp] - 1 - d[sum + N]);
		ok = true;
		--sum;
		minm = min(minm, sum), maxm = max(maxm, sum);
		if (d[sum + N] == -1) d[sum + N] = g[x][pp];
		else cur = max(cur, g[x][pp] - d[sum + N]);
		++pp;
	}
	if (a[lim] != x && a[lim] != m) cur = max(cur, lim - d[sum + N]);
	for (int i = minm; i <= maxm; ++i) d[i + N] = -1;
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	ofstream o("in.txt");
	int num = 200000;
	o << num << endl;
	for (int i = 1; i <= num; ++i) {
		if (i & 1) o << 1 << ' ';
		else o << i << ' ';
	}
	o.close();
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g[a[i]].push_back(i);
	}
	int maxm = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) maxm = max(maxm, (int) g[i].size());
	for (int i = 1; i <= n; ++i) if (g[i].size() == maxm) ++cnt, m = i;
	if (cnt > 1) {
		printf("%d\n", n);
		return 0;
	}
	memset(d, -1, sizeof d);
	int ans = 0;
	sq = sqrt(n);
	for (int i = 1; i <= n; ++i) {
		if (i == m) continue;
		if (g[i].size() > sq) {
			d[N] = 0;
			int cur = 0;
			bool ok = false;
			for (int j = 1; j <= n; ++j) {
				if (a[j] == m) b[j] = b[j - 1] + 1;
				else if (a[j] == i) b[j] = b[j - 1] - 1;
				else b[j] = b[j - 1];
				if (b[j]) ok = true;
				if (d[b[j] + N] == -1) d[b[j] + N] = j;
				else if (ok) cur = max(cur, j - d[b[j] + N]);
			}
			ans = max(ans, cur);
			memset(d, -1, sizeof d);
		} else {
			if (g[i].empty()) continue;
			for (int pos: g[i]) ans = max(ans, work(i, pos));
		}
	}
	printf("%d\n", ans);
	return 0;
}