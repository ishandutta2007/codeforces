#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];

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
	sort(a, a + n);
	int x = 0, y = n / 2, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) b[i] = a[x++];
		else b[i] = a[y++];
	}
	for (int i = 1; i < n - 1; i += 2) {
		if (b[i] < b[i - 1] && b[i] < b[i + 1]) ++ans;
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		cout << b[i] << ' ';
	}
	return 0;
}