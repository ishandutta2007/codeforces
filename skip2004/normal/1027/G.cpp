#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
typedef __int128 LL;
const int mod = 998244353;
std::vector<ll> d, prm;
ll m, x;
inline void factor(ll x) {
	for(ll i = 1;i * i <= x;++i) {
		if(x % i == 0) {
			d.push_back(i);
			if(i * i != x) d.push_back(x / i);
		}
	}
	sort(d.begin(), d.end());
}
inline void fctprm(ll x) {
	for(ll i = 2;i * i <= x;++i) if(x % i == 0) {
		prm.push_back(i);
		do x /= i; while(x % i == 0);
	}
	if(x != 1) prm.push_back(x);
}
inline ll phi(ll x) {
	ll ret = x;
	for(ll i : prm) {
		if(x % i == 0) {
			ret /= i;
			ret *= i - 1;
		}
	}
	return ret;
}
inline ll pow(ll a, ll b, ll mod) {
	ll ans = 1;
	for(;b;b >>= 1, a = (LL) a * a % mod) if(b & 1) {
		ans = (LL) ans * a % mod;
	}
	return ans;
}
inline ll ln(ll x, ll mod, ll phimod) {
	ll ret = phimod;
	for(ll i : prm) while(ret % i == 0 && pow(x, ret / i, mod) == 1) 
		ret /= i;
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> x;
	factor(m);
	fctprm(m);
	fctprm(phi(m));
	sort(prm.begin(), prm.end());
	prm.erase(unique(prm.begin(), prm.end()), prm.end());
	ll ans = 1;
	for(ll gcd : d) if(gcd != m) {
		ll mod = m / gcd, cnt = phi(mod);
		ans += cnt / ln(x % mod, mod, cnt);
	}
	cout << ans << '\n';
}