#include<bits/stdc++.h>
const int maxn = 100100;
typedef long long ll;

using std::cin;
using std::cout;
using std::endl;
int n, q, mod;
int st[50], top;
int w[maxn];
inline int phi(int x) {
	int res = x;
	for(int i = 2;i * i <= x;++i) if(x % i == 0) {
		res = res / i * (i - 1);
		for(;x % i == 0;) x /= i;
	}
	if(x > 1) res = res / x * (x - 1);
	return res;
}
inline int get(int x, int mod) { return x >= mod ? x % mod + mod : x; }
inline int get(ll x, int mod) { return x >= mod ? x % mod + mod : x; }
inline int pow(int a, int b, int mod, int ans = 1) {
	for(;b;b >>= 1, a = get((ll) a * a, mod)) if(b & 1)
		ans = get((ll) ans * a, mod);
	return ans;
}
inline int getpow(int l, int r, int *mod) {
	if(l == r || *mod == 1) return get(w[l], mod[0]);
	return pow(w[l], getpow(l + 1, r, mod + 1), mod[0]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> mod;
	st[1] = mod;
	for(top = 2;st[top - 1] != 1;++top) {
		st[top] = phi(st[top - 1]);
	}
	for(int i = 1;i <= n;++i) {
		cin >> w[i];
	}
	cin >> q;
	for(int i = 1, l, r;i <= q;++i) {
		cin >> l >> r;
		cout << getpow(l, r, st + 1) % mod << '\n';
	}
}