#include <bits/stdc++.h>

using namespace std;

struct dt {
	long long a, b;
} d[100005];

int cmp(dt &x, dt &y) {
	return x.b < y.b;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &d[i].a, &d[i].b);
		sum += d[i].a;
	}
	sort(d, d + n, cmp);
	long long cur = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (cur == sum)
			break;
		if (cur < d[i].b) {
			long long g = d[i].b - cur;
			long long l = sum - cur;
			if (l < g) {
				long long s = min(l, d[i].a);
				ans += 2 * s;
				cur += s;
			} else {
				ans += 2 * g;
				cur = d[i].b;
				l = sum - cur;
				long long s = min(l, d[i].a);
				ans += s;
				cur += s;
			}
		} else {
			long long l = sum - cur;
			long long s = min(l, d[i].a);
			ans += s;
			cur += s;
		}
	}
	printf("%lld\n", ans);
	return 0;
}