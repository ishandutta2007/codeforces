#include <iostream>
#include <algorithm>
using namespace std;
int N; double prob[69][69], win[9][69], dp[9][69];
int main() {
	cin >> N;
	for (int i = 0; i < 1 << N; ++i) {
		for (int j = 0; j < 1 << N; ++j) {
			cin >> prob[i][j];
			prob[i][j] *= 0.01;
		}
		win[0][i] = 1;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 1 << N; j += (2 << i)) {
			for (int k = j; k < j + (1 << i); ++k) {
				for (int l = j + (1 << i); l < j + (2 << i); ++l) {
					win[i + 1][k] += win[i][k] * win[i][l] * prob[k][l];
					win[i + 1][l] += win[i][l] * win[i][k] * prob[l][k];
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 1 << N; j += (2 << i)) {
			for (int k = j; k < j + (1 << i); ++k) {
				for (int l = j + (1 << i); l < j + (2 << i); ++l) {
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][k] + dp[i][l] + win[i + 1][k] * (1 << i));
					dp[i + 1][l] = max(dp[i + 1][l], dp[i][l] + dp[i][k] + win[i + 1][l] * (1 << i));
				}
			}
		}
	}
	double ans = *max_element(dp[N], dp[N] + (1 << N));
	cout.precision(15);
	cout << ans << endl;
	return 0;
}