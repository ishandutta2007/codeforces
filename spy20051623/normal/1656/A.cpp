#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	cin >> n;
	int x = 1, y = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i] < a[x]) x = i;
		if (a[i] > a[y]) y = i;
	}
	cout << x << ' ' << y << '\n';
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