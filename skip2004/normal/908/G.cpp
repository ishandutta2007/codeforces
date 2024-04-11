#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 710;
const int mod = 1e9 + 7;
ll sum = 0;
char s[maxn];
int cnt[10];

int dp[10][maxn][maxn], pw[maxn];
inline int calc(int x, int gx, int rem) {
	if(~dp[x][gx][rem]) return dp[x][gx][rem];
	if(rem == 0) return pw[gx];
	return dp[x][gx][rem] = ( (ll) calc(x, gx + 1, rem - 1) * (10 - x) + (ll) calc(x, gx, rem - 1) * x) % mod;
}

inline int calc(int rem) {
	ll sum = 0;
	for(int k = 9, p = 0;k >= 1;--k) sum += calc(k, p += cnt[k], rem);
	return sum % mod;
}
int main() {
	memset(dp, -1, sizeof dp);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> s + 1;
	int n = strlen(s + 1);
	*pw = 0;
	for(int i = 1;i <= n;++i) pw[i] = (pw[i - 1] * 10ll + 1) % mod;
	for(int i = 1;i <= n;++i) {
		for(int j = 0;j < s[i] - '0';++j) {
			++ cnt[j];
			sum += calc(n - i);
			-- cnt[j];
		}
		++ cnt[s[i] - '0'];
	}
	sum += calc(0);
	cout << sum % mod << '\n';
}