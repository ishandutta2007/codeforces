#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, K;
	cin >> N >> K;
	vector<string> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	vector<vector<int> > dp(N, vector<int>(N, inf));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			if (i + j == 0) dp[i][j] = 0;
			if (S[i][j] != 'a') ++dp[i][j];
		}
	}
	int mx = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dp[i][j] <= K) mx = max(mx, i + j + 1);
		}
	}
	if (mx == 2 * N - 1) {
		cout << string(mx, 'a') << endl;
	}
	else {
		vector<vector<bool> > ok(N, vector<bool>(N));
		if (mx == 0) ok[0][0] = true;
		else {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (i + j == mx - 1 && dp[i][j] <= K) {
						if (i != N - 1) ok[i + 1][j] = true;
						if (j != N - 1) ok[i][j + 1] = true;
					}
				}
			}
		}
		for (int i = mx; i <= 2 * N - 2; ++i) {
			char mn = '~';
			for (int j = 0; j < N; ++j) {
				int k = i - j;
				if (0 <= k && k < N && ok[j][k]) {
					mn = min(mn, S[j][k]);
				}
			}
			for (int j = 0; j < N; ++j) {
				int k = i - j;
				if (0 <= k && k < N && ok[j][k] && S[j][k] != mn) {
					ok[j][k] = false;
				}
			}
			for (int j = 0; j < N; ++j) {
				int k = i - j;
				if (0 <= k && k < N && ok[j][k]) {
					if (j != N - 1) ok[j + 1][k] = true;
					if (k != N - 1) ok[j][k + 1] = true;
				}
			}
		}
		int cx = N - 1, cy = N - 1;
		string ans;
		for (int i = 2 * N - 2; i >= mx; --i) {
			ans += S[cx][cy];
			if (cx != 0 && ok[cx - 1][cy]) --cx;
			else --cy;
		}
		reverse(ans.begin(), ans.end());
		ans = string(mx, 'a') + ans;
		cout << ans << endl;
	}
	return 0;
}