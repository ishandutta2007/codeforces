#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005];

long long c2(int n) {
	return 1ll * n * (n - 1) / 2;
}

long long c3(int n) {
	return 1ll * n * (n - 1) * (n - 2) / 6;
}

void solve() {
	int n;
	scanf("%d", &n);
	unordered_map<int, int> p, q;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		++p[a[i]], ++q[b[i]];
	}
	long long ans = c3(n);
//	for (auto &i: p) {
//		ans -= c2(i.second) * (n - i.second) + c3(i.second);
//	}
//	for (auto &i: q) {
//		ans -= c2(i.second) * (n - i.second) + c3(i.second);
//	}
	for (int i = 0; i < n; ++i) {
		ans -= 1ll * (p[a[i]] - 1) * (q[b[i]] - 1);
	}
	printf("%lld\n", ans);
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