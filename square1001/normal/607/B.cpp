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
	vector<vector<int> > dp(N + 1, vector<int>(N + 1, inf));
	for (int i = 0; i <= N; ++i) {
		dp[i][i] = 1;
		if (i < N) dp[i][i + 1] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= N - i; ++j) {
			if (A[j] == A[j + i - 1]) dp[j][j + i] = min(dp[j][j + i], dp[j + 1][j + i - 1]);
			for (int k = j + 1; k < j + i; ++k) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i]);
			}
		}
	}
	cout << dp[0][N] << endl;
	return 0;
}