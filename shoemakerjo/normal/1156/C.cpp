
#include <bits/stdc++.h>

using namespace std;

int n, z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums, rnums;
	cin >> n >> z;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
		rnums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	sort(rnums.begin(), rnums.end());
	reverse(rnums.begin(), rnums.end());

	int lo = 0, hi = n/2;
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		bool ok = true;
		for (int i = 0; i < mid; i++) {
				if (nums[i] + z > rnums[mid-i-1]) {
					ok = false;
					break;
				}
		}
		if (ok) {
			lo = mid;
		}
		else hi = mid-1;
	}

	cout << lo << endl;

}