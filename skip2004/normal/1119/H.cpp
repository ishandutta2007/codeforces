#include<bits/stdc++.h>
const int maxn = 1 << 17;
using i64 = long long;
using std::cin;
using std::cout;
const int mod = 998244353;
const i64 inv2 = mod + 1 >> 1;
int n, k;
i64 x, y, z;
i64 c0[maxn], c1[maxn], c2[maxn], res[maxn];
inline i64 pow(i64 a, i64 b, i64 ans = 1) {
	for(;b;b >>= 1, a = (i64) a * a % mod) if(b & 1)
		ans = (i64) ans * a % mod;
	return ans;
}
inline void fwt(i64 * a, int lim) {
	lim >>= 1;
	if(lim == 0) return ;
	for(int i = 0;i < lim;++i) {
		const i64 t = a[i + lim];
		a[i + lim] = a[i] - t; 
		a[i] += t;
	}
	fwt(a, lim), fwt(a + lim, lim);
}
int main() {
	cin >> n >> k;
	cin >> x >> y >> z;
	int all = 0;
	for(int i = 0, a, b, c;i < n;++i) {
		cin >> a >> b >> c;
		all ^= a, b ^= a, c ^= a;
		++ c0[b];
		++ c1[c];
		++ c2[b ^ c];
	}
	fwt(c0, 1 << k), fwt(c1, 1 << k), fwt(c2, 1 << k);
	x %= mod;
	y %= mod;
	z %= mod;
	i64 a0 = (mod + mod + x + y + z) % mod;
	i64 a1 = (mod + mod + x + y - z) % mod;
	i64 a2 = (mod + mod + x - y + z) % mod;
	i64 a3 = (mod + mod + x - y - z) % mod;
	for(int i = 0;i < 1 << k;++i) {
		if(n + c0[i] + c1[i] + c2[i] & 3)
			exit(1);
		i64 c = (n + c0[i] + c1[i] + c2[i]) / 4;
		res[i] = pow(a0, c) * pow(a1, (n + c0[i] - c - c) / 2) % mod * 
				pow(a2, (n + c1[i] - c - c) / 2) % mod * pow(a3, (n + c2[i] - c - c) / 2) % mod;
	}
	fwt(res, 1 << k);
	i64 inv = pow(inv2, k);
	for(int i = 0;i < 1 << k;++i) {
		cout << int(res[all ^ i] % mod * inv % mod + mod) % mod << ' ';
	}
}