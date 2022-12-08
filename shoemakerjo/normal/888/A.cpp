#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i < n-1; i++) {
		if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) ans++;
		if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) ans++;
	}
	cout << ans << endl;
	cin >> ans;
}