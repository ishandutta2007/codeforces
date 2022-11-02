#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, H, L, R;
	cin >> N >> H >> L >> R;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> dp(H, -inf);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<int> ndp(H, -inf);
		for (int j = 0; j < H; ++j) {
			for (int k = -1; k <= 0; ++k) {
				int p = (j + A[i] + k) % H;
				if (L <= p && p <= R) {
					ndp[p] = max(ndp[p], dp[j] + 1);
				}
				else {
					ndp[p] = max(ndp[p], dp[j]);
				}
			}
		}
		dp = ndp;
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << endl;
	return 0;
}