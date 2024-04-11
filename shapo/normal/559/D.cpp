#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
    #include <sys/time.h>
    #include <sys/resource.h>
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

template< typename T >
T gcd(T a, T b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int MAXN = 100500;

struct Input {
    int n;
    int x[MAXN], y[MAXN];
	bool read () {
        if (scanf("%d", &n) != 1) {
            return 0;
        }
        forn(i, n) {
            scanf("%d%d", &x[i], &y[i]);
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
        cout << double(ans) << '\n';
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
    int int_num(int i, int j)
    {
        int dx = abs(x[i] - x[j]), dy = abs(y[i] - y[j]);
        int g = gcd(dx, dy);
        return g;
    }
    ld sq(int i, int j)
    {
        return ld(1ll * x[i] * y[j] - 1ll * y[i] * x[j]);
    }
	void solve () {
        ans = ld(0);
        if (n <= 300) {
            // calc 1 / 2 ** n
            ld frac = ld(1);
            forn(i, n) {
                frac *= 0.5;
            }
            ld denom = 1. - frac * (n * n + n + 2) / 2.;
            debug(denom);
            forn(i, n) {
                ld cfrac = ld(0.5);
                forn(nxt, 1, n - 1) {
                    cfrac /= ld(2);
                    int j = (i + nxt) % n;
                    ld add = sq(i, j) - int_num(i, j);
                    ld prob = (cfrac - frac) / denom;
                    debug(mt(cfrac - frac, prob, add));
                    ans += add * prob;
                }
            }
        } else {
            forn(i, n) {
                ld prob = ld(0.5);
                forn(nxt, 1, 200) {
                    prob /= ld(2);
                    int j = (i + nxt) % n;
                    ld add = sq(i, j) - int_num(i, j);
                    ans += add * prob;
                }
            }
        }
        ans /= ld(2);
        ans += ld(1);
	}
	
	void clear () {
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