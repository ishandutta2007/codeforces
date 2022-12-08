#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;

	int sum = 0;
	int cur; 
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		sum+=cur;
		nums.push_back(sum);
		
	}

	int m;
	cin >> m;
	int spot;
	for (int i = 0; i < m; ++i) {
		cin >> cur;
		spot = lower_bound(nums.begin(), nums.end(), cur) - nums.begin();
		cout << spot+1 << "\n";
	
	}

	// cin >> n;
}