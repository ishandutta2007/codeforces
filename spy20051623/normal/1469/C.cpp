#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int l, r;
	l = r = a[0];
	for (int i = 1; i < n; ++i) {
		l = max(l - k + 1, a[i]);
		r = min(r + k - 1, a[i] + k - 1);
		if (l > r) {
			printf("NO\n");
			return;
		}
	}
	if (a[n - 1] < l || a[n - 1] > r)
		printf("NO\n");
	else
		printf("YES\n");
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