#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur;
	map<int, int> nums;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (nums.count(cur) == 0) nums[cur] = 1;
		else {
			nums[cur]++;
		}
		ans = max(ans, nums[cur]);
	}
	cout << ans << endl;
	cin >> ans;
	
}