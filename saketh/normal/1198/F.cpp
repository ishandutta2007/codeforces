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

vi factors(int V) {
    vi res;
    for (int v = 2; v * v <= V; v++) {
        if (V % v != 0) continue;
        res.pb(v);
        while (V % v == 0) V /= v;
    }
    if (V > 1) res.pb(V);
    assert(sz(res) <= 9);
    return res;
}

bool reach[18 * 18][1 << 9][1 << 9];
bool go(vector<array<int, 3>>& elts, int inx, int m0, int m1, vb& assign) {
    if (m0 == 0 && m1 == 0) return true;
    if (inx >= sz(elts) || reach[inx][m0][m1]) return false;
    reach[inx][m0][m1] = true;

    if (go(elts, inx+1, m0 & elts[inx][1], m1, assign)) return true;
    assign[inx] = true;
    if (go(elts, inx+1, m0, m1 & elts[inx][2], assign)) return true;
    assign[inx] = false;
    return false;
}

int main() {
    setIO();

    int N; re(N); vi a(N); re(a);

    if (N < 20) {
        FOR (m, 1, 1 << (N - 1)) {
            int g1 = 0, g2 = 0;
            F0R (i, N) {
                if (m & (1 << i)) g2 = __gcd(g2, a[i]);
                else g1 = __gcd(g1, a[i]);
            }

            if (g1 == 1 && g2 == 1) {
                ps("YES");
                F0R (i, N) {
                    if (i) pr(" ");
                    pr(m & (1 << i) ? 2 : 1);
                }
                ps();
                return 0;
            }
        }

        ps("NO");
        return 0;
    }

    int REP = 0;
    double fail = 1.;
    while (fail > 1e-9) {
        fail *= 9. / (N - 1);
        REP++;
    }
    F0R (rep, REP) {
        int k = rng() % (N - 1) + 1;
        vi f0 = factors(a[0]), f1 = factors(a[k]);

        vector<array<int, 3>> elts;

        const int TF = sz(f0) + sz(f1);
        vi h0(sz(f0)), h1(sz(f1));

        F0R (i, N) if (i != 0 && i != k) {
            bool take = false;
            int m0 = 0, m1 = 0;
            F0R (j, sz(f0)) {
                if (a[i] % f0[j] == 0) {
                    m0 |= 1 << j;
                } else {
                    take |= h0[j]++ < TF;
                }
            }
            F0R (j, sz(f1)) {
                if (a[i] % f1[j] == 0) {
                    m1 |= 1 << j;
                } else {
                    take |= h1[j]++ < TF;
                }
            }
            if (take) elts.pb({i, m0, m1});
        }

        memset(reach, 0, sizeof(reach));
        vb assign(sz(elts));
        if (go(elts, 0, (1 << sz(f0)) - 1, (1 << sz(f1)) - 1, assign)) {
            vb res(N); res[k] = true;
            F0R (i, sz(elts)) if (assign[i]) res[elts[i][0]] = true;
            ps("YES");
            F0R (i, N) {
                if (i) pr(" ");
                pr(res[i] ? 2 : 1);
            }
            ps();
            return 0;
        }
    }

    ps("NO");

    return 0;
}