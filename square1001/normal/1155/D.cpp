#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 62;
int main() {
	int N, X;
	cin >> N >> X;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<vector<long long> > dp(N + 1, vector<long long>(5, -inf));
	dp[0][0] = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (j >= 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (i >= 1) {
				if (j == 0 || j == 4) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				else if (j == 1 || j == 3) dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i - 1]);
				else dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i - 1] * X);
			}
		}
	}
	cout << dp[N][4] << endl;
	return 0;
}