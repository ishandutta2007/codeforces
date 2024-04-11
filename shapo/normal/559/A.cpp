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

struct Input {
    int a[6];
	bool read () {
        if (scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) != 6) {
            return 0;
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    int ans;
	void write () {
        printf("%d\n", ans);
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	void solve () {
        ans = 0;
        int add = 1;
        int cur_len = a[0];
        forn(i, a[1] + a[2]) {
            int new_len = cur_len + add;
            debug(mt(cur_len, new_len));
            ans += new_len + cur_len;
            cur_len = new_len;
            if (i == a[5] - 1) {
                --add;
            }
            if (i == a[1] - 1) {
                --add;
            }
        }
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