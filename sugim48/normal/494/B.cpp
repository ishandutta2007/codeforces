#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

vector<ll> rolliha(string& s) {
	int n = s.length();
	vector<ll> h(n + 1);
	ll x = 1;
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + (s[i] - 'a' + 29) * x) % MOD;
		x = x * 55 % MOD;
	}
	return h;
}

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	int lower_bound(ll x) {
		if (x <= 0) return 0;
		int res = 0;
		for (int i = 1 << 24; i > 0; i >>= 1)
			if (res + i < v.size() && v[res + i] < x) {
				res += i; x -= v[res];
			}
		return res + 1;
	}
};

int main() {
	string s, t; cin >> s >> t;
	int S = s.length(), T = t.length();
	if (S < T) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> hs = rolliha(s), ht = rolliha(t);
	vector<ll> a(S - T + 1);
	ll x = 1;
	for (int i = 0; i + T <= S; i++) {
		a[i] = (hs[i + T] - hs[i] + MOD) * mod_inverse(x, MOD) % MOD;
		x = x * 55 % MOD;
	}
	bit b(S - T + 1);
	for (int i = 0; i < S - T + 1; i++)
		if (a[i] == ht[T])
			b.add(i, 1);
	vector<ll> dp(S + 1);
	bit c(S + 1);
	for (int i = T; i <= S; i++) {
		int s = b.sum(i - T + 1);
		if (s == 0) continue;
		int j = b.lower_bound(s);
		dp[i] = (dp[i - 1] + j + c.sum(j)) % MOD;
		c.add(i, dp[i]);
	}
	cout << dp[S] << endl;
}