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
	
    int n, m;
    ve< vi > g;

	bool read () {
        if (!(cin >> n >> m)) return 0;
        g.assign(n, vi());
        forn (i, m) {
            int u, v;
            cin >> u >> v;
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

    ld ans;
	
	void write () {
		cout << double(ans) << '\n';
	}
};

struct Solution: Data {

    ve< vi > dist;
    ve< ve< ld > > div;
	
	void solve () {
        deepen(0);
        dist.assign(n, vi(n, n + 1));
        forn (i, n) {
            dist[i][i] = 0;
            for (int to : g[i]) {
                dist[i][to] = 1;
            }
        }
        // Floyd
        forn (k, n) {
            forn (i, n) {
                forn (j, n) {
                    umn(dist[i][j], dist[i][k] + dist[j][k]);
                }
            }
        }
        div.assign(n, ve< ld >(n, 0));
        forn (i, n) {
            forn (j, n) {
                div[i][dist[i][j]]++;
            }
            forn (d, n) {
                if (div[i][d]) {
                    div[i][d] = 1 / div[i][d];
                }
            }
        }
        ans = 0;
        vi tm(n, 0);
        ve< ld > val(n, ld(0));
        int ct = 0;
        forn (i, n) {
            ve< ld > prob(n, 0.);
            // split towns
            ve< vi > dist_split(n, vi());
            forn (j, n) {
                dist_split[dist[i][j]].pb(j);
            }
            forn (d, n) {
                if (dist_split[d].empty()) continue;
                ld rel = ld(sz(dist_split[d])) / n;
                ld tprob = div[i][d];
                ve< ld > trans(n, 0);
                for (int v : dist_split[d]) {
                    ld gsz = ld(sz(g[v]));
                    for (int to : g[v]) {
                        trans[to] += tprob / gsz;
                    } 
                }
                vi tx;
                forn (v, n) {
                    if (trans[v] > 0) {
                        tx.pb(v);
                    }
                }
                forn (i2, n) {
                    ++ct;
                    ld cur_prob = 0.;
                    for (int v : tx) {
                        int cd = dist[i2][v];
                        if (tm[cd] != ct) {
                            val[cd] = 0;
                        }
                        if (val[cd] < trans[v]) {
                            cur_prob += (trans[v] - val[cd]);
                            val[cd] = trans[v];
                        }
                        tm[cd] = ct;
                    }
                    umx(prob[d], cur_prob);
                    debug(i, d, i2, cur_prob, rel);
                }
                umx(prob[d], tprob);
                prob[d] *= rel;
            }
            umx(ans, accumulate(all(prob), ld(0)));
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