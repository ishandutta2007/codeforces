#include <bits/stdc++.h>

using namespace std;

int n, a, b;
string s;

const int mod = 1000000009;
const int p = 31;

// map<int, int> indo;

int ch[5005][5005];
int indo[5005][5005];

int dp[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;
	// string s;
	cin >> s;
	s  = " " + s;

	for (int i = 1; i <= n; i++) {
		int ha = 0;

		int cspot = 1;
		for (int j = i; j <= n; j++) {
			ha = (ha*31)%mod;
			ha = (ha + s[j]-'a'+1)%mod;

			ch[i][j] = ha;

			while (ch[cspot][cspot + j-i] != ha) {
				++cspot;
			}

			indo[i][j] = cspot;
		}
	}

	fill(dp, dp+5005, 1000000000);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = min(dp[i], dp[i-1] + a);
		for (int j = i; j >= 1; j--) {
			int cv = indo[j][i];

			if (cv + i - j < j) {
				dp[i] = min(dp[i], b + dp[j-1]);
			}
		}
	}

	cout << dp[n];
}