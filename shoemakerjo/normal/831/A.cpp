#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool valid = true;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int part = 0;
	for (int i = 1; i < n; i++) {
		if (part == 0) {
			if (nums[i] == nums[i-1]) part = 1;
			if (nums[i] < nums[i-1]) part = 2;
		}
		else if (part == 1) {
			if (nums[i] < nums[i-1]) part = 2;
			if (nums[i] > nums[i-1]) valid = false;
		}
		else {
			if (nums[i] >= nums[i-1]) valid = false;
		}
	}
	if (valid) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}