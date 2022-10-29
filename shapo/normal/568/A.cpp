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
    int p, q;
	bool read () {
        return (cin >> p >> q);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    int n;	
	void write () {
        cout << n << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
    static const int MAXL = 10000000;
    int prime[MAXL], pal[MAXL];
    void init() {
        forn(i, 2, MAXL) {
            prime[i] = 1;
        }
        for (int i = 2; i * i < MAXL; ++i) {
            if (prime[i]) {
                for (int j = i * i; j < MAXL; j += i) prime[j] = 0;
            }
        }
        forn(i, 1, MAXL) {
            pal[i] = (i % 10 && reverse(i) == i);
        }
    }

    int reverse(int x)
    {
        int res = 0;
        while (x) {
            res = (res * 10) + x % 10;
            x /= 10;
        }
        return res;
    }

	void solve () {
        int sum_prime = 0, sum_pal = 0;
        n = -1;
        forn(i, 1, MAXL) {
            sum_prime += prime[i];
            sum_pal += pal[i];
            if (1ll * sum_prime * q <= 1ll * sum_pal * p) {
                n = i;
            }
        }
        assert(n != -1);
	}
	
	void clear () {
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
    sol.init();
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