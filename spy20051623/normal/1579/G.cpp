#include <bits/stdc++.h>

using namespace std;

int a[10005];
int n;

bool check(int x) {
	bitset<2005> b, c;
	for (int i = 0; i <= x; ++i) b[i] = c[i] = true;
	for (int i = 0; i < n; ++i) b = (b << a[i] | b >> a[i]) & c;
	return b.any();
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int l = 0, r = 2000, ans;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}