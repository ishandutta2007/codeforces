#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
int dp[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		int x; cin >> x;
		dp[x] = x;
	}
	for(int i = 1; i < N; i ++)
		dp[i] = max(dp[i], dp[i - 1]);

	int ans = 0;
	for(int i = 1; i < N; i ++) if(dp[i] == i) {
		for(int j = 2 * i; j < N + i; j += i)
			ans = max(ans, dp[min(j - 1, N - 1)] - (j - i));
	}
	cout << ans << '\n';
	return 0;
}