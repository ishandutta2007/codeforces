#include <bits/stdc++.h>

using namespace std;

int main() {
	int small = 2000000000;
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		small = min(small, nums[i]);
	}
	vector<int> cur;
	for (int i = 0; i < n; i++) {
		if (nums[i] == small) {
			cur.push_back(i);
		}
	}
	int ans = n*2;
	for (int i = 1; i < cur.size(); i++) {
		ans = min(ans, cur[i]-cur[i-1]);
	}
	cout << ans << endl;
	cin >> ans;
}