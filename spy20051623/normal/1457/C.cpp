#include <bits/stdc++.h>

using namespace std;

int a[100005];
int c[200005];

void solve() {
	int n, p, k, x, y, sss;
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 0; i < p - 1; ++i) {
		scanf("%1d", &sss);
	}
	n -= p - 1;
	for (int i = 0; i < n; ++i) {
		scanf("%1d", &a[i]);
	}
	scanf("%d%d", &x, &y);
	memset(c, 0, sizeof c);
	for (int i = n - 1; i >= 0; --i) {
		c[i] = c[i + k];
		if (!a[i])
			++c[i];
	}
	long long res = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		res = min(res, 1LL * x * c[i] + 1LL * y * i);
	}
	printf("%lld\n", res);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}