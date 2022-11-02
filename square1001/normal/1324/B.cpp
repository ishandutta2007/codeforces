#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		bool ok = false;
		vector<vector<bool> > dp(N + 1, vector<bool>(N + 1, false));
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (A[i] == A[j]) {
					if (j - i >= 2) ok = true;
					dp[i][j] = true;
				}
			}
		}
		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j <= N - i; ++j) {
				if (dp[j][j + i - 1]) dp[j][j + i] = true;
				if (dp[j + 1][j + i]) dp[j][j + i] = true;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (A[i] == A[j] && dp[i + 1][j]) {
					ok = true;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}