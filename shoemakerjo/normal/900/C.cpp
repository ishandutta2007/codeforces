#include <bits/stdc++.h>

using namespace std;

int n;
int BIT[100010];

void update(int u) {
	while (u <= n) {
		BIT[u]++;
		u += u&(-u);
	}
}

int query(int u) {
	int ans = 0;
	while (u > 0) {
		ans += BIT[u];
		u -= u&(-u);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin  >> n;
	int cur;
	int mx = -1;
	int fs = 0;
	bool se[n];
	int ad[n+1];
	int nums[n];
	for (int i = 0; i <= n; i++) {
		ad[i] = 0;
		BIT[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums[i] = cur;
		if (cur > mx) {
			se[i] = true;
			mx = cur;
			fs++;
		}
		else {
			se[i] = false;
			int qu = i-query(cur);
			// cout << "nums[i]  " << nums[i] << "  " << qu << endl;
			if (qu == 1) {
				ad[mx]++;
			}
		}
		update(cur);
	}
	int ans = fs-3;
	int rem = 1;
	for (int i = 0; i < n; i++) {
		int ca = fs;
		if (se[i]) ca--;
		// cout << "val   " << nums[i] << "  " << ad[nums[i]] << endl;
		ca += ad[nums[i]];
		if (ca >ans) {
			rem = nums[i];
			ans = ca;
		}
		else if (ca == ans) {
			rem = min(rem, nums[i]);
		}
	}
	cout << rem << endl;
	cin >> ans;
}