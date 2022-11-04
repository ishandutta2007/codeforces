#include <bits/stdc++.h>

using namespace std;

int n, m;
string A, B;
int dp[5005][5005];

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> A >> B;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (A[i] == B[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
		dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
	}
	int mx = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) mx = max(mx, dp[i][j]);
	cout << mx << endl;
	
	return 0;
	
}