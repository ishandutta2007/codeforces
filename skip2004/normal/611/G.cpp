#include<bits/stdc++.h>
const int maxn = 500200;
const int mod = 1e9 + 7;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
int n;
int x[maxn], y[maxn];
inline ll cross(int a,int b,int c) {
	return ll(x[c] - x[a]) * (y[b] - y[a]) - ll(x[b] - x[a]) * (y[c] - y[a]);
}
inline int nxt(int x) { return x == n - 1 ? 0 : x + 1; }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for(int i = 0;i < n;++i) std::cin >> x[i] >> y[i];
	ll s = 0, now = 0, ans = 0, sum = 0;
	ll sx = x[0], sy = y[0];
	for(int i = 2;i < n;++i) s += cross(0, i - 1, i);
	for(int i = 0,j = 0;i < n;++i) {
		sx -= x[i], sy -= y[i];
		for(;;j = nxt(j), sx += x[j], sy += y[j]) {
			ll o = now + cross(i, j, nxt(j));
			if((unsigned long long) o + o >= s) break;
			now = o; sum = (sum + now) % mod;
		}
		int cnt = (j - i + n) % n;
		ans = (ans + s % mod * (cnt - 1) - sum * 2) % mod;
		ll x0 = (sx - (ll) x[i] * cnt) % mod, y0 = (sy - (ll) y[i] * cnt) % mod;
		ll x1 = (x[nxt(i)] - x[i]) % mod, y1 = (y[nxt(i)] - y[i]) % mod;
		sum = (sum + x1 * y0 - x0 * y1) % mod;
		now -= cross(i, i + 1, j);
	}
	std::cout << (ans + mod) % mod << '\n';
}