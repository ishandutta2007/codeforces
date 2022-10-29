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
    
    vi a, t, x;
	
	bool read () {
        if (scanf("%d", &n) != 1) return 0;
        a.resize(n);
        x = t = a;
        forn (i, n) {
            scanf("%d%d%d", &a[i], &t[i], &x[i]);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    vi ans;
	
	void write () {
		for (int x : ans) {
            printf("%d\n", x);
        }
	}
};

struct Solution: Data {

    vi tree;
    int curk;

    void init(int cnt) {
        curk = 2;
        while (curk < cnt) curk *= 2;
        tree.assign(2 * curk, 0);
    }

    void add_val(int pos, int x) {
        pos += curk;
        while (pos) {
            tree[pos] += x;
            pos /= 2;
        }
    }

    int get_sum(int r) {
        int res = 0;
        int l = curk;
        r += curk;
        while (l < r) {
            if (l % 2 == 1) res += tree[l];
            if (r % 2 == 0) res += tree[r];
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        if (l == r) res += tree[l];
        return res;
    }
	
	void solve () {
        vi tmp(n, -1);
	    ve< pii > ids(n);
        forn (i, n) {
            ids[i] = mp(x[i], i);
        }
        sort(all(ids));
        int l;
        while (l < n) {
            int r = l;
            while (r < n && ids[l].fs == ids[r].fs) ++r;
            vi ts;
            ts.reserve(r - l);
            forn (i, l, r) {
                int id = ids[i].sc;
                ts.pb(t[id]);
            }
            sort(all(ts));
            forn (i, l, r) {
                int id = ids[i].sc;
                int pos = lower_bound(all(ts), t[id]) - ts.begin();
                t[id] = pos;
            }
            init(r - l);
            forn (i, l, r) {
                int id = ids[i].sc;
                int pos = t[id];
                int tp = a[id];
                if (tp == 1) {
                    add_val(pos, 1);
                } else if (tp == 2) {
                    add_val(pos, -1);
                } else {
                    tmp[id] = get_sum(pos);
                }
            }
            l = r;
        }
        ans.clear();
        forn (i, n) {
            if (tmp[i] != -1) {
                ans.pb(tmp[i]);
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