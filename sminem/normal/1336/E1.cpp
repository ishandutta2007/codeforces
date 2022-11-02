#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998244353;
typedef modint<mod> mint;

ll n, m, h, d;

ll g[60];
void gadd(ll x) {
	for (int i=0; i<m; i++) {
		if (x & (1ll << (m-1-i))) {
			if (!g[i]) {
				g[i] = x;
				d++;
				return;
			} else {
				x ^= g[i];
			}
		}
	}
}

ll c[8192];
ll kes[8192][14];
mint sol[40];

void resi(ll x) {
	if (kes[x][0] != -1)
		return;
	fill(kes[x], kes[x] + 14, 0);
	for (int i=0; i<(1<<h); i++)
		kes[x][__builtin_popcountll(i ^ x)] += c[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(kes, 255, sizeof kes);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		gadd(x);
	}

	cerr << "d = " << d << '\n';

	vector<ll> b;
	for (int i=0; i<m; i++)
		if (g[i])
			b.push_back(g[i]);
	sort(begin(b), end(b));

	h = m / 3;
	if (m >= 30)
		h += 2;
	ll hm = (1ll<<h) - 1;

	int ch = 0;
	while (ch < d && b[ch] <= hm)
		ch++;

	for (int mask=0; mask<(1<<ch); mask++) {
		ll x = 0;
		for (int i=0; i<ch; i++) {
			if (mask & (1 << i)) {
				x ^= b[i];
			}
		}

		c[x]++;
	}

	// for (int i=0; i<=hm; i++)
	// 	cerr << "c = " << c[i] << '\n';

	// for (ll x : b)
	// 	cerr << "x = " << x << '\n';

	for (ll mask=0; mask<(1ll<<d); mask+=(1ll<<ch)) {
		ll x = 0;
		for (int i=ch; i<d; i++) {
			if (mask & (1ll << i)) {
				x ^= b[i];
			}
		}

		resi(x & hm);
		int ex = __builtin_popcountll(x >> h);
		// cerr << "ex = " << ex << '\n';
		for (int i=0; i<=h; i++)
			sol[i + ex] += kes[x & hm][i];
	}

	mint mul = mint(2) ^ (n-d);
	for (int i=0; i<=m; i++) {
		cout << (sol[i] * mul)() << " \n"[i == m];
	}

}