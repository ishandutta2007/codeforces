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
	int N, M;
	cin >> N >> M;
	vector<long long> L(M);
	for (int i = 0; i < M; ++i) {
		cin >> L[i];
	}
	vector<long long> dp(M);
	dp[M - 1] = N - L[M - 1] + 1;
	for (int i = M - 2; i >= 0; --i) {
		dp[i] = min(dp[i + 1] - 1, N - L[i] + 1);
	}
	long long sum = 0;
	for (int i = 0; i < M; ++i) {
		sum += L[i];
	}
	if (dp[0] <= 0 || sum < N) {
		cout << -1 << endl;
	}
	else {
		long long s = 1;
		for (int i = 0; i < M; ++i) {
			if (i) cout << ' ';
			cout << min(s, dp[i]);
			s += L[i];
		}
		cout << endl;
	}
	return 0;
}