#include <bits/stdc++.h>
#define MX 200005
using namespace std;

#define endl '\n'

int a[MX], dp[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int tc; cin >> tc;
	while (tc --){
		int n; cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i <= n; i ++) {
			if (i - a[i] >= 1 && dp[i - a[i] - 1]) dp[i] = 1;
			if (dp[i] && i + 1 + a[i + 1] <= n) dp[i + 1 + a[i + 1]] = 1;
		}
		if (dp[n]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}