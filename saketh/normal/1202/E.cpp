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
    trie(auto begin, auto end) : W(0), nodes({ node(0) }) {
        int L = 0; for (auto it = begin; it != end; it++) L += it->size();
        nodes.reserve(L);

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
            nodes[loc].wct++;
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

    vi search(const string& text) const {
        vi res;
        int loc = 0;
        for (char c : text) {
            loc = nodes[loc].link[c - MIN_CHAR];
            res.pb(nodes[loc].wct);
        }
        return res;
    }
};

int main() {
    setIO();

    string t; int N; re(t, N); vs s(N); re(s);

    trie<'a', 26> fw(all(s));
    vi mf = fw.search(t);

    trav (e, s) reverse(all(e));
    reverse(all(t));

    trie<'a', 26> bk(all(s));
    vi mb = bk.search(t);

    ll ans = 0;
    FOR (i, 0, sz(mf) - 1) {
        ans += ll(mf[i]) * mb[sz(mf) - i - 2];
    }
    ps(ans);

    return 0;
}