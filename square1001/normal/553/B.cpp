#include <iostream>
#include <algorithm>
using namespace std;
int N, ret[55]; long long K, dp[55];
int main() {
	cin >> N >> K;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 0; i < N; ++i) {
		ret[i] = i + 1;
	}
	int pos = 0;
	while (pos != N) {
		if (K > dp[N - (pos + 1)]) {
			swap(ret[pos], ret[pos + 1]);
			K -= dp[N - (pos + 1)];
			pos += 2;
		}
		else {
			pos += 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << ret[i];
	}
	cout << '\n';
	return 0;
}