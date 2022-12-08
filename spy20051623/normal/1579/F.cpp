#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], b[N];

void solve() {
	int n, d;
	scanf("%d%d", &n, &d);
	memset(b, 0, (n + 5) << 2);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	if (d == n) {
		for (int i = 0; i < n; ++i) {
			if (a[i]) {
				printf("-1\n");
				return;
			}
		}
		printf("0\n");
		return;
	}
	int k = __gcd(n, d), lim = n / k, ans = 0;
	for (int i = 0; i < k; ++i) {
		int pos = i;
		for (int j = 0; j < 2 * lim; ++j) {
			if (a[(pos + d) % n]) b[(pos + d) % n] = b[pos % n] + 1;
			if (b[(pos + d) % n] >= lim) {
				printf("-1\n");
				return;
			}
			pos = (pos + d) % n;
		}
	}
	for (int i = 0; i < n; ++i) ans = max(ans, b[i]);
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}