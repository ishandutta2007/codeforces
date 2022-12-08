#include <bits/stdc++.h>

using namespace std;

int a[200005];
int n, k;

bool check(int x) {
	if (k & 1) {
		int p = 0;
		for (int i = 0; i < k / 2 + 1; ++i) {
			while (p < n && a[p] > x) ++p;
			p += 2;
		}
		if (p < n + 2) return true;
		p = 1;
		for (int i = 0; i < k / 2; ++i) {
			while (p < n && a[p] > x) ++p;
			p += 2;
		}
		if (p < n + 1) return true;
	} else {
		int p = 0;
		for (int i = 0; i < k / 2; ++i) {
			while (p < n && a[p] > x) ++p;
			p += 2;
		}
		if (p < n + 1) return true;
		p = 1;
		for (int i = 0; i < k / 2; ++i) {
			while (p < n && a[p] > x) ++p;
			p += 2;
		}
		if (p < n + 2) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, r = 1e9 + 7, ans;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (check(m)) r = m - 1, ans = m;
		else l = m + 1;
	}
	cout << ans << '\n';
	return 0;
}