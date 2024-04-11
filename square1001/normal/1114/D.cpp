#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<int> rle;
	for (int i = 1; i <= N; ++i) {
		if (i == N || A[i] != A[i - 1]) {
			rle.push_back(A[i - 1]);
		}
	}
	N = rle.size();
	vector<vector<int> > dp(N, vector<int>(N + 1));
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= N - i; ++j) {
			dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
			if (rle[j] == rle[j + i - 1]) dp[j][j + i] = max(dp[j][j + i], dp[j + 1][j + i - 1] + 1);
		}
	}
	cout << N - dp[0][N] - 1 << endl;
	return 0;
}