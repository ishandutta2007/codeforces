#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	long long sum = 0;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum * 2 % n) {
		puts("0");
		return;
	}
	long long s = sum * 2 / n, ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += m[s - a[i]];
		++m[a[i]];
	}
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