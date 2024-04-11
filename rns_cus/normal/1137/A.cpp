#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define pb push_back

int n, m, a[N][N], szr[N], szc[N];
vector <int> r[N], c[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) r[i].pb(a[i][j]);
		sort(r[i].begin(), r[i].end());
		szr[i] = unique(r[i].begin(), r[i].end()) - r[i].begin();
		while (r[i].size() > szr[i]) r[i].pop_back();
	}
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) c[i].pb(a[j][i]);
		sort(c[i].begin(), c[i].end());
		szc[i] = unique(c[i].begin(), c[i].end()) - c[i].begin();
		while (c[i].size() > szc[i]) c[i].pop_back();
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int x = szr[i], y = szc[j];
			int k = lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
			int l = lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
			if (k < l) x += l - k;
			else y += k - l;
			printf("%d ", max(x, y));
		}
		puts("");
	}

	return 0;
}