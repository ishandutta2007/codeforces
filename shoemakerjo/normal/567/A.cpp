#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++) {
		int mi;
		if (i == 0) mi = nums[1]-nums[0];
		else if (i == n-1) mi = nums[n-1]-nums[n-2];
		else {
			mi = min(nums[i+1]-nums[i],nums[i]-nums[i-1]);
		}

		int ma = max(nums[i]-nums[0], nums[n-1]-nums[i]);
		cout << mi << " " << ma << "\n";
	}
	// cin >> n;
}