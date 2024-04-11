#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int sq = 0;
	vector<ll> poss;
	vector<ll> bc;
	for (int i = 0; i < n; i++) {
		int cur = sqrt(nums[i]);
		if (cur*cur == nums[i]) {
			sq++;
			if (nums[i] == 0) {
				bc.push_back(2);
			}
			else bc.push_back(1);
			continue;
		}
		int diff = nums[i]-cur*cur;
		diff = min(diff, (cur+1)*(cur+1)-nums[i]);
		poss.push_back(diff+0LL);

	}
	sort(poss.begin(), poss.end());
	sort(bc.begin(), bc.end());
	ll ans = 0LL;
	if (sq >= n/2) {
		for (int i = 1; i <= sq-n/2; i++) {
			ans += bc[i-1];
		}
	}
	else {
		for (int i = 1; i <= (n-sq)-n/2; i++) {
			ans += poss[i-1];
		}
	}
	cout << ans << endl;
	cin >> ans;
}