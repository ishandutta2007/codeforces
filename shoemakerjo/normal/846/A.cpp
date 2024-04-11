#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i != n && nums[i] == 0) continue;
		int cur = n;
		for (int j = 0; j < i; j++) {
			if (nums[j] == 1) cur--;
		}
		for (int j = i+1; j < n; j++) {
			if (nums[j] == 0) cur--;
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	cin >> ans;
}