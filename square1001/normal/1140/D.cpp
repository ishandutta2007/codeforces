#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<long long> > dp(N, vector<long long>(N + 1));
	for (int i = 2; i <= N; ++i) {
		for (int l = 0; l <= N - i; ++l) {
			int r = l + i;
			dp[l][r] = 1LL << 62;
			for (int j = l + 1; j < r; ++j) {
				dp[l][r] = min(dp[l][r], dp[l][j] + dp[j][r] + 1LL * (l + 1) * (j + 1) * (r == N ? 1 : r + 1));
			}
		}
	}
	cout << dp[0][N - 1] << endl;
	return 0;
}