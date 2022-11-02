#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
ll qmul(ll a, ll b, ll m) { a %= m; b %= m;
	ll r = a * b, s = ld(a) * b / m;
	return ((r - m * s) % m + m) % m;
}

ll mod;
struct mat {
	ll a[2][2];
	ll* operator [](int i) { return a[i]; }
	mat operator *(mat m) {
		mat r;
		for(int i : {0, 1}) for(int j : {0, 1}) {
			r[i][j] = 0;
			for(int k : {0, 1})
				r[i][j] += qmul(a[i][k], m[k][j], mod);
			r[i][j] %= mod;
		}
		return r;
	}
};

mat qpow(mat a, ll b) {
	mat r = a; b --;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

ll fib(ll n, ll mod) {
	if(n == 0) return 0;
	::mod = mod;
	mat m; m[0][0] = 0;
	m[0][1] = m[1][0] = m[1][1] = 1;
	return qpow(m, n)[0][1];
}

ll solve(ll x, ll b, ll &rep) {
	set <ll> st;
	for(int i = 0; i < rep; i ++)
		if(fib(i, b) == x % b) st.insert(i);
	ll tb = b;
	for(int _ = 0; _ < 12; _ ++) {
		tb *= b;
		set <ll> nxt;
		for(ll i : st) for(int j = 0; j < b; j ++) {
			ll k = rep * j + i;
			if(fib(k, tb) == x % tb)
				nxt.insert(k);
		}
		rep *= b;
		st = nxt;
	}
	if(st.size()) return *st.begin();
	return -1;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) return x = 1, y = 0, a;
	ll t = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

int main() {
	ios :: sync_with_stdio(0);
	ll x; cin >> x;

	ll rep10 = 60;
	cout << solve(x, 10, rep10) << '\n';
}