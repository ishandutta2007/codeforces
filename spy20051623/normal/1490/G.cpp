#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n, m, i, j, l, r, mid;
	cin >> n >> m;
	vector<ll> a(n + 5);
	vector<ll> s(n + 5);
	vector<ll> ma(n + 5);
	cin >> a[0];
	s[0] = ma[0] = a[0];
	for (i = 1; i < n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ma[i] = max(ma[i - 1], s[i]);
	}
	while (m--) {
		cin >> i;
		ll sum;
		if (ma[n - 1] < i && s[n - 1] <= 0)
			cout << -1 << ' ';
		else {
			if (i <= ma[n - 1])
				sum = 0;
			else if ((i - ma[n - 1]) % s[n - 1] == 0) {
				sum = (i - ma[n - 1]) / s[n - 1] * n;
				i = ma[n - 1];
			} else {
				sum = ((i - ma[n - 1]) / s[n - 1] + 1) * n;
				i -= ((i - ma[n - 1]) / s[n - 1] + 1) * s[n - 1];
			}
			l = 0;
			r = n - 1;
			while (l < r) {
				mid = l + r >> 1;
				if (ma[mid] < i)
					l = mid + 1;
				else
					r = mid;
			}
			cout << sum + l << ' ';
		}
	}
	cout << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}