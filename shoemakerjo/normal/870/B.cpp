#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	if (k >= 3) {
		int ans = nums[0];
		for (int i = 0; i < n; i++) {
			ans = max(ans, nums[i]);
		}
		cout << ans << endl;
	}
	else if (k == 2) {
		cout << max(nums[0], nums[n-1]) << endl;
	}
	else {
		int ans = nums[0];
		for (int i = 0; i < n; i++) {
			ans = min(ans, nums[i]);
		}
		cout << ans << endl;
	}
	// cin >> n;
}