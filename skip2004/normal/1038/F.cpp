#include<bits/stdc++.h>
const int maxn = 50;
int n, m;
char s[maxn];

int fail[maxn];
int go[maxn][2];

typedef long long ll;
ll dp[maxn][maxn][maxn];

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> s + 1;
	m = strlen(s + 1);
	for(int i = 1;i <= m;++i) s[i] &= 1;
	for(int i = 0;i < m;++i) {
		fail[i + 1] = go[fail[i]][s[i + 1]];
		go[i][s[i + 1]] = i + 1;
		go[i][s[i + 1] ^ 1] = go[fail[i]][s[i + 1] ^ 1];
	}
	ll ans = 1ll << n;
	for(int i = 0;i < m;++i) {
		memset(dp, 0, sizeof dp);
		dp[0][i][0] = 1;
		for(int j = 0;j < n;++j) {
			for(int k = 0;k < m;++k) {
				for(int l = 0;l < m;++l) {
					dp[j + 1][go[k][0]][go[l][0]] += dp[j][k][l];
					dp[j + 1][go[k][1]][go[l][1]] += dp[j][k][l];
				}
			}
		}
		for(int j = 0;j < m;++j) ans -= dp[n][j][i];
	}
	std::cout << ans << '\n';
}