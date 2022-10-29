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
    int n, k;
    ve< vi > g;
    vi h;
    vi s;
	
	bool read () {
        if (!(cin >> n)) {
            return 0;
        }
        h.resize(n);
        forn(i, n) {
            cin >> h[i];
        }
        g.assign(n, vi());
        forn(i, n - 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cin >> k;
        s.resize(k);
        forn(i, k) {
            cin >> s[i];
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
        cout << ans << '\n';
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
    vi sc_best;
    vi fs_best;
    vi all_vals;
    vi heights;
    vi backw_pos;
    vi forw_pos;
    vi fail_pos;
    vi fail_vers;
    void dfs(int x, int par, int fs, int sc) {
        if (fs == -1 || h[x] <= h[fs]) {
            sc = fs;
            fs = x;
        } else if (sc == -1 || h[x] <= h[sc]) {
            sc = x;
        }
        fs_best[x] = fs;
        sc_best[x] = sc;
        for (auto to : g[x]) {
            if (to != par) {
                dfs(to, x, fs, sc);
            }
        }
    }
    int mfit() {
        int ans = -1;
        int ln = 0;
        int cnt = sz(all_vals);
        forn(i, cnt) {
            int cur = 0;
            vi new_h;
            int rn = ln;
            while (rn <  n && fs_best[heights[rn]] == all_vals[i]) ++rn;
            int fail_from = 0, fail_to = fail_pos[i];
            int lp = forw_pos[i], rp = backw_pos[i];
            bool ok = true;
            forn(j, ln, rn) {
                int a = h[all_vals[i]];
                int b = 2000000000;
                if (sc_best[heights[j]] != -1) {
                    b = h[sc_best[heights[j]]];
                }
                if (fail_from != fail_to) {
                    if (b >= fail_vers[fail_from]) {
                        umx(cur, fail_vers[fail_from] - a);
                    } else {
                        ok = false;
                    }
                    ++fail_from;
                } else if (lp != rp) {
                    if (b >= s[lp]) {
                        umx(cur, s[lp] - a);
                    } else {
                        ok = false;
                    }
                    ++lp;
                }
            }
            if (ok && fail_from == fail_to && lp == rp && (ans == -1 || ans > cur)) {
                ans = cur;
            }
            ln = rn;
        }
        return ans;
    }
	void solve () {
        sort(all(s));
        reverse(all(s));
        sc_best.assign(n, -1);
        fs_best.assign(n, -1);
        dfs(0, -1, -1, -1);
        heights.resize(n);
        forn(i, n) {
            heights[i] = i;
        }
        sort(all(heights), [&](int a, int b) {
                return (h[fs_best[a]] > h[fs_best[b]] ||
                        (h[fs_best[a]] == h[fs_best[b]] && fs_best[a] < fs_best[b]) ||
                        (fs_best[a] == fs_best[b] && (sc_best[b] != -1 && 
                                                     (sc_best[a] == -1 || h[sc_best[a]] > h[sc_best[b]]))));
                });
        all_vals.clear();
        for (auto x : heights) {
            if (all_vals.empty() || all_vals.back() != fs_best[x]) {
                all_vals.pb(fs_best[x]);
            }
        }
        int lp = 0, ln = 0;
        int cnt = sz(all_vals);
        forw_pos.assign(cnt, 0);
        fail_pos.assign(cnt, 0);
        forn(i, cnt - 1) {
            while (ln < n && fs_best[heights[ln]] == all_vals[i]) {
                int cur_h = h[all_vals[i]];
                while (lp < k && cur_h < s[lp]) {
                    fail_vers.pb(s[lp]);
                    ++lp;
                }
                if (lp < k) {
                    ++lp;
                }
                ++ln;
            }
            forw_pos[i + 1] = lp;
            fail_pos[i + 1] = sz(fail_vers);
        }
        debug(all(fail_vers));
        backw_pos.assign(cnt, k);
        int rp = k - 1, rn = n - 1;
        ford(i, 1, cnt) {
            while (rn >= 0 && fs_best[heights[rn]] == all_vals[i]) {
                int cur_h = h[all_vals[i]];
                if (rp >= 0) {
                    if (cur_h >= s[rp]) {
                        --rp;
                    }
                }
                --rn;
            }
            backw_pos[i - 1] = rp + 1;
        }
        ans = mfit();
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
    ios_base::sync_with_stdio(false);
#ifdef SG
    deepen(0);
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