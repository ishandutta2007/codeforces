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
	
    int d, n, m;
    ve< pii > fuel;
    
	bool read () {
        if (scanf("%d%d%d", &d, &n, &m) != 3) return 0;
        fuel.resize(m);
        forn (i, m) {
            scanf("%d%d", &fuel[i].fs, &fuel[i].sc);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {

    ll ans;
	
	void write () {
		printf("%" PRId64 "\n", ans);
	}
};

const int INF = 2000000000;

struct Solution: Data {

    ve< pii > tree;
    int curk;

    void filter() {
        sort(all(fuel));
        curk = 2;
        while (curk < sz(fuel)) curk *= 2;
        tree.assign(2 * curk, mp(INF, -1));
        forn (i, sz(fuel)) {
            tree[curk + i] = mp(fuel[i].sc, i);
        }
        ford (i, 1, curk) {
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int get_min(int l, int r) {
        l += curk, r += curk;
        pii res = mp(INF, -1);
        while (l < r) {
            res = min(res, min(tree[l], tree[r]));
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        if (l == r) res = min(res, tree[l]);
        return res.sc;
    }

    pa< ll, int> rec(int lid, int rid, int lx, int rx, int avail) {
        debug(mt(lid, rid, lx, rx, avail));
        if (lid > rid) {
            return (rx - lx > avail) ? mp(-1ll, 0) : mp(0ll, avail + lx - rx);
        }
        int mid = get_min(lid, rid);
        debug(mid);
        auto res = rec(lid, mid - 1, lx, fuel[mid].fs, avail);
        ll sum = res.fs;
        avail = res.sc;
        if (res.fs == -1ll) {
            return mp(-1ll, 0);
        }
        int want = max(min(rx - fuel[mid].fs, n), avail);
        sum += 1ll * fuel[mid].sc * (want - avail);
        res = rec(mid + 1, rid, fuel[mid].fs, rx, want);
        if (res.fs == -1ll) {
            return mp(-1ll, 0);
        }
        return mp(sum + res.fs, res.sc);
    }
	
	void solve () {
        filter();
        ans = rec(0, m - 1, 0, d, n).fs;
	}
	
	void clear () {
        debug();
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