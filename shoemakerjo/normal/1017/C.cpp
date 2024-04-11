#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	// if (n == 1) {
	// 	cout << 1 << endl;
	// 	return 0;
	// }
	int lo = 1;
	int hi = n+10;
	while (lo < hi) {
		// cout << lo << "  " << hi << ": ";
		int mid = (lo + hi)/2;
		// cout << mid << endl;
		if (mid % 2 == 0) {
			ll fi = mid/2;
			if (fi*fi >= n) {
				hi = mid;
			}
			else lo = mid+1;
		}
		else {
			ll fi = mid/2;
			ll se = fi+1;
			if (fi * se >= n) {
				hi = mid;
			}
			else lo = mid+1;
		}
	}

	int numgroups = lo/2;
	int gsize = numgroups;
	if (lo % 2 == 1) gsize++;
	// cout << "ans things: " << lo << " "  << numgroups << " " << gsize << endl;
	int cstart = 1;

	for (int i = 0; i < numgroups; i++) {
		vector<int> stuff;
		for (int j = 0; j < gsize; j++) {
			if (cstart <= n) stuff.push_back(cstart);
			else break;
			cstart++; 
		}
		reverse(stuff.begin(), stuff.end());
		for (int val : stuff) cout << val << " ";
	}
	cout << endl;

	// int minsum = n*n*1000;
	// vector<int> nums;
	// int lis[n];
	// int lds[n];
	// for (int i = 1; i <= n; i++) nums.push_back(i);

	// int bestans = minsum;

	// vector<int> ans;

	// do {
	// 	fill(lis, lis+n, 1);
	// 	fill(lds, lds+n, 1);
	// 	for (int i = 1; i < n; i++) {
	// 		for (int j = 0; j < i; j++) {
	// 			if (nums[j] < nums[i]) lis[i] = max(lis[i], lis[j]+1);
	// 			else lds[i] = max(lds[i], lds[i]+1);
	// 		}
	// 	}
	// 	int mi = 0, md = 0;
	// 	for (int i = 0; i < n; i++) {
	// 		mi = max(mi, lis[i]);
	// 		md = max(md, lds[i]);
	// 	}
	// 	int myans = mi + md;

	// 	// cout << "perm: ";
	// 	// for (int val : nums) cout << val << " ";
	// 	// 	cout << "		cans:   " << myans << endl;
	// 	if (bestans > myans) {
	// 		ans.clear();
	// 		for (int val : nums) ans.push_back(val);
	// 	}
	// 	bestans = min(bestans, myans);


	// } while (next_permutation(nums.begin(), nums.end()));

	// cout << "answer: ";
	// for (int val : ans) cout << val << " ";
	// cout << endl;
	// cout << bestans << endl;
}