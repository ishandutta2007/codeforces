#include <bits/stdc++.h>

using namespace std;

vector <int> z_function(string s) {
	reverse(s.begin(), s.end());
	int n = s.length(), l = 0, r = 0;
	vector <int> z(n, 0);
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (z[i] + i < n && s[z[i]] == s[z[i] + i])
			z[i]++;
		if (i + z[i] - 1 > r) {
			l = i, r = i + z[i] - 1;
		}
	}
	return z;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector <int> dp(n + 1, 1e9);
	dp[0] = 0;
	string help = "";	
	for (int i = 1; i <= n; i++) {
		help += s[i - 1];
		dp[i] = min(dp[i], dp[i - 1] + a);
		vector <int> fans = z_function(help);

		int mx = 0;
		for (int j = 0; j < i; j++) {
			mx = max(mx, min(fans[j], j));
		}

		for (int j = 1; j <= mx; j++) {
			dp[i] = min(dp[i], dp[i - j] + b);
		}
	}
	cout << dp[n] << endl;
	return 0;
}

/*
3 3 1
aba
*/