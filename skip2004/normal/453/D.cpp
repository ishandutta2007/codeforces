#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
typedef __int128 LL;
const int N = 20;
ll e[1 << N], a[1 << N], b[N + 1];
int m, n;
ll t, mod;

inline void reduce(ll & x) {
	x += x >> 63 & mod;
}

inline ll pow(ll a, ll b, ll ans = 1) {
	for(;b;b >>= 1, a = (LL) a * a % mod) if(b & 1)
		ans = (LL) ans * a % mod;
	return ans;
}
inline void fwt(ll * a, int lim) {
	lim >>= 1;
	if(lim == 0) return ;
	for(int i = 0;i < lim;++i) {
		const ll T = a[i + lim];
		reduce(a[i + lim] = a[i] - T);
		reduce(a[i] += T - mod);
	}
	fwt(a, lim), fwt(a + lim, lim);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> m >> t >> mod, mod <<= m;
	n = 1 << m;
	for(int i = 0;i < n;++i) {
		cin >> e[i];
	}
	for(int i = 0;i <= m;++i) cin >> b[i];
	for(int i = 0;i < n;++i) {
		a[i] = b[__builtin_popcount(i)];
	}
	fwt(e, n);
	fwt(a, n);
	for(int i = 0;i < n;++i) {
		e[i] = pow(a[i], t, e[i]);
	}
	fwt(e, n);
	for(int i = 0;i < n;++i) {
		cout << int(e[i] >> m) << '\n';
	}
}