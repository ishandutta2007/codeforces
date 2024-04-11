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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

#define ook order_of_key
#define fbo find_by_order

bool LOCAL = 0;
vi secret;

bool query(int a, int b) {
    if (LOCAL) return secret[a] < secret[b];
    ps("?", a+1, b+1); cout << flush;
    char r; re(r); return r == '<';
}

const int MAXP = 200;
bitset<200> reach[MAXP];
vi order;

void reset(int N) {
    F0R (p, MAXP) reach[p].reset();
    order.resz(2 * N);
    F0R (i, 2 * N) order[i] = i;
    if (LOCAL) {
        if (N == 3) {
            secret = {207789888, 1819976271, -643235242, 34230353, -301917541, -1553883093};
        } else {
            secret.resz(2 * N);
            F0R (i, sz(secret)) secret[i] = rng();
            vi tmp = secret; dedup(tmp); assert(sz(tmp) == 2 * N);
        }
    }
}

bool lt(int a, int b) {
    if (reach[a][b] || reach[b][a]) return reach[a][b];
    bool r = query(a, b);
    reach[a][b] =  r;
    reach[b][a] = !r;
    sort_by(order, (reach[a][b] || reach[b][a]) ? reach[a][b] : (a < b));
    F0Rd (_i, sz(order)) {
        int i = order[_i];
        F0R (j, sz(order)) if (reach[i][j]) reach[i] |= reach[j];
    }
    return r;
}

int find_worst(set<int>& look) {
    int res = -1;
    trav (e, look) {
        if (res == -1) res = e;
        else if (lt(e, res)) res = e;
    }
    return res;
}

void solve() {
    int N; re(N), reset(N);

    vpii pairs;
    F0R (i, N) {
        bool res = lt(2 * i, 2 * i + 1);
        pairs.eb(2 * i + !res, 2 * i + res);
    }

    set<int> losers;
    while (losers.size() < N) {
        int next;
        set<int> possible;
        {
            sort_by(pairs, lt(a.f, b.f));
            int t = 0;
            while (losers.count(pairs[t].f)) {
                if (!losers.count(pairs[t].s)) possible.insert(pairs[t].s);
                t++;
            }
            next = pairs[t].f;
        }

        if (sz(possible)) {
            int worst = find_worst(possible);
            if (lt(worst, next)) next = worst;
        }
        losers.insert(next);
    }

    int known = 0;
    F0R (i, 2 * N) known += reach[i].count();
    if (known == (2 * N * (2 * N - 1) / 2)) {
        cerr << "BAD!" << endl;
    }

    assert(sz(losers) == N);
    F0R (i, 2 * N) if (!losers.count(i)) {
        trav (j, losers) assert(reach[j][i]);
    }
    ps("!"); cout << flush;
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        //pr("Case #", t+1, ": ");
        solve();
    }

    // did you check N=1? did you mix up N,M?
    // check your "infinity" and "null" values against the bounds
    return 0;
}