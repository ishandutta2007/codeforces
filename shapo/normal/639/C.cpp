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
    ll k;
    vi a;

	bool read () {
        if (scanf("%d%" SCNd64, &n, &k) != 2) return 0;
        a.resize(n + 1);
        forn (i, n + 1) {
            scanf("%d", &a[i]);
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
	
    ve< ll > plus, minus;

	void solve () {
        plus.assign(n + 100, ll(0));
        minus.assign(n + 100, ll(0));
        forn (i, n + 1) {
            if (!a[i]) continue;
            if (a[i] > 0) {
                plus[i] += a[i];
            } else {
                minus[i] -= a[i];
            }
        }
        int m = sz(plus);
        forn (i, m - 1) {
            plus[i + 1] += plus[i] / 2;
            plus[i] %= 2;
            minus[i + 1] += minus[i] / 2;
            minus[i] %= 2;
        }
        int id = 0;
        ford (i, m) {
            if (plus[i] > minus[i]) {
                id = 1;
                break;
            } else if (plus[i] < minus[i]) {
                id = -1;
                break;
            }
        }
        debug(plus);
        debug(minus);
        if (id == -1) {
            forn (i, n + 1) {
                a[i] *= -1;
            }
            plus.swap(minus);
            id = 1;
        }
        int l_index = -1, r_index = 0;
        forn (i, m - 1) {
            int diff = plus[i] - minus[i];
            while (diff < 0) {
                plus[i + 1]--;
                diff += 2;
            }
            plus[i] = diff;
            if (plus[i]) {
                if (l_index == -1) {
                    l_index = i;
                }
                r_index = i;
            }
        }
        debug(plus);
        debug(mp(l_index, r_index));
        ll val = 0ll;
        ans = 0;
        ford (i, l_index, r_index + 1) {
            val = (val * 2 + plus[i]);
            if (val > 5 * k) {
                return;
            }
        }
        debug(val);
        while (l_index >= 0 && val < 5 * k) {
            if (l_index == n && a[l_index] != val && abs(a[l_index] - val) <= k) {
                ans++;
            }
            if (l_index < n && abs(a[l_index] - val) <= k) {
                ans++;
            }
            val *= 2;
            --l_index;
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