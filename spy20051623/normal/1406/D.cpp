#include <bits/stdc++.h>

using namespace std;

long long a[100005], d[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n - 1; ++i) d[i] = a[i + 1] - a[i];
	long long sum = 0;
	for (int i = 1; i <= n - 1; ++i) if (d[i] > 0) sum += d[i];
	cout << (long long) ceil((sum + a[1]) * 0.5) << '\n';
	int q;
	cin >> q;
	while (q--) {
		long long l, r, x;
		cin >> l >> r >> x;
		if (l > 1) {
			if (d[l - 1] > 0) sum -= d[l - 1];
			d[l - 1] += x;
			if (d[l - 1] > 0) sum += d[l - 1];
		}
		if (r < n) {
			if (d[r] > 0) sum -= d[r];
			d[r] -= x;
			if (d[r] > 0) sum += d[r];
		}
		if (l == 1) a[1] += x;
		cout << (long long) ceil((sum + a[1]) * 0.5) << '\n';
	}
	return 0;
}