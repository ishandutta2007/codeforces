#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
long long a[N], b[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; ++i) scanf("%lld", &b[i]);
	for (int i = 2; i <= m; ++i)
		if (a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) {
			puts("-1");
			return 0;
		}
	a[0] = -2e9, a[n + 1] = 2e9, b[m + 1] = n + 1;
	int ans = 0;
	for (int i = 0; i <= m; ++i) {
		for (int j = b[i] + 1; j < b[i + 1]; ++j) {
			c[j] = a[j] - a[b[i]] - (j - b[i]);
		}
		vector<long long> v;
		for (int j = b[i] + 1; j < b[i + 1]; ++j) {
			if (c[j] < 0 || c[j] > a[b[i + 1]] - a[b[i]] - (b[i + 1] - b[i])) continue;
			if (v.empty() || v.back() <= c[j]) v.push_back(c[j]);
			else *upper_bound(v.begin(), v.end(), c[j]) = c[j];
		}
		ans += b[i + 1] - b[i] - 1 - v.size();
	}
	printf("%d\n", ans);
	return 0;
}