#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	int ans = 300000;
	for (int i = 1; i < n-1; i++) {
		vector<int> cur;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			cur.push_back(nums[j]);
		}
		int cans = 0;
		for (int j = 0; j < cur.size()-1; j++) {
			cans = max(cans, cur[j+1]-cur[j]);
		}
		ans = min(ans, cans);
	}
	cout << ans << endl;
	// cin  >> ans;
}