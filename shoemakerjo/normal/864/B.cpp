#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans = 0;
	set<int> nums;
	int n;
	string line;
	cin >> n >> line;
	for (int i = 0; i < n; i++) {
		int val = line[i]-'a';
		if (0 <= val && val < 26) {
			nums.insert(val);
		}
		else {
			nums.clear();
		}
		int sz = nums.size();
		ans = max(ans, sz);
	}
	cout << ans << endl;
	// cin >> ans;
}