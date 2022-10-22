#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
typedef long long ll;

int n, mod, l, r;

int p[100], tot;
inline void exgcd(int a, int b, int & x, int & y) {
	if(!a) {
		x = 0, y = 1;
		return ;
	}
	exgcd(b % a, a, y, x);
	x -= b / a * y;
}
inline int inv(int x) {
	int a, b;
	exgcd(x, mod, a, b);
	return a < 0 ? a + mod : a;
}
inline int pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}

struct modint
{
	int val;
	int power[10];
	inline modint() { }
	inline int eval() const {
		int res = val;
		for(int i = 0;i < tot;++i) {
			if(power[i]) res = (ll) res * pow(p[i], power[i]) % mod;
		}
		return res;
	}
	inline modint(int x) {
		for(int i = 0;i < tot;++i) {
			power[i] = 0;
			while(x % p[i] == 0) {
				++ power[i];
				x /= p[i];
			}
		}
		val = x;
	}
};

inline void factor(int x) {
	for(int i = 2;i * i <= x;++i) {
		if(x % i == 0) {
			p[tot ++] = i;
			do {
				x /= i;
			} while(x % i == 0);
		}
	}
	if(x != 1) {
		p[tot ++] = x;
	}
}

inline modint const mul(modint const& x, modint const& y) {
	modint res;
	res.val = (ll) x.val * y.val % mod;
	for(int i = 0;i < 10;++i) {
		res.power[i] = x.power[i] + y.power[i];
	}
	return res;
}
inline modint const inv(modint x) {
	x.val = inv(x.val);
	for(int i = 0;i < 10;++i) x.power[i] = - x.power[i];
	return x;
}
modint fac[maxn], ifac[maxn];


inline int c(int n, int m) {
	if(m < 0) return 0;
	return mul(mul(fac[n], ifac[m]), ifac[n - m]).eval();
}
inline unsigned calc(int n) {
	return c(n, n - l >> 1) - c(n, n - r - 1 >> 1) + mod;
}
int main()
{
	cin >> n >> mod >> l >> r;
	factor(mod);
	ifac[0] = fac[0] = 1;
	for(int i = 1;i <= n;++i) {
		fac[i] = mul(fac[i - 1], i);
		ifac[i] = inv(fac[i]);
	}
	int ans = 0;
	for(int i = l;i <= n;++i) {
		ans = (ans + (ll) c(n, i) * calc(i)) % mod;
	}
	cout << ans << '\n';
}