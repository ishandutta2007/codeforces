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

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vi64 = vector<i64>;
using vvi64 = vector<vi64>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using vpii = vector<pii>;

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
}
using namespace __algorithm;

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

bool get(int a, int b, int c) {
    ps('?', a + 1, b + 1, c + 1);
    cout << flush;

    bool res;
    re(res);
    return res;
}

bool get(array<int, 3> a) {
    return get(a[0], a[1], a[2]);
}

array<int, 3> group(int i) {
    return { 3 * i, 3 * i + 1, 3 * i + 2 };
}

void solve() {
    int N; re(N);

    vector<bool> maj(N / 3);

    int m0 = -1, m1 = -1;

    F0R (i, N / 3) {
        maj[i] = get(group(i));
        (maj[i] ? m1 : m0) = i;
    }

    auto g0 = group(m0);
    auto g1 = group(m1);

    int k0, k1;
    if (get(g0[1], g0[2], g1[0])) {
        k0 = g0[0];
        k1 = g1[0];
    } else if (get(g0[2], g1[0], g1[1])) {
        k0 = g0[1];
        k1 = g1[1];
    } else {
        k0 = g0[2];
        k1 = g1[2];
    }

    vi zeros = { k0 };

    for (auto g : { g0, g1 }) {
        for (int inx : g) {
            if (inx == k0 || inx == k1) {
                continue;
            }

            if (!get(k0, k1, inx))
                zeros.pb(inx);
        }
    }

    F0R (i, N / 3) {
        if (i == m0 || i == m1) {
            continue;
        }

        auto g = group(i);

        bool q1 = get(maj[i] ? k0 : k1, g[0], g[1]);

        if (q1 == maj[i]) {
            if (!maj[i]) {
                zeros.pb(g[0]);
                zeros.pb(g[1]);
            }

            if (!get(k0, k1, g[2])) {
                zeros.pb(g[2]);
            }
        } else {
            if (!maj[i]) {
                zeros.pb(g[2]);
            }

            if (!get(k0, k1, g[0])) {
                zeros.pb(g[0]);
            } else {
                zeros.pb(g[1]);
            }
        }
    }

    sort(all(zeros));

    pr("! ", sz(zeros));
    trav (inx, zeros) {
        pr(' ', inx + 1);
    }
    cout << endl;
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}