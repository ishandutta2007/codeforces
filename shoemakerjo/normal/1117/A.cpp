#include <bits/stdc++.h>

using namespace std;

int n;
int nums[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		mx = max(mx, nums[i]);
	}
	int crun = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (nums[i] != mx) {
			ans = max(ans, crun);
			crun = 0;
			continue;
		}
		crun++;
		ans = max(ans, crun);
	}
	ans = max(ans, crun);
	cout << ans << endl;

}