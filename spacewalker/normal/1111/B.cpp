#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, k, m;  scanf("%d %d %d", &n, &k, &m);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	sort(begin(arr), end(arr));
	reverse(begin(arr), end(arr));
	vector<ll> totalPower = arr;
	for (int i = 1; i < n; ++i) totalPower[i] += totalPower[i-1];
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		if (n - 1 - i > m) continue;
		ll remToI = m - (n - 1 - i);
		ll maxIncrease = (i + 1) * (ll)k;
		ans = max(ans, (totalPower[i] + min(maxIncrease, remToI)) / (double)(i + 1));
	}
	printf("%.8lf\n", ans);
	return 0;
}