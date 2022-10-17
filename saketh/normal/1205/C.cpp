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
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

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
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename C, typename T> vector<T> prefixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0R (i, sz(v)) res[i+1] = res[i] + v[i]; return res;
    }
    template<typename C, typename T> vector<T> suffixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0Rd (i, sz(v)) res[i] = v[i] + res[i+1]; return res;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

int N;

bool query(int r1, int c1, int r2, int c2) {
    assert(r1 <= r2);
    assert(c1 <= c2);
    assert(r1 + c1 + 2 <= r2 + c2);
    for (int v : {r1,c1,r2,c2}) assert(0 <= v && v < N);

    ps("?", r1+1, c1+1, r2+1, c2+1); cout << flush;
    int res; re(res); return res;
}

bool neq(int r1, int c1, int r2, int c2) {
    if (r1 > r2) { swap(r1, r2); swap(c1, c2); }
    assert(r2 - r1 + c2 - c1 == 2);
    return !query(r1, c1, r2, c2);
}

int main() {
    setIO();

    re(N);

    vvi ans(N, vi(N));
    ans[0][0] = 1;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if ((row + col) % 2 != 0) continue;
            if (row == 0 && col == 0) continue;
            if (row == N-1 && col == N-1) continue;

            if (row && col) ans[row][col] = ans[row-1][col-1] ^ neq(row-1, col-1, row, col);
            else if (row) ans[row][col] = ans[row-2][col] ^ neq(row-2, col, row, col);
            else ans[row][col] = ans[row][col-2] ^ neq(row, col-2, row, col);
        }
    }

    /*{ cout << "STAGE 1 COMPLETE\n";
        ps("!");
        F0R (r, N) {
            F0R (c, N) pr(ans[r][c]);
            ps();
        }
        cout << flush;
    }*/

    vpii path;
    F0R (r, N) path.eb(r, 0);
    FOR (c, 1, N) path.eb(N-1, c);

    vb val(sz(path));
    val[0] = val[1] = 1;
    FOR (i, 2, sz(path)) {
        int r1, c1, r2, c2;
        tie(r1, c1) = path[i-2];
        tie(r2, c2) = path[i];

        if (i&1) val[i] = val[i-2] ^ neq(r1, c1, r2, c2);
        else val[i] = ans[r2][c2];
    }

    bool did = false, flip;
    for (int i = 0; true; i += 2) {
        bool neq1 = val[i] != val[i+2];
        bool neq2 = val[i+2] != val[i+4];
        if (neq1 == neq2) continue;

        bool mneq = val[i+1] != val[i+3], palin;
        if (mneq == neq1) {
            palin = query(path[i].f, path[i].s, path[i+3].f, path[i+3].s);
            if (mneq) flip = palin ^ (val[i] != val[i+1]);
            else flip = !palin ^ (val[i] != val[i+1]);
        } else {
            palin = query(path[i+1].f, path[i+1].s, path[i+4].f, path[i+4].s);
            if (mneq) flip = palin ^ (val[i+1] != val[i+2]);
            else flip = !palin ^ (val[i+1] != val[i+2]);
        }

        did = true; break;
    }
    assert(did);

    for (int i = 1; i < sz(path); i += 2) {
        ans[path[i].f][path[i].s] = val[i] ^ flip;
    }

    for (int row = N - 2; row >= 0; row--) {
        for (int col = 1; col < N; col++) {
            if ((row + col) % 2 != 1) continue;
            if (col >= 2) ans[row][col] = ans[row][col-2] ^ neq(row, col-2, row, col);
            else ans[row][col] = ans[row+2][col] ^ neq(row+2, col, row, col);
        }
    }

    ps("!");
    F0R (r, N) {
        F0R (c, N) pr(ans[r][c]);
        ps();
    }
    cout << flush;

    return 0;
}