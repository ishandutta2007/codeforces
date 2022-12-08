#include <bits/stdc++.h>

using namespace std;

struct dt {
	int l, r, a, d;
} d[1005];

int v[1005];

void solve() {
	memset(v, 0, sizeof v);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i].l >> d[i].r;
		d[i].d = d[i].r - d[i].l;
	}
	sort(d, d + n, [&](dt &x, dt &y) {
		return x.d < y.d;
	});
	for (int i = 0; i < n; ++i) {
		for (int j = d[i].l; j <= d[i].r; ++j) {
			if (!v[j]) {
				d[i].a = j;
				v[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << d[i].l << ' ' << d[i].r << ' ' << d[i].a << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}