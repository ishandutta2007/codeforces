#include <bits/stdc++.h>

using namespace std;

long long c[6];
int vis[6];

void solve() {
	long long x, y;
	scanf("%lld%lld", &x, &y);
	for (long long &i: c) scanf("%lld", &i);
	for (int t = 0; t < 6; ++t) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < 6; ++i) {
			int mn = -1;
			for (int j = 0; j < 6; ++j) {
				if (!vis[j] && (mn == -1 || c[j] < c[mn])) mn = j;
			}
			vis[mn] = 1;
			c[(mn + 5) % 6] = min(c[(mn + 5) % 6], c[mn] + c[(mn + 4) % 6]);
			c[(mn + 1) % 6] = min(c[(mn + 1) % 6], c[mn] + c[(mn + 2) % 6]);
		}
	}
	if (x >= 0 && y >= 0 && x < y) printf("%lld\n", x * c[0] + (y - x) * c[1]);
	if (x < 0 && y >= 0) printf("%lld\n", y * c[1] - x * c[2]);
	if (x < 0 && y < 0 && x < y) printf("%lld\n", (y - x) * c[2] - y * c[3]);
	if (x < 0 && y < 0 && x >= y) printf("%lld\n", -x * c[3] + (x - y) * c[4]);
	if (x >= 0 && y < 0) printf("%lld\n", -y * c[4] + x * c[5]);
	if (x >= 0 && y >= 0 && x >= y) printf("%lld\n", (x - y) * c[5] + y * c[0]);
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