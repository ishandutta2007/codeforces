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
	
    int n, k;
    vi a;
    ve< vi > g;

	bool read () {
        if (scanf("%d%d", &n, &k) != 2) return 0;
        a.resize(n);
        forn (i, n) scanf("%d", &a[i]);
        g.assign(n, vi());
        forn (i, n - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
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
};

struct Solution: Data {

    void filter() {
        forn (i, n) {
            sort(all(g[i]));
        }
        g[0].pb(n);
    }

    vi alpha, beta;
    vi good;

    void calc_dp(int v, int par) {
        for (int son : g[v]) {
            if (son == par) continue;
            calc_dp(son, v);
        }
        // calc alpha[v]
        bool all_good = (good[v]);
        alpha[v] = 1;
        for (int son : g[v]) {
            if (son == par) continue;
            alpha[v] += alpha[son];
            if (alpha[son] == -1) all_good = false;
        }
        if (!all_good) {
            alpha[v] = -1;
        }
        // calc beta[v]
        if (good[v]) {
            int max_bad = 0;
            beta[v] = 1;
            for (int son : g[v]) {
                if (son == par) continue;
                if (alpha[son] != -1) {
                    beta[v] += alpha[son];
                } else {
                    umx(max_bad, beta[son]);
                }
            }
            beta[v] += max_bad;
        }
    }

    void update_val(int v, int par, int al, int bt, int &res) {
        debug(mt("update", v, par, al, bt));
        int old_al = alpha[par], old_bt = beta[par];
        alpha[par] = al, beta[par] = bt;
        // update ans
        umx(res, beta[v] + bt);
        debug(beta[v] + bt);
        // push updates to sons
        if (!good[v]) {
            for (int son : g[v]) {
                if (son == par) continue;
                update_val(son, v, -1, 0, res);
            }
        } else {
            int all_alpha = 1;
            int good_alpha = 1;
            vi bad_alphas;
            vi max_bt;
            for (int son : g[v]) {
                all_alpha += alpha[son];
                if (alpha[son] == -1) {
                    bad_alphas.pb(son);
                    max_bt.pb(beta[son]);
                    sort(max_bt.rbegin(), max_bt.rend());
                    max_bt.resize(2);
                } else {
                    good_alpha += alpha[son];
                }
            }
            for (int son : g[v]) {
                if (son == par) continue;
                int new_al = -1;
                int new_bt = 0;
                if (bad_alphas.empty() || (sz(bad_alphas) == 1 && bad_alphas.front() == son)) {
                    new_al = all_alpha - alpha[son];
                }
                new_bt = good_alpha;
                if (alpha[son] != -1) {
                    new_bt -= alpha[son];
                    if (!max_bt.empty()) {
                        new_bt += max_bt[0];
                    }
                } else {
                    if (max_bt[0] != beta[son]) {
                        new_bt += max_bt[0];
                    } else if (sz(max_bt) > 1) {
                        new_bt += max_bt[1];
                    }
                }
                update_val(son, v, new_al, new_bt, res);
            }
        }
        alpha[par] = old_al;
        beta[par] = old_bt;
    }

    bool can(int x) {
        alpha.assign(n + 1, -1);
        beta.assign(n + 1, 0);
        good.assign(n + 1, 0);
        forn (i, n) good[i] = a[i] >= x;
        good[n] = 0;
        calc_dp(0, n);
        int max_val = 0;
        debug(all(alpha));
        debug(all(beta));
        update_val(/* v = */ 0,
                   /* par = */ n,
                   /* al = */ 0,
                   /* bt = */ 0,
                   max_val);
        return max_val >= k;
    }
	
	void solve () {
	    filter();	
        ans = 0;
#ifdef SG
        int l = 0, r = 7;
#else
        int l = 0, r = 1000001;
#endif
        while (l < r - 1) {
            int mid = (l + r) / 2;
            debug(mid);
            if (can(mid)) {
                l =  mid;
            } else {
                r = mid;
            }
        }
        ans = l;
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