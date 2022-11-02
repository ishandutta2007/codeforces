#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

ll getMod(ll a, ll mod) {
	return (a % mod + mod) % mod;
	if (a < 0) {
		a += mod;
		if (a < 0) {
			a = ((a % mod) + mod) % mod;
		}
	} else if (a >= mod) {
		a -= mod;
		if (a >= mod) {
			a %= mod;
		}
	}
	return a;
}

ll add(ll a, ll b, ll mod) {
	a = getMod(a, mod);
	b = getMod(b, mod);
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	return a;
}

ll sub(ll a, ll b, ll mod) {
	a = getMod(a, mod);
	b = getMod(b, mod);
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
}

ll mul(ll a, ll b, ll mod) {
	a = getMod(a, mod);
	b = getMod(b, mod);
	return (__int128_t)a * b % mod;
}

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

ll gcd(ll x, ll y, ll & k, ll & l) {
	if (y == 0) {
		k = 1, l = 0;
		return x;
	}
	ll g = gcd(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

const ll INF = 1e18;

ll mul(ll a, ll b) {
	if (INF / a < b) return INF;
	return a * b;
}

ll lcm(ll a, ll b) {
	return mul(a / gcd(a, b), b);
}

ll getInv(ll x, ll mod) {
	ll k, l;
	assert(gcd(x, mod, k, l) == 1);
	return getMod(k, mod);
}

void Crt(ll r1, ll m1, ll r2, ll m2, ll & r0, ll & m0) {
	if (m1 > m2) {
		swap(r1, r2);
		swap(m1, m2);
	}
	ll k = mul(sub(r2, r1, m2), getInv(m1, m2), m2);
	m0 = mul(m1, m2);
	assert(m0 < INF);
	r0 = add(mul(k, m1, m0), r1, m0);
}

void no() {
	cout << "NO\n";
	exit(0);
}

const int MAXN = 1e4 + 10;
ll w, h;
int n;
ll a[MAXN];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> h >> w;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll x = 1;
	for (int i = 0; i < n; i++) {
		x = lcm(x, a[i]);
	}
	if (x > h) no();
	ll r0 = 0, m0 = 1;
	for (int i = 0; i < n; i++) {
		ll r1 = getMod(-i, a[i]);
		ll m1 = a[i];
		ll g = gcd(m0, m1);
		if (r0 % g != r1 % g) no();
		ll yr, ym;
		Crt(r0 / g, m0 / g, r1 / g, m1 / g, yr, ym);
		m0 /= g;
		m0 *= m1;
		r0 = add(mul(yr, g, m0), r1 % g, m0);
		assert(r0 == getMod(r0, m0));
	}
	ll y = r0;
	if (y == 0) y += m0;
	//cout << "x = " << x << " y = " << y << endl;
	if (y + n - 1 > w) no();
	for (int i = 0; i < n; i++) {
		if (gcd(x, y + i) != a[i]) {
			no();
		}
	}
	cout << "YES\n";
	return 0;
}