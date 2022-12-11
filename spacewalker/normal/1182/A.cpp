#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<ll> ans(n + 1);
	ans[0] = 1;
	for (int i = 1; i <= n; ++i) {
		ans[i] = (i >= 2 ? 2 * ans[i-2] : 0);
	}
	printf("%lld\n", ans[n]);
	return 0;
}