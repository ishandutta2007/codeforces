#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<int> hill(N), bonus(N);
	for (int i = 0; i < N; ++i) {
		int d1 = 0, d2 = 0;
		if (i < N - 1 && A[i] <= A[i + 1]) d1 = A[i + 1] - A[i] + 1;
		if (i > 0 && A[i] <= A[i - 1]) d2 = A[i - 1] - A[i] + 1;
		hill[i] = d1 + d2;
	}
	for (int i = 2; i < N; ++i) {
		if (A[i - 2] <= A[i - 1] && A[i - 1] >= A[i]) {
			int d1 = A[i - 1] - A[i - 2] + 1;
			int d2 = A[i - 1] - A[i] + 1;
			bonus[i] = min(d1, d2);
		}
	}
	vector<vector<int> > dp(1, vector<int>(4, inf));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<vector<int> > ndp(i / 2 + 2, vector<int>(4, inf));
		for (int j = 0; j < dp.size(); ++j) {
			for (int k = 0; k < 4; ++k) {
				ndp[j][(k * 2) & 3] = min(ndp[j][(k * 2) & 3], dp[j][k]);
				if (k % 2 == 0 && j + 1 < ndp.size()) ndp[j + 1][(k * 2 + 1) & 3] = min(ndp[j + 1][(k * 2 + 1) & 3], dp[j][k] + hill[i] - (k == 2 ? bonus[i] : 0));
			}
		}
		dp = ndp;
	}
	for (int i = 1; i < dp.size(); ++i) {
		int ans = min({ dp[i][0], dp[i][1], dp[i][2], dp[i][3] });
		if (i >= 2) cout << ' ';
		cout << ans;
	}
	cout << endl;
	return 0;
}