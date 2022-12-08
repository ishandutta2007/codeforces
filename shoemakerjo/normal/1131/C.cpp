#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i += 2) {
		cout << nums[i] << " ";
	}
	int st = nums.size()-1;
	if (st % 2 == 0) st--;
	for (int i = st; i > 0; i -= 2) {
		cout << nums[i] << " ";
	}
	cout << endl;
}