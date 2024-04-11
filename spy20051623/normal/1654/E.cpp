#include <bits/stdc++.h>

using namespace std;

int a[100005];
int c[100000005];
const int base = 50000000;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = -300; i <= 300; ++i) {
		int mx = 0;
		for (int j = 0; j < n; ++j) {
			++c[a[j] + i * j + base];
			mx = max(mx, c[a[j] + i * j + base]);
		}
		for (int j = 0; j < n; ++j) {
			--c[a[j] + i * j + base];
		}
		ans = max(ans, mx);
	}
	for (int i = 0; i < n; ++i) {
		int mx = 0;
		for (int j = 1; j < 400 && i + j < n; ++j) {
			int d = a[i + j] - a[i];
			if (d % j) continue;
			++c[d / j + base];
			mx = max(mx, c[d / j + base]);
		}
		for (int j = 1; j < 400 && i + j < n; ++j) {
			int d = a[i + j] - a[i];
			if (d % j) continue;
			--c[d / j + base];
		}
		ans = max(ans, mx + 1);
	}
	cout << n - ans;
	return 0;
}