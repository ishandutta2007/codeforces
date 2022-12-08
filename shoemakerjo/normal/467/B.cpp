#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int nums[m+1];
	for (int i = 0; i <= m; ++i) {
		cin >> nums[i];
	}
	int cur;
	int ct;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		cur = nums[i]^nums[m];
		ct = 0;
		while (cur > 0) {
			if (cur % 2 == 1) ct++;
			cur = cur >> 1;
		}
		if (ct <= k) ans++;
	}
	cout << ans << endl;
	// cin >> n;
}