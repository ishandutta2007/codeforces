#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1100100;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int fac[maxn], ifac[maxn], inv[maxn];
inline int c(int n, int m) {
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
ll cnt[maxn];
int k;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	cin >> k;
	for(int i = 0, x;i < k;++i) {
		cin >> x; ++ cnt[x];
	}
	for(int i = 0;i < k;++i) {
		for(int j = i + k;j < maxn;j += k) {
			cnt[j] += cnt[j - k];
		}
	}
	int end = -1;
	for(int j = 1;j + 1 < maxn;++j) {
		cnt[j] += cnt[j - 1];
		if(cnt[j - 1] > j) {
			end = j;
			break;
		}
	}
	ll ans = 0;
	if(end > 0) {
		ans = 1;
		for(int i = 1;i < end;++i){ 
			ans += c(i - cnt[i - 1] + k - 1, k - 1);
		}
	} else {
		for(int i = 1e6 + 1 - k;i < 1e6 + 1;++i) {
			ans += c(i - cnt[i - 1] + k - 1, k - 1);
		}
	}
	cout << ans % mod << '\n';
}