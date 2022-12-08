#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t[n+1];
	int tot = 0;
	int pref[n+1];
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		pref[i] = pref[i-1];
		if (t[i] == 1) tot += a[i];
		else {
			pref[i] += a[i];
		}
	}
	int ans = 0;
	for (int i = k; i <= n; i++) {
		int cur = tot + pref[i]-pref[i-k];
		ans = max(ans, cur);
	}
	cout << ans << endl;
	cin >> n;
}