#include <bits/stdc++.h>
using namespace std;

#define op operator

using ll = long long;
const ll mod = 1e9L + 7;

const int N = 211;
ll c[N][N];

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

struct num {
	ll a, b;
	void w() { cout << a << ' ' << b << '\n'; }
	num op -(num x) {
		return {a - x.a, b - x.b};
	}
	num op +(num x) {
		return {a + x.a, b + x.b};
	}
	num op *(num x) {
		num r = {a * x.a + 5 * b * x.b, a * x.b + b * x.a};
		r.a %= mod; r.b %= mod;
		return r;
	}
	num op /(num x) {
		return (*this) * num{x.a, -x.b} *
			num{qpow((x.a * x.a - 5 * x.b * x.b) % mod, mod - 2), 0};
	}
};

num qpow(num a, ll b) {
	num r = {1, 0};
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

ll fsum(ll n, int k) {
	num r = {0, 0};
	ll inv2 = qpow(2, mod - 2), inv5 = qpow(5, mod - 2);
	num a = {inv2, inv2}, b = {inv2, -inv2};
	for(int i = 0; i <= k; i ++) {
		num q = qpow(a, i) * qpow(b, k - i);
		q.a = (q.a % mod + mod) % mod;
		q.b = (q.b % mod + mod) % mod;
		num sp = num{c[k][i] * (((k - i) & 1) ? -1 : 1), 0} * qpow(num{0, inv5}, k);
		num t = (num{1, 0} - qpow(q, n + 1)) / (num{1, 0} - q);
		if(q.a == 1 && q.b == 0)
			t = {(n + 1) % mod, 0};
		r = r + (sp * t);
	}
	return r.a % mod;
}

ll dp[N][N];

int main() {
	for(int i = 0; i < N; i ++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	int k; cin >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= k; i ++)
		for(int j = 0; j < i; j ++) {
			dp[i][j] -= (i - 1) * dp[i - 1][j];
			dp[i][j + 1] += dp[i - 1][j];
			dp[i][j] %= mod;
			dp[i][j + 1] %= mod;
		}
	ll l, r; cin >> l >> r;
	l += 2; r += 2;
	ll ans = 0;
	for(int i = 0; i <= k; i ++) {
		for(int j = 1; j <= k; j ++) {
			dp[k][i] *= qpow(j, mod - 2);
			dp[k][i] %= mod;
		}
		ans += dp[k][i] * fsum(r, i);
		ans -= dp[k][i] * fsum(l - 1, i);
		ans %= mod;
	}
	cout << (ans + mod) % mod << '\n';
}