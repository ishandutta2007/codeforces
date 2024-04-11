#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
using u64 = unsigned long long;
const int N = 100005;
const int mod = 998244353;
int t, n, a[N];
int fac[N], ifac[N], inv[N];
inline int comb(int n, int m) {
	return (u64) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
inline int calc(int a, int b) {
	ll res = 0;
	for(int i = 0;i <= a && i <= b;++i) {
		res = (res + (u64) comb(a, i) * comb(b, i)) % mod;
	}
	return res;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < N;++i) {
		inv[i] = u64(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (u64) fac[i - 1] * i % mod;
		ifac[i] = (u64) ifac[i - 1] * inv[i] % mod;
	}
	for(int i = 0;i < t;++i) {
		cin >> n;
		ll sum = 0, su = 0;
		std::map<ll, int> map;
		for(int i = 1;i <= n;++i) {
			cin >> a[i];
			sum += a[i];
			su += a[i];
			if(i < n) map[su] += 1;
		}
		using pr = std::pair<int, int>;
		std::vector<int> cnts;
		ll ans = 1;
		for(auto x : map) {
			if(x.first * 2 < sum) {
				auto p = map.find(sum - x.first);
				if(p != map.end()) {
					ans = (u64) ans * calc(x.second, p -> second) % mod;
				}
			}
		}
		for(int i = sum & 1 ? 0 : map[sum / 2];i;--i) ans = ans * 2 % mod;
		cout << ans << '\n';
	}
}