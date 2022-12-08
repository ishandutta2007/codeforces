#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	long long sum = 0, sa = 0, sb = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		sum += a[i] + b[i];
	}
	long long md = (sum - 1ll * n * m) / 2;
	for (int i = 0; i < n; ++i) {
		if (b[i] < m) sa += a[i] + b[i] - m;
		else sa += a[i];
		if (a[i] < m) sb += a[i] + b[i] - m;
		else sb += b[i];
	}
	if (sa < md) {
		printf("%lld\n", sum - 1ll * n * m - sa - sa);
		for (int i = 0; i < n; ++i) {
			if (b[i] < m) printf("%d %d\n", m - b[i], b[i]);
			else printf("%d %d\n", 0, m);
		}
	} else if (sb < md) {
		printf("%lld\n", sum - 1ll * n * m - sb - sb);
		for (int i = 0; i < n; ++i) {
			if (a[i] < m) printf("%d %d\n", a[i], m - a[i]);
			else printf("%d %d\n", m, 0);
		}
	} else {
		printf("%lld\n", sum - 1ll * n * m & 1);
		sa = md, sb = sum - 1ll * n * m - md;
		for (int i = 0; i < n; ++i) {
			int ma = max(0, a[i] - m), mb = max(0, b[i] - m);
			sa -= ma, sb -= mb;
		}
		for (int i = 0; i < n; ++i) {
			int ma = max(0, a[i] - m), mb = max(0, b[i] - m);
			a[i] -= ma, b[i] -= mb;
			int da = max(1ll * m - b[i], a[i] - min(1ll * a[i], sa)), db = m - da;
			printf("%d %d\n", da, db);
			sa -= a[i] - da, sb -= b[i] - db;
		}
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