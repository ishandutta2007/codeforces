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
	int n, q;
    vi a, l, r;

	bool read () {
        if (scanf("%d%d", &n, &q) != 2) return 0;
        a.resize(n);
        forn (i, n) scanf("%d", &a[i]);
        l.resize(q); r = l;
        forn (i, q) {
            scanf("%d%d", &l[i], &r[i]);
            --l[i], --r[i];
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ve< ll > ans;	
	void write () {
		for (ll x : ans) {
            printf("%" PRId64 "\n", x);
        }
	}
};

struct Solution: Data {
	
    vi h;

    static const int MAXL = 17;

    ve< ve< pii > > sp;
    vi loglen;

    int get_max_id (int l, int r) {
        if (l == r) {
            return l;
        }
        int it = loglen[r - l + 1];
        auto res = max(sp[it][l], sp[it][r - (1 << it) + 1]);
        return res.sc;
    }

    ll get_ans(int l, int r) {
        if (l >= r) {
            return 0ll;
        }
        int pos = get_max_id(l, r - 1);
        ll res = 1ll * h[pos] * (pos - l + 1) * (r - pos);
        res += get_ans(l, pos);
        res += get_ans(pos + 1, r);
        return res;
    }

	void solve () {
	    h.resize(n - 1);
        forn (i, n - 1) {
            h[i] = abs(a[i + 1] - a[i]);
        }
        loglen.assign(n, 0);
        int high = 0;
        forn (i, 2, n) {
            loglen[i] = high;
            if ((1 << (high + 1)) == i) ++high;
        }
        sp.assign(MAXL, ve< pii >(n - 1, pii(-1, 0)));
        forn (i, n - 1) {
            sp[0][i] = mp(h[i], i);
        }
        forn (it, 1, MAXL) {
            int pos = (1 << (it - 1));
            sp[it] = sp[it - 1];
            for (int i = 0; pos < n - 1; ++i, ++pos) {
                umx(sp[it][i], sp[it - 1][pos]);
            }
        }
        forn (i, q) {
            ans.pb(get_ans(l[i], r[i]));
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