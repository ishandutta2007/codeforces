#include <bits/stdc++.h>

using namespace std;

int a[200];

void solve() {
	int n;
	scanf("%d", &n);
	int maxm = 0, minm = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > a[maxm])
			maxm = i;
		if (a[i] < a[minm])
			minm = i;
	}
	if (minm > maxm)
		swap(minm, maxm);
	int ans = 100000;
	ans = min(ans, maxm + 1);
	ans = min(ans, n - minm);
	ans = min(ans, minm + 1 + n - maxm);
	printf("%d\n", ans);
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