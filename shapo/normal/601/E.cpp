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
    int n, k, q;
    vi v, w;
    vi tq, vq, wq;
	bool read () {
        if (scanf("%d%d", &n, &k) != 2) return 0;
        v.resize(n), w.resize(n);
        forn (i, n) {
            scanf("%d%d", &v[i], &w[i]);
        }
        scanf("%d", &q);
        tq.resize(q), vq = wq = tq;
        forn (i, q) {
            scanf("%d", &tq[i]); --tq[i];
            if (tq[i] == 0) {
                scanf("%d%d", &vq[i], &wq[i]);
            } else if (tq[i] == 1) {
                scanf("%d", &vq[i]);
                --vq[i];
            }
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
    static const int BASE = 10000019;
    static const int MOD = 1000000007;

    static const int MAXIT = 20;
    static const int MAXK = 1001;

    int dp[MAXIT][MAXK];
    
    vi lpos, rpos;

    void rec(int l, int r, int it) {
        if (l == r - 1) {
            if (tq[l] == 2) {
                int res = 0;
                ford (j, 1, k + 1) {
                    res = (1ll * res * BASE + dp[it][j]) % MOD;
                }
                ans.pb(res);
            }
        } else {
            int mid = (l + r) / 2;
            memcpy(dp[it + 1], dp[it], (k + 1) * sizeof(dp[it + 1][0]));
            forn (i, mid, r) {
                if (tq[i] == 1 && lpos[i] < l) {
                    int id = vq[i];
                    int tv = v[id], tw = w[id];
                    ford (t, tw, k + 1) {
                        umx(dp[it + 1][t], dp[it + 1][t - tw] + tv);
                    }
                }
            }
            rec(l, mid, it + 1);
            memcpy(dp[it + 1], dp[it], (k + 1) * sizeof(dp[it + 1][0]));
            forn (i, l, mid) {
                if (tq[i] == 0 && rpos[i] >= r) {
                    int id = vq[i];
                    int tv = v[id], tw = w[id];
                    ford (t, tw, k + 1) {
                        umx(dp[it + 1][t], dp[it + 1][t - tw] + tv);
                    }
                }
            }
            rec(mid, r, it + 1);
        }
    }
	
	void solve () {
	    forn (i, q) {
            if (tq[i] == 0) {
                v.pb(vq[i]);
                w.pb(wq[i]);
                vq[i] = sz(v) - 1;
            }
        }
        memset(dp, 0, sizeof(dp));
        {
            vi ttt(n, 0), ttv(n);
            forn (i, n) {
                ttv[i] = i;
            }
            ttt.swap(tq);
            tq.insert(tq.end(), all(ttt));
            ttv.swap(vq);
            vq.insert(vq.end(), all(ttv));
            n = sz(v);
            q = sz(tq);
            vi used(n, 0);
            forn (i, q) {
                if (tq[i] == 0) {
                    used[vq[i]]++;
                } else if (tq[i] == 1) {
                    used[vq[i]]--;
                }
            }
            forn (i, n) {
                if (used[i]) {
                    tq.pb(1);
                    vq.pb(i);
                }
            }
        }
        q = sz(tq);
        {
            vi cnt(n, -1);
            lpos.resize(q, -1);
            forn (i, q) {
                if (tq[i] == 0) {
                    cnt[vq[i]] = i;
                } else if (tq[i] == 1) {
                    lpos[i] = cnt[vq[i]];
                }
            }
            cnt.assign(n, q + 1);
            rpos.resize(q, q + 1);
            ford (i, q) {
                if (tq[i] == 1) {
                    cnt[vq[i]] = i;
                } else if (tq[i] == 0) {
                    rpos[i] = cnt[vq[i]];
                }
            }
        }
        rec(0, q, 0);
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