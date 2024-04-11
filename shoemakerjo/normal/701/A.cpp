#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		nums.push_back(cur*101 + i);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i  < n/2; i++) {
		cout << nums[i]%101 << " " << nums[n-i-1]%101 << endl;
	}
	// cin >> n;
}