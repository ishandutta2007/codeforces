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

void solve() {
    int N, X;
    re(N, X);

    vi a(N);
    re(a);

    int64_t tot = 0;
    FOR (i, 1, N) {
        tot += abs(a[i] - a[i - 1]);
    }

    // now insert both 1 and x

    vi ins1(N + 1);

    F0R (i, N + 1) { // 1 goes left of index i
        if (i) ins1[i] += abs(1 - a[i - 1]);
        if (i<N) ins1[i] += abs(1 - a[i]);
        if (i && i<N) ins1[i] -= abs(a[i - 1] - a[i]);
    }

    vi pref_min(N + 2, INT_MAX);
    vi suff_min(N + 2, INT_MAX);

    F0R (i, N + 1) {
        pref_min[i + 1] = min(pref_min[i], ins1[i]);
    }
    F0Rd (i, N + 1) {
        suff_min[i] = min(suff_min[i + 1], ins1[i]);
    }

    int ans = 2e9;

    F0R (i, N + 1) { // X goes left of index i
        int insx = 0;
        if (i) insx += abs(X - a[i - 1]);
        if (i<N) insx += abs(X - a[i]);
        if (i && i<N) insx -= abs(a[i - 1] - a[i]);

        int best1 = 1e9;

        ckmin(best1, pref_min[i]);   // 1 goes left of something <i
        ckmin(best1, suff_min[i+1]); // 1 goes left of something >=i+1;

        { // 1 goes left of x
            int ins1 = X - 1;
            if (i) {
                ins1 += abs(a[i - 1] - 1);
                ins1 -= abs(a[i - 1] - X);
            }
            ckmin(best1, ins1);
        }
        { // 1 goes right of x
            int ins1 = X - 1;
            if (i < N) {
                ins1 += abs(a[i] - 1);
                ins1 -= abs(a[i] - X);
            }
            ckmin(best1, ins1);
        }

        ckmin(ans, insx + best1);
    }

    ps(tot + ans);
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}