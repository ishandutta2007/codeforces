#include<bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 3540;
typedef long long ll;
int p, a;
inline int calc(int x) {
	if(x <= p) return (ll) x * (x + 1) / 2 % mod;
	x = p + p - 1 - x;
	return ((ll) p * p - (ll) x * (x + 1) / 2) % mod;
}
inline int calc(int ql,int qr) {
	int ret = calc(qr + 1) - calc(ql);
	return ret + (ret >> 31 & mod);
}
ll s[maxn];
int dp[maxn][maxn][2][2];
inline int dfs(int now,int cnt,int high,int ad) {
	if(now == -1) return cnt >= a && ad == 0;
	int & ans = dp[now][cnt][high][ad];
	if(~ans) return ans;
	ans = 0;
	for(int i = 0;i < 2;++i) {
		int l = ad * p - i, r = (high ? s[now] : p - 1) + ad * p - i;
		if(high) {
			ans = (ans + (ll) dfs(now - 1, cnt + ad, 0, i) * calc(l, r - 1)) % mod;
			ans = (ans + (ll) dfs(now - 1, cnt + ad, 1, i) * calc(r, r)) % mod;
		} else {
			ans = (ans + (ll) dfs(now - 1, cnt + ad, 0, i) * calc(l, r)) % mod;
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> p >> a; std::string str; std::cin >> str;
	for(auto i : str) {
		for(int i = 0;i < maxn;++i) s[i] *= 10; s[0] += i - 48;
		for(int i = 0;i + 1 < maxn;++i) s[i + 1] += s[i] / p, s[i] %= p;
	}
	memset(dp, -1, sizeof dp);
	std::cout << dfs(maxn - 1, 0, 1, 0) << '\n';
}