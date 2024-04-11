#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 1e9 + 7;
const int inv6 = (mod + 1) / 6;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
ll m;
inline ll pre3(ll x) {
	return x * (x + 1) % mod * (2 * x + 1) % mod * inv6 % mod;
}
inline ll calc(ll x) {
	static const int m = ::m % mod;
	return (ll(x + m) * (m - x + 1 + mod + mod) / 2 % mod * (m + 1) + mod - pre3(m) + pre3(x - 1)) % mod;
}
ll fac[10], ifac[10];
inline ll _calc(ll x, ll v) {
	x %= mod, v %= mod; ll sx = x * x % mod;
	ll val[] = {
		calc(sx),
		(val[0] + calc(sx + 1 * 1) * 2) % mod, 
		(val[1] + calc(sx + 2 * 2) * 2) % mod, 
		(val[2] + calc(sx + 3 * 3) * 2) % mod, 
		(val[3] + calc(sx + 4 * 4) * 2) % mod, 
		(val[4] + calc(sx + 5 * 5) * 2) % mod, 
		(val[5] + calc(sx + 6 * 6) * 2) % mod, 
		(val[6] + calc(sx + 7 * 7) * 2) % mod, 
	};
	ll s[8] = {}, p = 1;
	for(int i = 0;i < 8;++i) {
		s[i] = (ll) ifac[i] * ifac[7 - i] % mod * val[i] % mod * p % mod;
		p = p * (v - i) % mod;
	}
	p = 1;
	ll ret = 0;
	for(int i = 7;i >= 0;--i) {
		ret += i & 1 ? p * s[i] : -p * s[i];
		p = p * (v - i) % mod;
	}
	return ret % mod;
}
int main() {
	ifac[0] = fac[0] = 1;
	for(int i = 1;i < 10;++i) fac[i] = fac[i - 1] * i, ifac[i] = inverse(fac[i]);
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m;
	ll ans = _calc(0, sqrtl(m));
	for(ll i = 1;i * i <= m;++i) if(i * i <= m) {
		ans += _calc(i, sqrtl(m - i * i)) << 1;
	}
	cout << (ans % mod + mod) % mod << '\n';
}