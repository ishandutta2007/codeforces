#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> nums;
	int ans = 0;
	int cur;
	while (n--) {
		cin >> cur;
		if (cur == 0) continue;
		if (nums.count(cur) == 0) {
			ans++;
			nums.insert(cur);
		}
	}
	cout << ans << endl;
	cin >> ans;
}