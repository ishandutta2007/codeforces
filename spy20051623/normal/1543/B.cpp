#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		sum += p;
	}
	long long rem = sum % n;
	long long ans = rem * (n - rem);
	printf("%lld\n", ans);
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