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
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

int P;
vvi comp;

using ull = unsigned long long;
using pull = pair<ull, ull>;
using vpull = vector<pull>;

inline bool has(pull& bs, int i) {
    if (i < 64) return bs.f & (1ull << i);
    else return bs.s & (1ull << (i - 64));
}

inline void give(pull& bs, int i) {
    if (i < 64) bs.f |= 1ull << i;
    else bs.s |= 1ull << (i - 64);
}

const int CH = 9, PC = 14;
const int MASK = (1 << PC) - 1;
inline int get(const pull& bs, int i, int j) {
    int res = 0;
    if (i < 64) res |= (bs.f << i) & MASK;
    if (i + j > 64) res |= (bs.s << max(0, i - 64)) & ((1 << (j - max(i, 64))) - 1);
    return res;
}

int main() {
    setIO();

    int N, K; re(N, K);

    P = 1; FOR (v, 2, K + 1) P *= v;

    vvi perms(P);
    map<vi, int> id;

    vi p(K); F0R (i, K) p[i] = i;
    F0R (i, P) {
        perms[i] = p;
        id[p] = i;
        next_permutation(all(p));
    }
    sort(all(p));

    auto compose = [&](const vi& a, const vi& b) {
        vi x = p, y = p;
        F0R (i, K) y[i] = x[a[i]];
        swap(x, y);
        F0R (i, K) y[i] = x[b[i]];
        return id[y];
    };

    comp.resz(P); trav (v, comp) v.resz(P);
    F0R (i, P) F0R (j, P) {
        comp[i][j] = compose(perms[i], perms[j]);
    }

    set<pull> subg;
    map<pull, map<int, pull>> prod;
    subg.insert({1,0});
    queue<pull> bfs; bfs.push({1, 0});

    map<pull, int> who;
    vpull ord;

    while (!bfs.empty()) {
        pull sg = bfs.front(); bfs.pop();
        who[sg] = sz(ord);
        ord.pb(sg);

        F0R (j, P) {
            pull succ = sg;
            queue<int> intr({j});
            while (!intr.empty()) {
                int pid = intr.front(); intr.pop();
                F0R (i, P) if (has(succ, i)) {
                    int e1 = comp[i][pid];
                    if (!has(succ, e1)) { give(succ, e1); intr.push(e1); }
                    int e2 = comp[pid][i];
                    if (!has(succ, e2)) { give(succ, e2); intr.push(e2); }
                }
            }
            prod[sg][j] = succ;
            if (succ != sg && !subg.count(succ)) {
                bfs.push(succ);
                subg.insert(succ);
            }
        }
    }

    int S = sz(subg);
    vvi bbao(S, vi(P));
    F0R (i, sz(subg)) F0R (j, P) {
        bbao[i][j] = who[prod[ord[i]][j]];
    }
    vi ssz(S);
    F0R (s, S) {
        pull sg = ord[s];
        ssz[s] = __builtin_popcountll(sg.f) + __builtin_popcountll(sg.s);
    }

    vi trix(N);
    F0R (i, N) {
        vi per(K); re(per); trav (e, per) --e;
        trix[i] = id[per];
    }

    ll ans = 0;
    vi chi, CHI;

    F0Rd (l, N) {
        CHI = {l};
        int can = bbao[0][trix[l]];
        trav (r, chi) {
            int would = bbao[can][trix[r]];
            if (would != can) {
                ans += (r - CHI.back()) * ssz[can];
                can = would;
                CHI.push_back(r);
            }
        }
        ans += (N - CHI.back()) * ssz[can];
        swap(chi, CHI);
    }

    ps(ans);

    return 0;
}