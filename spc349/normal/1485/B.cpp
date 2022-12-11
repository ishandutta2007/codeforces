#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main () {
	int n, q, k; cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i] - 1;
		b[i] += b[i - 1];
	}
	while (q--) {
		int l, r; cin >> l >> r;
		int ans = (b[r - 1] - b[l - 1]) * 2 + a[l] - 1 + k - a[r];
		cout << ans << endl;
	}
	return 0;
}