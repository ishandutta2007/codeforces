#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> seen;
	vector<int> ans;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = n-1; i >= 0; i--) {
		if (seen.find(nums[i]) != seen.end()) continue;
		seen.insert(nums[i]);
		ans.push_back(nums[i]);
	}
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	for (auto v : ans) cout << v << " ";
	cout << endl;
	cin >> n;
}