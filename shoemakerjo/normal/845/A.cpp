#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 0; i < 2*n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	if (nums[n-1] == nums[n]) cout << "NO\n";
	else cout << "YES\n";
	cin >> n;
}