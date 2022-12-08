#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur*1000+i+1);
	}
	sort(nums.begin(), nums.end());
	vector<int> inds;
	// cout << "here";
	for (int j = 0; j < n; j++) {
		if (k >= nums[j]/1000) {
			k-=nums[j]/1000;
			inds.push_back(nums[j]%1000);
		}
		else break;
	}
	// cout << "here2";
	cout << inds.size() << endl;
	for (int i = 0; i < inds.size(); i++) {
		if (i > 0) cout << " ";
		cout << inds[i];
	}
	if (inds.size() > 0)
		cout << endl;
	// cin >> n;
}