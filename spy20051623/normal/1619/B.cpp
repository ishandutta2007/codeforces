#include <bits/stdc++.h>

using namespace std;

int a[100000];
int n = 0;

void solve() {
	int x;
	cin >> x;
	int p = upper_bound(a, a + n, x) - a;
	cout << p << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 1; i < 33333; ++i) {
		if (i * i <= 1e9) a[n++] = i * i;
		else break;
	}
	for (int i = 1; i < 10000; ++i) {
		if (i * i * i <= 1e9) a[n++] = i * i * i;
		else break;
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}