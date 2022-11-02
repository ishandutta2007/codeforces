#include <bits/stdc++.h>
using namespace std;

const int N = 111;
using ll = long long;
ll dp[N][4];
ll solve(string s, int type) {
	int n = s.size();
	memset(dp, 0, sizeof(dp));
	if(!type) dp[0][0] = 1;
	else dp[0][3] = 1;
	for(int i = 1; i < n; i ++) {
		if(s[i - 1] == 'A' && s[i] == 'B') {
			dp[i][1] += dp[i - 1][0];
			dp[i][1] += dp[i - 1][3];
			dp[i][2] += dp[i - 1][0];
		}
		else if(s[i - 1] == 'B' && s[i] == 'A') {
			dp[i][3] += dp[i - 1][2];
			dp[i][0] += dp[i - 1][1];
		} else if(s[i - 1] == 'B' && s[i] == 'B') {
			dp[i][2] += dp[i - 1][2];
			dp[i][1] += dp[i - 1][2];
		} else {
			dp[i][3] += dp[i - 1][3];
			dp[i][3] += dp[i - 1][0];
		}
	}
	if(!type) return dp[n - 1][1];
	else return dp[n - 1][2];
}

int main() {
	ios :: sync_with_stdio(false);
	string s; cin >> s;
	if(!count(s.begin(), s.end(), 'A') ||
		!count(s.begin(), s.end(), 'B'))
		cout << "1\n";
	else {
		int n = s.size();
		for(int i = 0; i < n; i ++)
			if(s[i] == 'A' && s[(i - 1 + n) % n] == 'B') {
				rotate(s.begin(), s.begin() + i, s.end());
				break;
			}
		cout << solve(s, 0) + solve(s, 1) << '\n';
	}
	return 0;
}