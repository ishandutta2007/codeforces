#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cur;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int ans = 0;
	int changes = 1;
	while (changes > 0) {
		changes = 0;
		vector<int> nx;
		ans += nums.size()-1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i-1]) {
				ans--;
				changes++;
				nx.push_back(nums[i]);
			}
		}
		nums = nx;
	}
	cout << ans << endl;
	cin >> n;
}