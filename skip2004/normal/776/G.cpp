#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
ll dp[23][23][1 << 16];
int a[maxn], tot;
inline ll dfs(int bit, int max, int set, bool high) {
	if(bit == -1) return set >> max & 1;
	if(!high && ~dp[bit][max][set]) return dp[bit][max][set];
	ll ans = 0;
	for(int i = 0;i <= (high ? a[bit] : 15);++i) {
		int s = set; if(bit < 4) s |= i << bit * 4;
		ans += dfs(bit - 1, std::max(i, max), s, high && i == a[bit]);
	}
	if(!high) dp[bit][max][set] = ans;
	return ans;
}
inline ll calc(ll x) {
	if(x < 0) return 0;
	for(tot = 0;x;x >>= 4) a[tot++] = x & 15;
	return dfs(tot - 1, 0, 0, 1);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int q;
	memset(dp, -1, sizeof dp);
	cin >> q;
	for(;q--;) {
		ll l, r;
		cin >> std::hex >> l >> std::hex >> r;
		cout << calc(r) - calc(l - 1) << '\n';
	}
}