#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	vector<long long> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}

	long long ans = numeric_limits<long long>::max();
	for (int i = 0; i <= n - 1; ++i) {
		long long ss = k - pref[n - i] + pref[1];
		long long mx = ss / (i + 1);
		while ((mx + 1) * (i + 1) <= ss) {
			++mx;
		}
		while (mx * (i + 1) > ss) {
			--mx;
		}
		ans = min(ans, i + max(0ll, a[0] - mx));
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}