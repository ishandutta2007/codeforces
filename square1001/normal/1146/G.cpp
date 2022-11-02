#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
bool vis[55][55][55]; int dp[55][55][55];
int main() {
	int N, H, K;
	cin >> N >> H >> K;
	vector<int> L(K), R(K), X(K), C(K);
	for (int i = 0; i < K; ++i) {
		cin >> L[i] >> R[i] >> X[i] >> C[i]; --L[i];
	}
	function<int(int, int, int)> calc = [&](int l, int r, int h) {
		if (h == -1) return -inf;
		if (l == r) return 0;
		if (vis[l][r][h]) return dp[l][r][h];
		int ans = -inf;
		for (int i = l; i < r; ++i) {
			int fine = 0;
			for (int j = 0; j < K; ++j) {
				if (l <= L[j] && L[j] <= i && i < R[j] && R[j] <= r && h > X[j]) {
					fine += C[j];
				}
			}
			ans = max(ans, calc(l, i, h) + calc(i + 1, r, h) + h * h - fine);
		}
		ans = max(ans, calc(l, r, h - 1));
		vis[l][r][h] = true;
		return dp[l][r][h] = ans;
	};
	int ans = calc(0, N, H);
	cout << ans << endl;
	return 0;
}