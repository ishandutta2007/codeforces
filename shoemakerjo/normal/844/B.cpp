#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int nums[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int  j = 0; j < m; j++) {
			int ct = 0;
			for (int k = 0; k < i; k++) {
				if (nums[k][j] == nums[i][j]) ct++;
			}
			ll add = 1;
			for (int k = 0; k < ct; k++) {
				add*=2LL;
			}
			ans += add;
			ct = 0;
			for (int k = 0; k < j; k++) {
				if (nums[i][k] == nums[i][j]) ct++;
			}
			add = 1;
			for (int k = 0; k < ct; k++) {
				add*=2LL;
			}
			ans += add-1;
		}
	}
	cout << ans << endl;
	// cin >> ans;
}