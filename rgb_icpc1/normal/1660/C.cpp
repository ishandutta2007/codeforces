#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;
int dp[30];
char s[MX];
#define inf 100000000

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		cin >> s;
		int n = strlen(s);
		for (int i = 0; i < 26; i ++) dp[i] = inf;
		dp[26] = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 26; j ++) {
				if (s[i] - 'a' == j) {
					int val = dp[26];
					dp[26] = min (dp[26] + 1, dp[j]);
					dp[j] = min (val, dp[j] + 1);
				}
				else {
					dp[j] ++;
				}
			}
		}
		cout << dp[26] << endl;
	}

	return 0;
}