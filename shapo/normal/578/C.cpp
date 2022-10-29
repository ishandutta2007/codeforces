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
    int n;
    vi a;
	bool read () {
        if (!(cin >> n)) return 0;
        a.resize(n);
        forn(i, n) {
            cin >> a[i];
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ld ans;	
	void write () {
		cout << ans << '\n';
	}
};

struct Solution: Data {
    ld calc_weak(ld x)
    {
        ld min_val = 1e20, max_val = -1e20;
        ld max_pref = 0., min_pref = 0., cur_pref = 0.;
        forn(i, n) {
            cur_pref += a[i] + x;
            umx(max_val, cur_pref - min_pref);
            umn(min_val, cur_pref - max_pref);
            umx(max_pref, cur_pref);
            umn(min_pref, cur_pref);
        }
        return max(fabsl(min_val), fabsl(max_val));
    }
	void solve () {
	    ld l = -1.5e4, r = 1.5e4;
        forn(it, 90) {
            ld m1 = (2 * l + r) / 3;
            ld m2 = (l + 2 * r) / 3;
            ld v1 = calc_weak(m1), v2 = calc_weak(m2);
            if (v1 < v2) {
                r = m2;
            } else {
                l = m1;
            }
        }
        debug(mt(l, r, r - l));
        ans = calc_weak((l + r) / 2);
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
    ios_base::sync_with_stdio(false);
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
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