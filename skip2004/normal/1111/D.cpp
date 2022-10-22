#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
const int mod = 1e9 + 7;
typedef long long ll;
int n, q;
char s[maxn];
int cnt[maxn];
int fac[maxn];
int ifac[maxn];
int inv[maxn];
inline int trs(char x) {
	if(islower(x)) return x - 'a';
	else return x - 'A' + 26;
}
inline void add(int & x, int y) {
	x += y - mod, x += x >> 31 & mod;
}
inline void sub(int & x, int y) {
	x -= y, x += x >> 31 & mod;
}
int ans[52][52];
int dp[maxn], ddp[maxn], res;
inline void emplace(int * dp, int x) {
	if(x) for(int j = n / 2;j >= x;--j) add(dp[j], dp[j - x]);
}
inline void pop(int * dp, int x) {
	if(x) for(int j = x;j <= n / 2;++j)
		sub(dp[j], dp[j - x]);
}
inline int get(int x, int y) {
	std::tie(x, y) = std::minmax(trs(x), trs(y));
	if(~ans[x][y]) return ans[x][y];
	memcpy(ddp, dp, n / 2 + 1 << 2);
	pop(ddp, cnt[x]);
	pop(ddp, cnt[y]);
	return ans[x][y] = cnt[x] > n / 2 ? 0 : (ll) ddp[n / 2 - cnt[x] - cnt[y]] * res * 2 % mod;
}
int main() {
	memset(ans, -1, sizeof ans);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	cin >> q;
	* fac = * ifac = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i <= n;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	*dp = 1;
	res = (ll) fac[n / 2] * fac[n / 2] % mod;
	for(int i = 1;i <= n;++i) ++ cnt[trs(s[i])];
	for(int i = 0;i < 52;++i) if(cnt[i]) emplace(dp, cnt[i]), res = (ll) res * ifac[cnt[i]] % mod;
	for(int i = 1, x, y;i <= q;++i) {
		cin >> x >> y;
		if(s[x] == s[y]) {
			cout << int((ll) dp[n / 2] * res % mod) << '\n';
		} else {
			cout << get(s[x], s[y]) << '\n';
		}
	}
}