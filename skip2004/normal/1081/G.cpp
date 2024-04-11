#include<bits/stdc++.h>
#define pb push_back
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;

const int maxn = 100100;
int n, k, mod, inv2;

inline void reduce(int & x) {
	x += x >> 31 & mod;
}
inline void add(int & x, int y) {
	x += y - mod, x += x >> 31 & mod;
}
inline void sub(int & x, int y) {
	x -= y, x += x >> 31 & mod;
}
inline void fma(int & x, int y, int z) {
	x = (x + (ll) y * z) % mod;
}
inline void up(int & x, int y) {
	if(x < y) x = y;
}
inline void down(int& x, int y) {
	if(x > y) x = y;
}
template<const int *a>
inline int cmp(const int & x, const int & y) {
	return a[x] < a[y];
}

std::map<int, int> map;
void solve(int l, int r, int k) {
	if(l == r || k == 1) {
		++ map[r - l + 1];
		return ;
	}
	int mid = l + r >> 1;
	solve(l, mid, k - 1);
	solve(mid + 1, r, k - 1);
}
int inv[maxn];

inline int calc(int n, int m) {
	ll ans = (ll) n * m % mod * inv2 % mod;
	for(int i = 2;i <= n + m;++i) {
		const int L = std::max(1, i - n), R = std::min(m, i - 1);
		ans = (ans - (ll) (R - L + 1) * inv[i]) % mod;
	}
	return ans + (ans >> 63 & mod);
}

inline void print(int x) {
	for(int i = 1;i <= 1000;++i) {
		if((ll) x * i % mod <= 1000) {
			cout << (ll) x * i % mod << '/' << i << std::endl;
			return ;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> mod, inv2 = mod + 1 >> 1;
	inv[1] = 1;
	for(int i = 2;i <= n;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
	}
	solve(1, n, k);
	int ans = 0;
	for(auto i : map) {
		fma(ans, i.second, i.first * (i.first - 1ull) / 2 % mod * inv2 % mod);
	}
//	print(ans);
	for(auto i = map.begin();i != map.end();++i) {
		for(auto j = map.begin();j != i;++j) {
			ans = (ans + (ll) i -> second * j -> second % mod * calc(i -> first, j -> first)) % mod;
		}
		ans = (ans + (ll) i -> second * (i -> second - 1) / 2 % mod * calc(i -> first, i -> first)) % mod;
	}
//	print(ans);
//	print(449209967);
	cout << ans << '\n';
}