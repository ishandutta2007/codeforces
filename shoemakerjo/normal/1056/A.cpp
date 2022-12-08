#include <bits/stdc++.h>

using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	set<int> nums;
	map<int, int> ct;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		int cur;
		while (r--) {
			cin >> cur;
			nums.insert(cur);
			ct[cur]++;
		}
	}
	for (int val : nums) {
		if (ct[val] == n) {
			cout << val << " " ;
		}
	}
	cout << endl;
}