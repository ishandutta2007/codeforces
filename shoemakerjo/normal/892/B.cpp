#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int mx = 2000000000;
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (i+1 < mx) ans++;
		mx = min(mx, i+1-nums[i]);
	}
	cout << ans << endl;
	cin >> ans;
}