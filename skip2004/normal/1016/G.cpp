#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
int n;
ll x, y;
std::vector<ll> p = {2, 3};
inline void fwt(int * a, int lim) {
	if(lim == 1) return ;
	lim >>= 1;
	for(int i = 0;i < lim;++i) a[i] += a[i + lim];
	fwt(a, lim), fwt(a + lim, lim);
}
inline std::map<ll, int> factor(ll x) {
	std::map<ll, int> map;
	for(ll i : p) {
		if(x % i == 0) {
			int&cnt = map[i] = 0;
			do {
				x /= i;
				++ cnt;
			} while(x % i == 0);
		}
	}
	if(x != 1) {
		map[x] += 1;
	}
	return map;
}
inline ll solve(std::vector<ll> v, ll x, ll y) {
	for(int i = 5;i <= 1e6;i += 2) {
		p.push_back(i);
		p.push_back(i + 2);
	}
	for(ll i : v) {
		ll o = std::__gcd(i, x);
		if(o != 1 && o != y) {
			p.push_back(o);
		}
		o = std::__gcd(i, y);
		if(o != 1 && o != y) {
			p.push_back(o);
		}
	}
	sort(p.begin(), p.end()), p.erase(unique(p.begin(), p.end()), p.end());
	auto vc = factor(y);
	p = {};
	for(auto i : vc) p.push_back(i.first);
	auto vx = factor(x);
	std::vector<ll> p0;
	for(auto i : p) {
		if(vx[i] != vc[i]) {
			p0.push_back(i);
		}
	}
	std::vector<int> v0, v1;
	for(ll i : v) {
		auto fc = factor(i);
		if(i % x == 0) {
			int s = 0, idx = 0;
			for(ll i : p0) {
				if(fc[i] != vx[i]) {
					s |= 1 << idx;
				}
				++ idx;
			}
			v0.push_back(s);
		}
		if(y % i == 0) {
			int s = 0, idx = 0;
			for(ll i : p0) {
				if(fc[i] != vc[i]) {
					s |= 1 << idx;
				}
				++ idx;
			}
			v1.push_back(s);
		}
	}
	std::vector<int> b0(1 << 18), b1(1 << 18);
	for(int i : v0) {
		++ b0[i];
	}
	for(int i : v1) {
		++ b1[i];
	}
	fwt(b0.data(), 1 << 18);
	fwt(b1.data(), 1 << 18);
	ll ans = 0;
	for(int i = 0;i < 1 << 18;++i) {
		if(__builtin_popcount(i) & 1) {
			ans -= (ll) b0[i] * b1[i];
		} else {
			ans += (ll) b0[i] * b1[i];
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	std::vector<ll> v;
	cin >> n >> x >> y;
	if(y % x) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0;i < n;++i) {
		ll z;
		cin >> z;
		v.push_back(z);
	}
	cout << solve(v, x, y) << '\n';
}