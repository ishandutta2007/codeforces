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

const int MAXN = 200500;

struct Input {
    char s[MAXN], t[MAXN];
    int len;
	bool read () {
        if (scanf(" %s %s", s, t) != 2) {
            return 0;
        }
        len = strlen(s);
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    bool ans;
	void write () {
        puts(ans ? "YES" : "NO");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
    void my_sort(char *s, int from, int to)
    {
        if ((to - from) % 2 == 0) {
            int mid = (to + from) / 2;
            int hlen = (to - from) / 2;
            my_sort(s, from, mid);
            my_sort(s, mid, to);
            int ret = strncmp(s + from, s + mid, hlen);
            if (ret > 0) {
                forn(i, hlen) {
                    swap(s[from + i], s[mid + i]);
                }
            }
        }
    }
	
	void solve () {
        ans = false;
        my_sort(s, 0, len);
        my_sort(t, 0, len);
        ans = !strncmp(s, t, len);
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