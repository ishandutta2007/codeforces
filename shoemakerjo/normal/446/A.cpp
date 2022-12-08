#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}	
	int notused[n];
	int used[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		notused[i] = 1;
		used[i] = 1;
		if (i > 0) {
			// used[i] = notused[i-1]+1;
			ans = max(ans, notused[i-1]+1);
			if (nums[i] > nums[i-1]) {
				notused[i] = notused[i-1]+1;
				used[i] = max(used[i], used[i-1]+1);
			}

		}
		if (i > 1) {
			if (nums[i] > nums[i-2]+1) {
				used[i] = 
				max(used[i], notused[i-2]+2);
			}
		}
		ans = max(ans, used[i]);
		ans = max(ans, notused[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i - notused[i]+1 > 0) {
			ans = max(ans, notused[i]+1);
		}
	}
	cout << ans << endl;
	cin >> n;
}