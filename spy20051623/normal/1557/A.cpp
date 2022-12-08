#include <bits/stdc++.h>

using namespace std;

long long a[300005];

void solve() {
	int n;
	scanf("%d", &n);
	long long sum = 0, maxm = -1e18;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i];
		maxm = max(maxm, a[i]);
	}
	printf("%.10lf\n", maxm + (sum - maxm) * 1.0 / (n - 1));
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