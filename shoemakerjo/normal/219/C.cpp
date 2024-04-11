#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int k;
	cin >> n >> k;
	int dp[n][k];
	int dpi[n][k];
	string orig;
	cin >> orig;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = n*2;
			dpi[i][j] = -1;
		}
	}
	for (int i = 0; i < k; i++) {
		if (orig[0]-'A' == i) {
			dp[0][i] = 0;
		}
		else dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int b1 = n*2;
		int ind1 = -1;
		int ind2 = -1;
		int b2 = n*2;
		for (int j = 0; j < k; j++) {
			if (dp[i-1][j] < b1) {
				b2 = b1;
				ind2 = ind1;
				b1 = dp[i-1][j];
				ind1 = j;
			}
			else if (dp[i-1][j] < b2) {
				b2 = dp[i-1][j];
				ind2 = j;
			}
		}
		// cout << "b1:  " << b1 << " " << ind1 << endl;
		// cout << "   b2:    " << b2 << endl;
		for (int j = 0; j < k; j++) {
			int cur = 1;
			if (orig[i]-'A' == j) {
				cur--;
			}
			if (ind1 == j) {
				dp[i][j] = b2 + cur;
				dpi[i][j] = ind2;
			}
			else {
				dp[i][j] = b1 + cur;
				dpi[i][j] = ind1;
			}
		}
	}
	int best = 2*n;
	int si = -1;
	for (int i = 0; i < k; i++) {
		if (dp[n-1][i] < best) {
			best = dp[n-1][i];
			si = i;
		}
	}
	// cout << best << " " << si << endl;
	cout << best << endl;
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
	// cout << alph[si];
	vector<char> ans;
	ans.push_back(alph[si]);
	int st = n-1;
	while (si != -1) {
		// cout << st << " " << si << endl;
		si = dpi[st][si];
		st--;
		if (si == -1) break;
		// cout << alph[si];
		ans.push_back(alph[si]);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;


	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < k; j++) {
	// 		cout << "(" << dp[i][j] << " " << dpi[i][j] << ")  " ;
	// 	}
	// 	cout << endl;
	// }
	// cin >> n;
}