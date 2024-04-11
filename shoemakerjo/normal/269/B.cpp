#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	int nums[n];
	double d;
	for (int i = 0; i < n; i++) {
		cin >> nums[i] >> d;
	}
	int lis[n];
	for (int i = 0; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[j] <= nums[i]) {
				lis[i] = max(lis[i], lis[j]+1);
			}
		}
		ans = max(ans, lis[i]);
	}
	cout << n-ans << endl;
	// cin >> n;
}