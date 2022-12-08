#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	//(n^4 +n^2)/2
	vector<vector<int>> nums;
	for (int i = 0; i < n; i++) {
		vector<int> b;
		nums.push_back(b);
	}
	int pt = 0;
	int val = 1;
	bool inc = true;
	while (val <= n*n) {
		// cout << val << endl;
		nums[pt].push_back(val);
		if (inc) {
			if (pt == n-1) {
				inc = false;
			}
			else pt++;
		}
		else {
			if (pt == 0) {
				inc = true;
			}
			else pt--;
		}
		val++;
	}
	// cout <<  "here" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0) cout << " ";
			cout << nums[i][j];
		}
		cout << endl;
	}
	cin >> pt;
}