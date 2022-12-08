#include <bits/stdc++.h>

using namespace std;

long long a[200005];
long long d[200005];
long long n, l, r;
map<long long, int> m;

int lowbit(int x) {
	return x & -x;
}

void upd(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i))
		d[i] += k;
}

long long sum(int x) {
	long long res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		res += d[i];
	return res;
}

void solve() {
	m.clear();
	memset(d, 0, sizeof d);
	m[-1];
	scanf("%lld%lld%lld", &n, &l, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		m[a[i]];
	}
	int k = 0;
	for (auto &i : m) {
		i.second = k++;
	}
	long long minm = 0x7fffffff, maxm = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] + minm <= r && a[i] + maxm >= l) {
			auto it1 = --m.lower_bound(l - a[i]);
			auto it2 = --m.upper_bound(r - a[i]);
			ans += sum(it2->second) - sum(it1->second);
		}
		upd(m[a[i]], 1);
		minm = min(minm, a[i]);
		maxm = max(maxm, a[i]);
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