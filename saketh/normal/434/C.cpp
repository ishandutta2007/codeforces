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

template<char MIN_CHAR, int SIGMA> struct trie {
    struct node {
        // link: contains trie links + failure links
        // suff: link to longest proper suffix that exists in the trie
        // dict: link to longest suffix that exists in the dictionary
        // wct: number of suffixes that are words in the dictionary
        // wid: index of this node's word in the dictionary
        array<int, SIGMA> link;
        int depth, suff, dict, wct, wid;
        node(int depth) : depth(depth), suff(0), dict(0), wct(0), wid(-1) {
            fill(all(link), 0);
        }
        int& operator [] (char c) { return link[c - MIN_CHAR]; }
    };

    int W;
    vector<node> nodes;

    /*
     * Builds a trie over the given word set and calculates Aho-Corasick links.
     * Runs in O(sum of word lengths).
     */
    trie() {}
    trie(auto begin, auto end, vi& wt) : W(0), nodes({ node(0) }) {
        auto wit = wt.begin();
        for (auto it = begin; it != end; it++) {
            int loc = 0;
            for (char c : *it) {
                assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
                if (!nodes[loc][c]) {
                    nodes[loc][c] = nodes.size();
                    nodes.push_back(nodes[loc].depth + 1);
                }
                loc = nodes[loc][c];
            }
            nodes[loc].dict = loc;
            nodes[loc].wct += *wit++;
            nodes[loc].wid = W++;
        }

        for (queue<int> bfs({0}); !bfs.empty(); bfs.pop()) {
            int loc = bfs.front(), fail = nodes[loc].suff;
            if (!nodes[loc].dict)
                nodes[loc].dict = nodes[fail].dict;
            nodes[loc].wct += nodes[fail].wct;

            for (char c = MIN_CHAR; c < MIN_CHAR + SIGMA; c++) {
                int& succ = nodes[loc][c];
                if (succ) {
                    nodes[succ].suff = loc ? nodes[fail][c] : 0;
                    bfs.push(succ);
                } else succ = nodes[fail][c];
            }
        }
    }

    /*
     * Computes and returns the number of appearances of each word in the dictionary
     * as a substring of the given string.
     *
     * Runs in O(length of string to be searched + number of words in the dictionary).
     */
    vi matches(const string& text) const {
        vi res(W);
        priority_queue<pair<int, int>> found;

        int loc = 0;
        for (char c : text) {
            loc = nodes[loc].link[c - MIN_CHAR];
            int match = nodes[loc].dict;
            if (match) {
                if (!res[nodes[match].wid]++)
                    found.push({ nodes[match].depth, match });
            }
        }

        while (!found.empty()) {
            int loc = found.top().second; found.pop();
            int nxt = nodes[nodes[loc].suff].dict;
            if (nxt) {
                if (!res[nodes[nxt].wid]) found.push({ nodes[nxt].depth, nxt });
                res[nodes[nxt].id] += res[nodes[loc].id];
            }
        }
        return res;
    }

    /*
     * Computes and returns the total number of appearances of all words in the
     * dictionary as substrings of the given string.
     *
     * Runs in O(length of string to be searched).
     */
    ll search(const string& text) const {
        ll res = 0;
        int loc = 0;
        for (char c : text) {
            loc = nodes[loc].link[c - MIN_CHAR];
            res += nodes[loc].wct;
        }
        return res;
    }
};

using vc = vector<char>;
vc read() {
    int L; re(L); vc res(L);
    trav (e, res) { int v; re(v); e = v; }
    return res;
}

int M, K;
bool cache[201][201][501][2][2];
mn res[201][201][501][2][2];

mn go(trie<0, 20>& aho, vc& R, int i, int loc, int tot, bool top, bool lead) {
    if (tot > K) return 0;
    if (i == sz(R)) return 1;

    bool& fl = cache[i][loc][tot][top][lead];
    mn& ans = res[i][loc][tot][top][lead];
    if (fl) return ans; else fl = true;

    ans = 0;
    F0R (ndig, top ? R[i] + 1 : M) {
        int nloc = (!lead || ndig > 0) ? aho.nodes[loc].link[ndig] : loc;
        ans += go(aho, R, i+1, nloc, tot + aho.nodes[nloc].wct, top && ndig == R[i], lead && !ndig);
    }
    return ans;
}

int main() {
    setIO();

    int N; re(N, M, K);

    vc L = read(), R = read();
    while (sz(L) < sz(R)) L.insert(L.begin(), 0);
    F0Rd (i, sz(L)) {
        if (L[i] > 0) { L[i]--; break; }
        L[i] = M-1;
    }

    vector<vc> str(N); vi wt(N);
    F0R (i, N) str[i] = read(), re(wt[i]);
    trie<0, 20> aho(all(str), wt);

    mn ans = go(aho, R, 0, 0, 0, true, true);
    memset(cache, 0, sizeof(cache));
    ans -= go(aho, L, 0, 0, 0, true, true);
    ps(ans);

    return 0;
}