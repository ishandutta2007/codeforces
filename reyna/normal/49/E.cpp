//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 304;
int can1[N][N],can2[N][N];
int mp[N][N];
void solve(string s,int n,int can[N][N]) {
	for (int i = 0; i < n; ++i) can[i][i] = 1 << (s[i] - 'a');
	for (int sz = 1; sz < n; ++sz) {
		for (int l = 0; l + sz < n; ++l) {
			int r = l + sz;
			for (int k = l; k < r; ++k) {
				for (int i = 0; i < 26; ++i) {
					if(can[l][k] >> i & 1) {
						for (int j = 0; j < 26; ++j) {
							if(can[k+1][r] >> j & 1) {
								can[l][r] |= mp[i + 'a'][j + 'a'];
							}
						}
					}
				}
			}
		}
	}
	return;
}
int dp[N][N];
int main() {
	string s,t; cin >> s >> t;
	int n = s.size(),m = t.size();
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		string p; cin >> p;
		mp[p[3]][p[4]] |= 1 << (p[0] - 'a');
	}
	solve(s,n,can1);
	solve(t,m,can2);
	memset(dp,31,sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int l = 0; l < i; ++l) {
			for (int j = 0; j <= m; ++j) {
				for (int r = 0; r < j; ++r) {
					if(can1[l][i-1] & can2[r][j-1]) {
						dp[i][j] = min(dp[i][j],dp[l][r] + 1);
					}
				}
			}
		}
	}
	cout << (dp[n][m] > 100 ? -1 : dp[n][m])<< endl;
}