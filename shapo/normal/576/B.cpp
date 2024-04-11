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
    vi p;
	bool read () {
        if (scanf("%d", &n) != 1) return 0;
        p.resize(n);
        forn(i, n) {
            scanf("%d", &p[i]);
            --p[i];
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ve< vi > g;
    bool ok;
	void write () {
		if (!ok) {
            puts("NO");
        } else {
            puts("YES");
            forn(i, n) {
                for (int to : g[i]) {
                    if (to > i) {
                        printf("%d %d\n", i + 1, to + 1);
                    }
                }
            }
        }
	}
};

struct Solution: Data {
	
    void add_edge(int x, int y)
    {
        g[x].pb(y);
        g[y].pb(x);
    }

	void solve () {
	    ok = false;
        g.clear();
        g.resize(n);
        forn(i, n) {
            if (p[i] == i) {
                ok = true;
                forn(j, n) {
                    if (i == j) continue;
                    add_edge(i, j);
                }
                return;
            }
        }
        ve< vi > tmp_comp;
        vi used(n, 0);
        forn(i, n) {
            int cur = i;
            if (used[cur]) {
                continue;
            }
            tmp_comp.pb(vi());
            auto &add = tmp_comp.back();
            while (!used[cur]) {
                add.pb(cur);
                used[cur] = 1;
                cur = p[cur];
            }
        }
        int min_sz = n + 1;
        for (const auto &v : tmp_comp) {
            umn(min_sz, sz(v));
        }
        debug(tmp_comp);
        debug(min_sz);
        if (min_sz != 2) {
            return;
        }
        int id = -1;
        forn(i, sz(tmp_comp)) {
            if (sz(tmp_comp[i]) == 2) {
                id = i;
                break;
            }
        }
        forn(i, sz(tmp_comp)) {
            if (sz(tmp_comp[i]) % 2) {
                return;
            }
        }
        ok = true;
        int tu = tmp_comp[id][0], tv = tmp_comp[id][1];
        add_edge(tu, tv);
        forn(i, sz(tmp_comp)) {
            if (i == id) continue;
            forn(j, sz(tmp_comp[i]) / 2) {
                int ta = tmp_comp[i][j * 2], tb = tmp_comp[i][j * 2 + 1];
                add_edge(tu, ta);
                add_edge(tv, tb);
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