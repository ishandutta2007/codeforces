#include <bits/stdc++.h>

using namespace std;

int a[500005], b[500005], sa[500005], sb[500005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n, greater<int>());
	for (int i = 1; i <= n; ++i) {
		sa[i] = sa[i - 1] + a[i];
		sb[i] = sb[i - 1] + b[i];
	}
	int s, d = 0;
	while (s = n / 4, sa[n] - sa[s] < sb[n - s]) {
		++d, ++n;
		a[n] = 100;
		sa[n] = sa[n - 1] + 100;
		b[n] = 0;
		sb[n] = sb[n - 1];
	}
	printf("%d\n", d);
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