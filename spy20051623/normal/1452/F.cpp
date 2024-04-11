#include <bits/stdc++.h>

using namespace std;

long long a[50];
long long sum, ans;

long long work(int p, int x, long long k) {
	if (!k || p == x) return 0;
	long long tmp = sum >= k ? k : 0;
	long long res = 1;
	if (k >= 1ll << (p - x - 1)) {
		res += (1ll << (p - x - 1)) - 1;
		sum += (1ll << (p - 1)) - (1ll << (p - x - 1));
		k -= 1ll << (p - x - 1);
	}
	if (k) res += work(p - 1, x, k);
	if (tmp) res = min(res, tmp);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	while (q--) {
		int o;
		long long x, k;
		scanf("%d%lld%lld", &o, &x, &k);
		if (o == 1) {
			a[x] = k;
		} else {
			sum = 0, ans = 0;
			for (int i = 0; i < n; ++i) {
				sum += a[i] * (1ll << i);
			}
			if (sum < k) {
				printf("-1\n");
				continue;
			}
			sum = 0;
			for (int i = 0; i <= x; ++i) {
				sum += a[i] * ((1ll << i) - 1);
				k -= a[i];
			}
			if (k <= 0) {
				printf("0\n");
				continue;
			}

//			int i = x + 1;
//			while (i < n) {
//				long long add = 1ll << (i - x), need = min(k / add, a[i]);
//				ans += need * (add - 1);
//				k -= need * add;
//				sum += need * add * ((1ll << x) - 1);
//				if (need == a[i]) ++i;
//				else break;
//			}
//			if (k <= 0) {
//				printf("%lld\n", ans);
//				continue;
//			}
//			if (i >= n) {
//				printf("%lld\n", ans + k);
//				continue;
//			}
//			long long tmp = 1e18;
//			while (i > x) {
//				if (sum >= k) tmp = min(tmp, ans + k);
//				++ans, --i;
//				long long add = 1ll << (i - x);
//				if (k >= add) {
//					ans += add - 1;
//					k -= add;
//					sum += add * ((1ll << x) - 1);
//				}
//			}
//			printf("%lld\n", min(ans, tmp));

			for (int i = x + 1; i < n; ++i) {
				if (a[i] * (1ll << (i - x)) <= k) {
					ans += a[i] * ((1ll << (i - x)) - 1);
					sum += a[i] * ((1ll << i) - (1ll << (i - x)));
					k -= a[i] << (i - x);
				} else {
					long long num = k >> (i - x);
					ans += num * ((1ll << (i - x)) - 1);
					sum += num * ((1ll << i) - (1ll << (i - x)));
					k -= num << (i - x);

//					long long tmp = 1e18;
//					for (int j = i; j > x;) {
//						if (sum >= k) tmp = min(tmp, ans + k);
//						++ans, --j;
//						if (k >= 1ll << (j - x)) {
//							ans += (1ll << (j - x)) - 1;
//							sum += (1ll << j) - (1ll << (j - x));
//							k -= 1ll << (j - x);
//						}
//					}
//					ans = min(ans, tmp);
					ans += work(i, x, k);
					k = 0;
					break;
				}
			}
			ans += k;
			printf("%lld\n", ans);
		}
	}
	return 0;
}