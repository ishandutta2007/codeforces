#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 10;
ll dp[MAXN][2], A[MAXN], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i < n; i++) {
		if (A[i] >= A[i - 1]) dp[i][1] = max(dp[i - 1][1] + A[i] - A[i - 1], dp[i - 1][0]), dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		else dp[i][0] = max(dp[i - 1][0] + A[i - 1] - A[i], dp[i - 1][1]), dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	return 0;
}