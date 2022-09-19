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

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	ll n;
	bool read () {
		return cin >> n;
	}
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll l, r;

	void write () {
		cout << l << ' ' << r - 1 << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll calc (ll r) {
		ll ans = 0;
		ll d = 1;
		ll cnt = 0;
		int s = 0;
		while (d <= r) {
			ld x = r % (d * 10) / d;
			ans += cnt * x;
			cnt += x * d;
			ans += x * d * (x - 1 + s * 9) / 2;
			++s;
			d *= 10;
		}
		return ans;
	}
	
	ll calc (ll l, ll r) {
		return calc(r) - calc(l);
	}
	
	void solve () {
		l = 1, r = 1;
		while (calc(l, r) < n) {
			r *= 2;
		}
		{
			ll l_ = l, r_ = r;
			while (l_ != r_) {
				ll m_ = (l_ + r_) / 2;
				if (calc(l, m_) < n) {
					l_ = m_ + 1;
				} else {
					r_ = m_;
				}
			}
			r = r_;
		}
		ll w;
		while ((w = calc(l, r)) != n) {
			if (w < n) {
				++r;
			} else {
				++l;
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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