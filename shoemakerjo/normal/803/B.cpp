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
	int c0 = 0-n*2;
	int ans[n];
	fill(ans, ans+n, 2*n);
	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) {
			c0 = i;
		}
		ans[i] = min(ans[i], i-c0);
	}
	c0 = 4*n;
	for (int i = n-1; i >= 0; i--) {
		if (nums[i] == 0) c0 = i;
		ans[i] = min(ans[i], c0-i);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}