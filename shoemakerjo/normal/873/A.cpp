#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, x;
	cin >> n >> k >> x;
	int ans = 0;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < n-k; i++) {
		ans += nums[i];
	}
	ans += k*x;
	cout << ans << endl;
	// cin >> ans;
}