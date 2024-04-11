#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	int cur = a[0], mx, idx;
	for (int i = 0; i < n; ++i) {
		mx = 0;
		for (int j = 0; j < a.size(); ++j) {
			int g = __gcd(cur, a[j]);
			if (g > mx) {
				mx = g;
				idx = j;
			}
		}
		cout << a[idx] << ' ';
		a.erase(a.begin() + idx);
		cur = mx;
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}