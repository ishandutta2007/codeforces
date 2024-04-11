#include <iostream>
#include <vector>
#include <algorithm>

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
	sort(nums.begin(), nums.end());
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> cur;
		cout << upper_bound(nums.begin(), nums.end(), cur)-nums.begin() << endl;
	}
	// cin >> n;

}