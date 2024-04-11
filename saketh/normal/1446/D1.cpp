#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

struct ds {
    int T;
    vi occur; // last occurence of each positive value

    vpii compress; // compressed version of "occur"

    ds (int INF) : T(0) {
        //occur = {N};
        compress = { mp(0, INF) };
    }

    void push_front(int i, int x) {
        assert(x == -1 || x > 0);

        T += x;

        /*if (T == sz(occur)) {
            occur.push_back(i);
        }*/

        if (T > compress.back().f) {
            compress.eb(T, i);
        }
    }

    int get_x() {
        auto it = lower_bound(all(compress), mp(T, -1));
        assert(it != compress.end());
        return it->s + (it->f - T);
    }

    int linear_until() {
        auto it = lower_bound(all(compress), mp(T, -1));
        assert(it != compress.end());
        return it->f - T;
    }
};

// segment_tree {{{
template<typename T, typename F> struct segment_tree {
    int SZ;
    T id; F tt;
    vector<T> table;

    segment_tree() {}
    segment_tree(int SZ_, T id_, F tt_) : SZ(SZ_), id(id_), tt(tt_) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        for (int i = 0; i < SZ; i++) table[SZ + i] = create(i);
        for (int i = SZ - 1; i; i--) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += SZ] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = tt(table[2 * i], table[2 * i + 1]);
        }
    }

    // Accumulates the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left = id, right = id;
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
    const T& operator[](int i) const { return table[SZ + i]; }
};
// }}}

int main() {
    setIO();

    int N; re(N);
    vi a(N); re(a); trav (e, a) e--;

    vi ct(N);
    trav (e, a) ct[e]++;

    int x = max_element(all(ct)) - ct.begin();
    FOR (y, x+1, N) {
        if (ct[x] == ct[y]) {
            ps(N);
            return 0;
        }
    }

    vi xloc;
    F0R (i, N) if (a[i] == x) xloc.pb(i);

    vector<ds> trackers(N, ds(sz(xloc)));

    int ans = 0;

    int most_recent_x = sz(xloc);
    vi last_active(N, sz(xloc));

    vvi reactivate(N + 1);

    vector<int> active, ACTIVE;
    vb is_active(N, false);

    auto bigger = [](int x, int y) { return max(x, y); };

    segment_tree<int, decltype(bigger)> act(N, -1, bigger);

    int adjust_inactive = 0;
    segment_tree<int, decltype(bigger)> ina(N, -1, bigger);

    xloc.pb(N);

    auto activate = [&](int y) {
        assert(!is_active[y]);

        if (most_recent_x < last_active[y]) {
            trackers[y].push_front(most_recent_x, last_active[y] - most_recent_x);
            last_active[y] = most_recent_x;
        }

        active.pb(y);
        is_active[y] = true;

        ina.replace(y, -1);
        act.replace(y, trackers[y].get_x());
    };

    F0Rd (i, N) {
        if (a[i] == x) {
            trav (y, reactivate[adjust_inactive]) {
                if (!is_active[y])
                    activate(y);
            }
            reactivate[adjust_inactive].clear();

            adjust_inactive++;

            int xi = index(xloc, i);
            most_recent_x = xi;

            ACTIVE.clear();
            trav (y, active) {
                trackers[y].push_front(xi, 1);
                last_active[y] = xi;

                if (trackers[y].linear_until() == 0) {
                    ACTIVE.pb(y);
                    act.replace(y, trackers[y].get_x());
                } else {
                    is_active[y] = false;
                    act.replace(y, -1);

                    ina.replace(y, trackers[y].get_x() + adjust_inactive);

                    reactivate[adjust_inactive + trackers[y].linear_until()].pb(y);
                }
            }

            swap(active, ACTIVE);

        } else {
            int y = a[i];
            if (!is_active[y]) {
                activate(y);
            }

            trackers[y].push_front(-1, -1);
            act.replace(y, trackers[y].get_x());
        }

        /*pd(i);
        F0R (y, N) {
            if (is_active[y]) {
                pd(y, trackers[y].T, trackers[y].compress);
            }
        }*/

        int xr = ina(0, N) - adjust_inactive;
        ckmax(xr, act(0, N));
        ckmin(xr, sz(xloc) - 1);

        if (xr > -1) {
            ckmax(ans, xloc[xr] - i);
        }
    }

    ps(ans);

    return 0;
}