#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int l = 1, r = n - 1;
	long long s1 = v[0], s2 = 0;
	while (l < r) {
		s1 += v[l++];
		s2 += v[r--];
		if (s1 < s2) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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