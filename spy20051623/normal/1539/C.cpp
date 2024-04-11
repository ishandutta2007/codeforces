#include <bits/stdc++.h>

using namespace std;

long long a[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	long long k, x;
	scanf("%d%lld%lld", &n, &k, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	vector<long long> v;
	for (int i = 0; i < n - 1; ++i) {
		long long p = a[i + 1] - a[i];
		if (p > x) {
			v.push_back(p);
		}
	}
	sort(v.begin(), v.end());
	long long ans = 1;
	for (int i = 0; i < v.size(); ++i) {
		if ((v[i] - 1) / x <= k) {
			k -= (v[i] - 1) / x;
		} else {
			ans += v.size() - i;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}