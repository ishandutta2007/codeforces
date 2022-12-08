#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	long long sum = 0;
	int p = ceil(0.5 * n);
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j < p; ++j) {
			int x;
			scanf("%d", &x);
		}
	}
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		sum += x;
		for (int j = p + 1; j <= n; ++j) {
			scanf("%d", &x);
		}
	}
	printf("%lld\n", sum);
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