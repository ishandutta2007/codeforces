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

    int n, k, a, b, q;
    vi d, aa, p;
	
	bool read () {
        if (scanf("%d%d%d%d%d", &n, &k, &a, &b, &q) != 5) return 0;
        d.assign(q, -1);
        aa = p = d;
        forn (i, q) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                scanf("%d%d", &d[i], &aa[i]);
                --d[i];
            } else {
                scanf("%d", &p[i]);
                --p[i];
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
	
    vi sum_b, sum_a;
    int curk;
    vi cnt;

    void filter() {
		curk = 2;
        while (curk < n) curk *= 2;
        sum_b.assign(2 * curk, 0);
        sum_a = sum_b;
        cnt.assign(n, 0);
    }

    void update(int x, vi &tree, int bord) {
        x += curk;
        tree[x] = min(cnt[x - curk], bord);
        while (x != 1) {
            x /= 2;
            tree[x] = tree[x * 2] + tree[x * 2 + 1];
        }
    }

    int get_sum(int from, int to, const vi &tree) const {
        int res = 0;
        from += curk;
        to += curk;
        while (from < to) {
            if (from % 2 == 1) res += tree[from];
            if (to % 2 == 0) res += tree[to];
            from = (from + 1) / 2;
            to = (to - 1) / 2;
        }
        if (from == to) res += tree[from];
        return res;
    }

	void solve () {
        filter();
        forn (i, q) {
            if (d[i] != -1) { // type 1
                cnt[d[i]] += aa[i];
                update(d[i], sum_b, b);
                update(d[i], sum_a, a);
            } else { // type 2
                int res = 0;
                if (p[i]) {
                    res += get_sum(0, p[i] - 1, sum_b);
                }
                if (p[i] + k != n) {
                    res += get_sum(p[i] + k, n - 1, sum_a);
                }
                ans.pb(res);
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