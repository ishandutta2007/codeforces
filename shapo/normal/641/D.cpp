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

// typedef long double ld;
typedef double ld;
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
    ve< ld > c, d;

	bool read () {
        if (scanf("%d", &n) != 1) return 0;
        c.resize(n);
        d.resize(n);
        double tmp;
        forn (i, n) {
            scanf("%lf", &tmp);
            c[i] = tmp;
        }
        forn (i, n) {
            scanf("%lf", &tmp);
            d[i] = tmp;
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	
    ve< ld > x, y;

	void write () {
        forn (i, n) {
            printf("%.13lf ", double(x[i]));
        }
        puts("");
        forn (i, n) {
            printf("%.13lf ", double(y[i]));
        }
        puts("");
	}
};

struct Solution: Data {

	void solve () {
        forn (i, 1, n) {
            c[i] += c[i - 1];
            d[i] += d[i - 1];
        }
        x.resize(n);
        y.resize(n);
        forn (i, n) {
            ld a = c[i], b = c[i] + d[i];
            ld discr = sqrt(max(b * b - 4 * a, ld(0)));
            x[i] = (b - discr) / 2.;
            y[i] = (b + discr) / 2.;
        }
        ford (i, 1, n) {
            x[i] -= x[i - 1];
            y[i] -= y[i - 1];
        }
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
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