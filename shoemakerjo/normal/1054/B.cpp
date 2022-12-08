#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int maxtake = 0;
	int n;
	cin >> n;
	set<int> nums;
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		if (cur > maxtake) {
			cout << i << endl;
			return 0;
		}
		nums.insert(cur);
		while (nums.count(maxtake)) {
			maxtake++;
		}
	}
	cout << -1 << endl;
	
}