#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
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
#define pb emplace_back
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

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000;

ll y[N];

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		if (i < 2) {
			y[i] = 0;
		} else {
			ll a1, a2;
			cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << i + 1 << endl;
			cin >> a1;
			cout << 2 << ' ' << 1 << ' ' << 2 << ' ' << i + 1 << endl;
			cin >> a2;
			y[i] = a1 * a2;
		}
	}
	debug(y, y + n);
	int mni = 0, mxi = 0;
	ll mn = y[0], mx = y[0];
	forn (i, n) {
		if (umn(mn, y[i])) {
			mni = i;
		}
		if (umx(mx, y[i])) {
			mxi = i;
		}
	}
	vi v1, v2;
	forn (i, n) {
		if (i == mni || i == mxi) {
			continue;
		}
		ll val;
		cout << 2 << ' ' << mni + 1 << ' ' << mxi + 1 << ' ' << i + 1 << endl;
		cin >> val;
		if (val == -1) {
			v1.pb(i);
		} else {
			v2.pb(i);
		}
	}
	sort(all(v1), [&](int i, int j) {
		return y[i] < y[j];
	});
	sort(all(v2), [&](int i, int j) {
		return y[i] < y[j];
	});
	vi v;
	v.pb(mni);
	forn (i, sz(v1)) {
		v.pb(v1[i]);
	}
	v.pb(mxi);
	ford (i, sz(v2)) {
		v.pb(v2[i]);
	}
	int pos = 0;
	forn (i, sz(v)) {
		if (v[i] == 0) {
			pos = i;
		}
	}
	rotate(v.begin(), v.begin() + pos, v.end());
	cout << 0;
	forn (i, sz(v)) {
		cout << ' ' << v[i] + 1;
	}
	cout << endl;
	return 0;
}