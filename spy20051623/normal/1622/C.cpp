#include <bits/stdc++.h>

using namespace std;

long long a[200005];

void solve() {
	long long n, k;
	cin >> n >> k;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	long long l = -1e9, r = a[0], ans = 1e18;
	while (l <= r) {
		long long m1 = l + (r - l) / 3;
		long long num1 = a[0] - m1, s1 = sum - num1, p1 = n - 1;
		while (s1 > k && p1 >= 0) {
			++num1;
			s1 -= a[p1--] - m1;
		}
		if (p1 == -1) num1 = 1e18;
		long long m2 = r - (r - l) / 3;
		long long num2 = a[0] - m2, s2 = sum - num2, p2 = n - 1;
		while (s2 > k && p2 >= 0) {
			++num2;
			s2 -= a[p2--] - m2;
		}
		if (p2 == -1) num2 = 1e18;
		if (num1 < num2) {
			ans = min(ans, num1);
			r = m2 - 1;
		} else if (num1 > num2 || num1 == num2 && num1 == 1e18) {
			ans = min(ans, num2);
			l = m1 + 1;
		} else {
			for (int i = l; i <= r; ++i) {
				long long num = a[0] - i, s = sum - num, p = n - 1;
				while (s > k && p >= 0) {
					++num;
					s -= a[p--] - i;
				}
				if (p == -1) num = 1e18;
				ans = min(ans, num);
			}
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}