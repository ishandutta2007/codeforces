#include <bits/stdc++.h>

using namespace std;

int pre[2005], suf[2005];

struct pt {
	int l, r;

	bool operator<(pt &o) const {
		return l + r < o.l + o.r;
	}
} p[2005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &p[i].l, &p[i].r);
		--p[i].l;
	}
	sort(p, p + m);
	for (int i = 0; i <= n; ++i) {
		int pr = 0, su = 0;
		for (int j = 0; j < m; ++j) {
			pr += max(0, min(p[j].r, i + k) - max(p[j].l, i));
			pre[j] = max(pre[j], pr);
		}
		for (int j = m - 1; j >= 0; --j) {
			su += max(0, min(p[j].r, i + k) - max(p[j].l, i));
			suf[j] = max(suf[j], su);
		}
	}
	int ans = suf[0];
	for (int i = 0; i < m; ++i) {
		ans = max(ans, pre[i] + suf[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}