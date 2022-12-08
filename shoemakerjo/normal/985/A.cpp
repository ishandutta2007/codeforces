#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n/2; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n/2; i++) {
		ans1 += abs(nums[i]-i*2-2);
		ans2 += abs(nums[i]-i*2-1);
	}
	cout << min(ans1, ans2) << endl;
	cin >> n;
}