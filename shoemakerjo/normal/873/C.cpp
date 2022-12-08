#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int nums[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}
	int tscore = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int spot = -1;
		int best = -1;
		for (int j = 0; j < n; j++) {
			if (nums[j][i] == 0) continue;
			int cb = 0;
			for (int l = j; l < j+k && l < n; l++) {
				if (nums[l][i] == 1) cb++;
			}
			if (cb > best) {
				best = cb;
				spot = j;
			}
		}
		for (int j = 0; j < spot; j++) {
			ans += nums[j][i];
		}
		if (best != -1) {
			tscore += best;
		}
	}
	cout << tscore << " " << ans << endl;
	// cin >> n;
}