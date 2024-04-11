#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int start = -1;
	int end = -1;
	bool inr = false;
	bool flip = false;
	bool poss = true;
	for (int i = 1; i < n; i++) {
		if (!inr) {
			if (nums[i] < nums[i-1]) {
				start = i-1;
				inr = true;
				if (flip) {
					poss = false;
				}
				flip = true;
			}
			
		}
		else {
			if (nums[i] > nums[i-1]) {
				end = i-1;
				inr = false;
			}
		}
	}

	if (inr) end = n-1;
	// cout << start << " " << end << endl;
	if (poss && start == -1) {
		start = 0;
		end = 0;
	}
	if (poss && (start == 0 || nums[end] > nums[start-1]) && 
		(end == n-1 || nums[start] < nums[end+1])) {
		cout << "yes" << endl << start+1 << " " << end+1 << endl;
	}
	else cout << "no" << endl;
	// cin >> n;
}