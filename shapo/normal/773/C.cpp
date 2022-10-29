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
    ve< ll > a;

    bool read () {
        if (scanf("%d", &n) != 1) return 0;
        a.resize(n);
        forn (i, n) {
            scanf("%" SCNd64, &a[i]);
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
        if (ans.empty()) {
            printf("-1\n");
        } else {
            for (int x : ans) {
                printf("%d ", x);
            }
            printf("\n");
        }
    }
};

const int B_SIZE = 42;

struct Solution: Data {
    vi ncnt, bcnt;

    bool can(int m) {
        // debug(m);
        vi good, rest;
        good.assign(B_SIZE, 0); rest = good;
        vi t_ncnt = ncnt;
        if (t_ncnt[0] < m) {
            return false;
        }
        int mval = m;
        for (int i = 0; i < B_SIZE; ++i) {
            int nval = min(mval, t_ncnt[i]);
            int diff = mval - nval;
            t_ncnt[i] -= nval;
            good[i] = diff;
            mval = nval;
        }
        for (int i = 0; i < B_SIZE; ++i) {
            rest[i] = t_ncnt[i] + bcnt[i];
        }
        // debug(good);
        // debug(rest);
        int accum = 0;
        for (int i = 40; i >= 0; --i) {
            if (accum + good[i] < rest[i]) {
                return false;
            }
            accum += good[i] - rest[i];
        }
        return true;
    }

    void solve () {
        ans.clear();
        ncnt.assign(B_SIZE, 0); bcnt = ncnt;
        for (ll x : a) {
            int pos = 0;
            while (x > (1ll << pos)) pos++;
            if (x == (1ll << pos)) {
                ncnt[pos]++;
            } else {
                bcnt[pos]++;
            }
        }
        int lm = (ncnt[0] + 1) / 2, rm = ncnt[0];
        for (int tm = lm; tm <= rm; ++tm) {
            if (can(tm)) ans.push_back(tm);
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