#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int pos = (n - 1) / 2;
	int step = 1;
	int sgn = 1;
	for (int i = 0; i < n; i++) {
		cout << a[pos] << " ";
		pos += step * sgn;
		step++;
		sgn *= -1;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}