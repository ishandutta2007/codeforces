#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<int> nums;
	int cur;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	ans += 2;
	for (int i = 0; i < nums.size()-1; i++) {
		int diff = nums[i+1]-nums[i];
		if (diff > 2*d) ans += 2;
		if (diff == 2*d) ans++;
	}
	cout << ans << endl;

}