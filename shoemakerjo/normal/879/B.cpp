#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// freopen("out.txt", "w", stdout);
	int big = -1;
	int n;
	ll k;
	cin >> n >> k;
	int nums[n];
	vector<int> cnums;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		cnums.push_back(nums[i]);
		big = max(big, nums[i]);
	}
	if (k > n) {
		cout << big << endl;
		return 0;
	}
	int cur = nums[0];
	int cw = 0;
	for (int i = 1; i < 2*n; i++) {
		if (cw == k) {
			cout << cur << endl;
			return 0;
		}
		if (cnums[i] > cur) {
			cnums.push_back(cur);
			cur = cnums[i];
			cw = 1;

		}
		else {
			cnums.push_back(cnums[i]);
			cw++;
		}

	}
	cout << cur << endl;
}