#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int ans = n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (nums[j]-nums[i] <= d) {
				ans = min(ans, n-(j-i+1));
			}
		}
	}
	cout << ans << endl;
	cin >> n;
}