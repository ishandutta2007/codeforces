#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int l = 0, r = n - 1;
	while (l <= r && a[l] == a[r]) ++l, --r;
	if (l > r) {
		puts("YES");
		return;
	}
	int x = a[l], y = a[r];
	bool ok = true;
	l = 0, r = n - 1;
	while (l <= r) {
		while (a[l] == x) ++l;
		while (a[r] == x) --r;
		if (a[l] != a[r]) {
			ok = false;
			break;
		}
		++l, --r;
	}
	if (ok) {
		puts("YES");
		return;
	}
	ok = true;
	l = 0, r = n - 1;
	while (l <= r) {
		while (a[l] == y) ++l;
		while (a[r] == y) --r;
		if (a[l] != a[r]) {
			ok = false;
			break;
		}
		++l, --r;
	}
	if (ok) {
		puts("YES");
		return;
	}
	puts("NO");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}