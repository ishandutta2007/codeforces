#include <bits/stdc++.h>

using namespace std;

#define INF 1000000

int main() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	s = " " + s;
	int dp[n+1];
	for (int i = 0; i<= n; i++) {
		dp[i] = INF;
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (s[i] == '0') continue;
		for (int j = i; j >= i-d && j > 0; j--) {
			if (dp[j] != INF) {
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}
	if (dp[n] == INF) {
		cout << -1 << endl;
	}
	else cout << dp[n] << endl;
	cin >> n;
}