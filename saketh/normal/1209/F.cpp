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
    template<class T> void pr(const deque<T>& x);
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
    template<class T> void pr(const deque<T>& x) { prContain(x); }
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
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
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

// modnum {{{
template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { ll w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(ll e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static int totient() {
        int tot = MOD, tmp = MOD;
        for (int p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static int primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        int tot = totient(), tmp = tot;
        vi tot_pr;
        for (int p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (int r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (int p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static int discrete_log(modnum v) {
        static const int M = ceil(sqrt(MOD));
        static unordered_map<int, int> table;
        if (table.empty()) {
            modnum e = 1;
            for (int i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (int i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum fact(int n) {
        static vector<modnum> fact = { 1 };
        for (assert(n >= 0); fact.size() <= n; )
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum finv(int n) {
        static vector<modnum> finv = { 1 };
        for (assert(n >= 0); finv.size() <= n; )
            finv.push_back(finv.back() / finv.size());
        return finv[n];
    }

    static modnum ncr(int n, int r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};
// }}}
using mn = modnum<int(1e9 + 7)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

int main() {
    setIO();

    int N, M; re(N, M);
    vi dest;
    vvi adj(N);
    F0R (i, M) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(sz(dest)); dest.pb(v);
        adj[v].pb(sz(dest)); dest.pb(u);
    }

    vs nums(M); F0R (i, M) nums[i] = to_string(i+1);
    vi dc(M); F0R (i, M) dc[i] = sz(nums[i]);
    vmn p10(10); p10[0] = 1; FOR (l, 1, 10) p10[l] = p10[l-1] * 10;

    vi len(N, INT_MAX); len[0] = 0;
    priority_queue<pii> pq; pq.push({ -0, 0 });
    while (!pq.empty()) {
        int cdist, cloc; tie(cdist, cloc) = pq.top(); pq.pop();
        if ((cdist *= -1) != len[cloc]) continue;
        trav (ei, adj[cloc]) if (cdist + dc[ei/2] < len[dest[ei]]) {
            len[dest[ei]] = cdist + dc[ei/2];
            pq.push({ -len[dest[ei]], dest[ei] });
        }
    }

    const int MAXL = *max_element(all(len)) + 1;
    vvpii layer(MAXL);
    vvi indx(M); F0R (i, M) indx[i].resz(sz(nums[i]));

    vvi wlen(MAXL); F0R (i, N) wlen[len[i]].pb(i);
    vmn path(N); vi ine(N, -1);

    F0R (sl, MAXL) {
        auto key = [&](int e, int i) {
            char last = nums[e/2][i];
            if (i) return make_pair(indx[e/2][i-1], last);
            if (dest[e^1] == 0) return make_pair(0, last);
            return make_pair(indx[ine[dest[e^1]]/2].back(), last);
        };
        sort_by(layer[sl], key(a.f, a.s) < key(b.f, b.s));
        {
            int i = 0;
            pair<int, char> lkey = {-1, 0};
            trav (p, layer[sl]) {
                auto pkey = key(p.f, p.s);
                if (pkey != lkey) { lkey = pkey; i++; }
                indx[p.f/2][p.s] = i;
            }
        }

        trav (r, wlen[sl]) {
            if (r) {
                pair<int, pii> best = { INT_MAX, {-1, -1}};
                trav (ei, adj[r]) {
                    if (len[dest[ei]] + dc[ei/2] == len[r]) {
                        ckmin(best, {indx[ei/2].back(), {dest[ei], ei^1}});
                    }
                }
                ine[r] = best.s.s;
                path[r] = path[best.s.f] * p10[dc[ine[r]/2]] + ine[r]/2 + 1;
            }
            trav (ei, adj[r]) if (len[r] + dc[ei/2] == len[dest[ei]]) {
                F0R (i, min(dc[ei/2], MAXL - len[r] + 1)) {
                    layer[sl + i + 1].eb(ei, i);
                }
            }
        }
    }

    FOR (i, 1, N) ps(path[i]);

    return 0;
}