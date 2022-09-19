#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	ll a, b;
	
	bool read () {
		return cin >> a >> b;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans;
	
	void write () {
		if (!sz(ans)) {
			puts("Impossible");
			return;
		}
		puts(ans.c_str());
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	ll gcd (ll a, ll b, ll &x, ll &y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
		ll k = a / b;
		ll r = a % b;
		ll d = gcd(b, r, y, x);
		y -= k * x;
		return d;
	}
	
	string tostr (ll n) {
		if (!n) {
			return "";
		}
		return tostr(n / 10) + char(n % 10 + '0');
	}
	
	void solve () {
		ll p, q;
		ll d = gcd(a, b, p, q);
		if (d > 1) {
			return;
		}
		ll x1 = q;
		ll y1 = -p;
		ll x2 = a - x1;
		ll y2 = b - y1;
		while (x1 < 0 || y1 < 0) {
			x1 += a;
			y1 += b;
			x2 -= a;
			y2 -= b;
		}
		while (x2 < 0 || y2 < 0) {
			x1 -= a;
			y1 -= b;
			x2 += a;
			y2 += b;
		}
		while (x1 < 0 || y1 < 0) {
			return;
		}
		while (y1 || x2) {
			if (x1 >= x2 && y1 >= y2) {
				ll k = max(x1, y1);
				if (x2) {
					umn(k, x1 / x2);
				}
				if (y2) {
					umn(k, y1 / y2);
				}
				ans = tostr(k) + "B" + ans;
				x1 -= k * x2;
				y1 -= k * y2;
			} else {
				ll k = max(x2, y2);
				if (x1) {
					umn(k, x2 / x1);
				}
				if (y1) {
					umn(k, y2 / y1);
				}
				ans = tostr(k) + "A" + ans;
				x2 -= k * x1;
				y2 -= k * y1;
			}
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}