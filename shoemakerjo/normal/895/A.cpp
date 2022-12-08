#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 360;
	int cur;
	int sum = 0;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums[i] = cur;
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += nums[(i+j)%n];
			ans = min(ans, abs(sum-(360-sum)));
		}
	}
	cout << ans << endl;
	cin >> ans;
}