#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int cur;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	if (k == n) {
		cout << nums[n-1] << endl;
	}
	else {
		if (k == 0) {
			if (nums[0] == 1) cout << -1 << endl;
			else cout << 1 << endl;
		}
		else if (nums[k-1] == nums[k]) {
			cout << -1 << endl;
		}
		else cout << nums[k-1] << endl;
	}
	cin >> n;

	
}