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
    ve< ll > p, t;
	
	bool read () {
        if (scanf("%d", &n) != 1) {
            return 0;
        }
        p.resize(n);
        t.resize(n);
        forn (i, n) {
            scanf("%" SCNd64, &p[i]);
        }
        forn (i, n) {
            scanf("%" SCNd64, &t[i]);
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
		cout << double(ans) << endl;
	}
};

struct Solution: Data {
	void solve () {
        auto T = accumulate(all(t), ll(0));
        vi ids(n);
        forn (i, n) ids[i] = i;
        sort(all(ids), [&](int a, int b) {
                return mp(p[a] * t[b], b) > mp(p[b] * t[a], a);
                });
        ve< ll > min_sum(n), max_sum(n);
        ll cur_sum = 0ll;
        for (int l = 0; l < n; ) {
            int r = l + 1;
            while (r < n && p[ids[l]] * t[ids[r]] == p[ids[r]] * t[ids[l]]) ++r;
            forn (i, l, r) {
                int id = ids[i];
                min_sum[id] = cur_sum + t[id];
            }
            forn (i, l, r) {
                int id = ids[i];
                cur_sum += t[id];
            }
            forn (i, l, r) {
                int id = ids[i];
                max_sum[id] = cur_sum;
            }
            l = r;
        }
        vi good_ids(n);
        forn (i, n) good_ids[i] = i;
        sort(all(good_ids), [&](int a, int b) {
                return mp(p[a], a) < mp(p[b], b);
                });
        ld l = 0., r = 1.;
        int max_it = 100;
        forn (_, max_it) {
            ld mid = (l + r) / 2.;
            bool can = true;
            ld right_border = 0;
            for (int l = 0; l < n; ) {
                int r = l + 1;
                while (r < n && p[good_ids[l]] == p[good_ids[r]]) ++r;
                ld new_right_border = right_border;
                forn (i, l, r) {
                    int id = good_ids[i];
                    ld cur_left_border, cur_right_border;
                    cur_left_border = ld(p[id]) * (1. - mid * ld(max_sum[id]) / ld(T));
                    cur_right_border = ld(p[id]) * (1. - mid * ld(min_sum[id]) / ld(T));
                    if (cur_left_border < right_border - 1e-9) {
                        can = false;
                    }
                    umx(new_right_border, cur_right_border);
                }
                right_border = new_right_border;
                l = r;
            }
            if (can) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans = (l + r) / 2.;
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