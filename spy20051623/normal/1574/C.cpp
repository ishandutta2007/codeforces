#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	int m;
	scanf("%d", &m);
	while (m--) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		int p = lower_bound(a, a + n, x) - a;
		long long f;
		if (p == n) f = (a[n - 1] >= x ? 0 : x - a[n - 1]) + (s - y >= a[n - 1] ? 0 : a[n - 1] - (s - y));
		else if (p == 0) f = (a[0] >= x ? 0 : x - a[0]) + (s - y >= a[0] ? 0 : a[0] - (s - y));
		else
			f = min((a[p] >= x ? 0 : x - a[p]) + (s - y >= a[p] ? 0 : a[p] - (s - y)),
					(a[p - 1] >= x ? 0 : x - a[p - 1]) + (s - y >= a[p - 1] ? 0 : a[p - 1] - (s - y)));
		printf("%lld\n", f);
	}
	return 0;
}