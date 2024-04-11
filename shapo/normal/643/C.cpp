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
	
    int n, lvl;
    ve< ll > t;

	bool read () {
        if (scanf("%d%d", &n, &lvl) != 2) return 0;
        t.resize(n);
        forn (i, n) {
            int x;
            scanf("%d", &x);
            t[i] = x;
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
		printf("%.13lf\n", double(ans));
	}
};

struct Solution: Data {
	
    ve< ll > cumsum;
    ve< ld > dp;

    void run_dp_naive() {
        forn (it, 1, lvl) {
            ve< ld > new_dp(n, -1);
            forn (k, n) {
                if (dp[k] < 0) {
                    continue;
                }
                ld cur_val = 0.;
                forn (i, k + 1, n) {
                    cur_val += ld(cumsum[i] - cumsum[k]) / ld(t[i]);
                    ld new_val = dp[k] + cur_val;
                    if (new_dp[i] < 0 || new_dp[i] > new_val) {
                        new_dp[i] = new_val;
                    }
                }
            }
            dp.swap(new_dp);
        }
    }

    void run_dp() {
        ve< ld > add_val;
        add_val.assign(n, 0);
        {
            forn (i, n) {
                add_val[i] = ld(cumsum[i]) / ld(t[i]);
            }
        }
        forn (it, 1, lvl) {
            ve< ld > new_dp(n, -1);
            ve< pa< ld, pa< ld, ld > > > qhull;
            ld a_sum = ld(0);
            ld b_sum = ld(0);
            forn (k, n) {
                a_sum += add_val[k];
                b_sum += ld(1) / ld(t[k]);
                if (!qhull.empty()) {
                    auto it = upper_bound(all(qhull), mp(b_sum, mp(ld(-1e19), ld(0))));
                    ld fcoef, mult;
                    tie(mult, fcoef) = (--it)->second;
                    new_dp[k] = fcoef + a_sum + mult * b_sum;
                }
                if (dp[k] > 0) {
                    ld fcoef, mult;
                    mult = -cumsum[k];
                    fcoef = dp[k] - a_sum + ld(cumsum[k]) * b_sum;
                    while (!qhull.empty()) {
                        auto pr = qhull.back();
                        ld pos = (pr.second.second - fcoef) / (mult - pr.second.first);
                        if (pos > pr.first) {
                            qhull.pb(mp(pos, mp(mult, fcoef)));
                            break;
                        } else {
                            qhull.pop_back();
                        }
                    }
                    if (qhull.empty()) {
                        qhull.push_back(mp(b_sum, mp(mult, fcoef)));
                    }
                }
            }
            dp.swap(new_dp);
        }
    }

	void solve (int id = 0) {
        cumsum.resize(n);
        std::partial_sum(all(t), cumsum.begin());
        dp.resize(n);
        {
            ld cur_val = ld(0);
            forn (i, n) {
                dp[i] = cur_val += ld(cumsum[i]) / ld(t[i]);
            }
        }
        if (id) {
            run_dp_naive();
        } else {
            run_dp();
        }
        ans = dp.back();
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol, naive;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	while (sol.read()) {
        naive.init(sol);
        naive.solve(1);
        naive.write();
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