#include <bits/stdc++.h>

using namespace std;

struct dt {
	int a, b, m, aa, bb;
} d[200005];

struct seg {
	int l, r, id;
};

vector<seg> v[2000005];
set<int> s;

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].m);
		v[d[i].a + d[i].b - d[i].m].push_back(
				seg{d[i].m > d[i].a ? 0 : d[i].a - d[i].m, d[i].m > d[i].b ? d[i].a + d[i].b - d[i].m : d[i].a, i});
		s.insert(d[i].a + d[i].b - d[i].m);
	}
	int ans = 0;
	for (int i: s) {
		sort(v[i].begin(), v[i].end(), [&](seg &x, seg &y) { return x.l < y.l; });
		int l = -1, r = -1;
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j].l > r) {
				if (l != -1) {
					for (int k = l; k <= j; ++k) {
						d[v[i][k].id].aa = d[v[i][k].id].a - r;
						d[v[i][k].id].bb = d[v[i][k].id].m - d[v[i][k].id].aa;
					}
				}
				++ans;
				l = j;
				r = v[i][j].r;
			} else {
				r = min(r, v[i][j].r);
			}
		}
		if (l != -1) {
			for (int k = l; k < v[i].size(); ++k) {
				d[v[i][k].id].aa = d[v[i][k].id].a - r;
				d[v[i][k].id].bb = d[v[i][k].id].m - d[v[i][k].id].aa;
			}
		}
		v[i].clear();
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", d[i].aa, d[i].bb);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}