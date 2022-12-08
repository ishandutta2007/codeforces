#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], d[N], cnt;

int lowbit(int x) {
	return x & -x;
}

void upd(int x, int k) {
	for (int i = x; i <= cnt; i += lowbit(i)) d[i] += k;
}

int sum(int x) {
	int r = 0;
	for (int i = x; i > 0; i -= lowbit(i)) r += d[i];
	return r;
}

void solve() {
	int n;
	scanf("%d", &n);
	map<int, int> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		m[a[i]];
	}
	cnt = 0;
	for (auto &i: m) i.second = ++cnt;
	for (int i = 1; i <= n; ++i) a[i] = m[a[i]], upd(a[i], 1);
	long long ans = 0;
	for (int i = n; i >= 1; --i) {
		int l = sum(a[i] - 1), r = sum(cnt) - sum(a[i]);
		if (l > r) ans += r, upd(a[i], -1);
		else ans += l, upd(a[i], -1);
	}
	printf("%lld\n", ans);
	memset(d, 0, (cnt + 5) << 2);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}