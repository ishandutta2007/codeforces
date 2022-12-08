#include <bits/stdc++.h>

using namespace std;

long long fac[16];
long long sum[200005];

vector<int> calc(int n, long long x) {
	vector<int> v, p(n);
	for (int i = 0; i < n; ++i) p[i] = i + 1;
	for (int i = n - 1; i >= 0; --i) {
		v.push_back(p[x / fac[i]]);
		p.erase(p.begin() + x / fac[i]);
		x %= fac[i];
	}
	return v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	fac[0] = 1;
	for (int i = 1; i < 16; ++i) fac[i] = fac[i - 1] * i;
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + i;
	int sz = min(15, n);
	long long s = 0;
	while (q--) {
		int o;
		scanf("%d", &o);
		if (o == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			vector<int> v = calc(sz, s);
			for (int i = 0; i < sz; ++i) sum[n - sz + 1 + i] = sum[n - sz + i] + v[i] + n - sz;
			printf("%lld\n", sum[r] - sum[l - 1]);
		} else {
			int x;
			scanf("%d", &x);
			s += x;
		}
	}
	return 0;
}