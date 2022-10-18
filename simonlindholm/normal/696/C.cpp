#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll mod = 1000000007;
const ll mod2 = 1000000006;

struct M {
	typedef const M& R;
	array<ll, 4> d;
	M(int _r, int _c) { rep(i,0,4) d[i] = 0; }
	ll& operator()(int row, int col) { return d[row*2 + col]; }
	const ll& operator()(int row, int col) const { return d[row*2 + col]; }
	M operator*(R m) const {
		M a(2, 2);
		const M& n = *this;

		a(0,0) = (n(0,0) * m(0,0) + n(0,1) * m(1,0)) % mod;
		a(1,0) = (n(1,0) * m(0,0) + n(1,1) * m(1,0)) % mod;
		a(0,1) = (n(0,0) * m(0,1) + n(0,1) * m(1,1)) % mod;
		a(1,1) = (n(1,0) * m(0,1) + n(1,1) * m(1,1)) % mod;

		return a;
	}
	M operator^(ll p) const {
		M a(0, 0), b(*this);
		rep(i,0,2) a(i,i) = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

ll mpow(ll x, ll e) {
	if (e == 0) return 1;
	ll a = mpow(x * x % mod, e >> 1);
	if (e & 1) a = a * x % mod;
	return a;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	M ma(2, 2);
	ma(0,0) = 0;
	ma(0,1) = 1;
	ma(1,0) = 2;
	ma(1,1) = 1;

	ll prodm = 1;

	int N;
	cin >> N;
	rep(i,0,N) {
		ll e;
		cin >> e;
		ma = ma ^ e;
		prodm = prodm * (e % mod2) % mod2;
	}

	ll mb = mpow(2, prodm);

	ll half = (mod+1) / 2;
	ll num = ma.d[0] * half % mod;
	ll den = mb * half % mod;
	cout << num << '/' << den << endl;

	exit(0);
}