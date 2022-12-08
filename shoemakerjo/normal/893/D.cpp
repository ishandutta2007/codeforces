#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	int ans = 0;
	bool ok = true;
	ll nums[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	ll pref[n+1];
	pref[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + nums[i];
	}
	ll pmax[n+1];
	pmax[n] = pref[n];
	int cur = 0;
	for (int i = n-1; i >= 0; i--) {
		pmax[i] = max(pmax[i+1], pref[i]);
	}
	for (int i = 1; i <= n; i++) {
		cur += nums[i];
		if (cur > d) {
			ok = false;
			break;
		}
		if (nums[i] == 0) {
			if (cur < 0) {
				ans++;
				int mx = pmax[i]-pref[i];
				if (mx < 0 || mx > d) {
					ok = false;
					break;
				}
				cur = d-mx;
			}
		}
	}
	if (!ok) cout << -1 << endl;
	else cout << ans << endl;
	cin >> ans;
}