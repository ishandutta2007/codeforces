#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200;
typedef long long ll;
const int mod = 998244353;
int dp[maxn][maxn][maxn][2];
int n;
char s[maxn];
int sv, sk, sx;
inline int calc(int a, int b, int c, char need) {
	rep(i, 1, n) {
		if(s[i] == 'V') {
			-- a;
			if(s[i] == need && a < 0) return std::max(-b, 0) + std::max(-c, 0);
		} else if(s[i] == 'K') {
			-- b;
			if(s[i] == need && b < 0) return std::max(-a, 0) + std::max(-c, 0);
		} else {
			-- c;
			if(s[i] == need && c < 0) return std::max(-a, 0) + std::max(-b, 0);
		}
	}
	return 1e9;
}
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> s + 1;
	rep(i, 1, n) {
		if(s[i] == 'V') {
			++ sv;
		} else if(s[i] == 'K') {
			++ sk;
		} else {
			s[i] = ' ';
			++ sx;
		}
	}
	rep(i, 0, sv) rep(j, 0, sk) rep(k, 0, sx) dp[i][j][k][0] = dp[i][j][k][1] = 1e9;
	dp[0][0][0][0] = 0;
	rep(i, 0, sv) rep(j, 0, sk) rep(k, 0, sx) rep(l, 0, 1) {
		down(dp[i + 1][j][k][1], dp[i][j][k][l] + calc(i, j, k, 'V'));
		if(!l)
		down(dp[i][j + 1][k][0], dp[i][j][k][l] + calc(i, j, k, 'K'));
		down(dp[i][j][k + 1][0], dp[i][j][k][l] + calc(i, j, k, ' '));
	}
	cout << std::min(dp[sv][sk][sx][0], dp[sv][sk][sx][1]) << '\n';
}