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

const bool LOCAL = 0;

string secret = "abcdhhhh";

vs get(int i, int j) {
    if (LOCAL) {
        vs res;
        FOR (st, i, j) FOR (en, st + 1, j + 1) {
            res.pb(secret.substr(st, en - st));
            sort(all(res.back()));
        }
        return res;
    }

    ps("?", i+1, j);
    cout << flush;

    int ct = (j - i) * (j - i + 1) / 2;
    vs res(ct); re(res);
    trav (e, res) sort(all(e));
    return res;
}

void finish(string ans) {
    if (LOCAL) {
        assert(ans == secret);
    }

    ps("!", ans);
    cout << flush;
    exit(0);
}

char diff(string& a, string& b) {
    vi ct(26);
    trav (e, a) ct[e-'a']++;
    trav (e, b) ct[e-'a']--;
    assert(accumulate(all(ct), 0) == 1);
    F0R (i, 26) if (ct[i]) return 'a' + i;
    assert(false);
}

string solve(int N) {
    vs full =   get(0, N);
    if (N == 1) return full[0];

    vs almost = get(1, N);

    sort(all(full));
    trav (e, almost) {
        full.erase(find(all(full), e));
    }

    sort_by(full, sz(a) < sz(b));

    string ans(N, '?');
    ans[0] = full[0][0];
    FOR (i, 1, N) ans[i] = diff(full[i], full[i-1]);

    return ans;
}

string solve(string known, int T) {
    string res(T, '?');

    int N = sz(known) + T;

    vs tail = get(N - 2 * T, N);
    sort_by(tail, sz(a) > sz(b));

    int i = 1;
    F0R (t, T) {
        int SZ = 2 * T - t - 1;

        vs str;
        while (i < sz(tail) && sz(tail[i]) == SZ) str.pb(tail[i++]);
        sort(all(str));

        FOR (j, 1, t + 2) {
            string rem = tail[0];
            F0R  (k, j) rem.erase(rem.find(known[N - 2 * T + k]), 1);
            F0R  (k, 2 * T - SZ - j) rem.erase(rem.find(res[T - 1 - k]), 1);
            auto it = find(all(str), rem);
            str.erase(it);
        }

        assert(sz(str) == 1);
        string rem = tail[0];
        trav (e, *str.begin()) rem.erase(rem.find(e), 1);
        F0R (k, 2 * T - SZ - 1) rem.erase(rem.find(res[T - 1 - k]), 1);
        res[T - 1 - t] = rem[0];
    }

    return res;
}

int main() {
    setIO();

    int N; re(N);

    if (LOCAL) {
        secret = string(N, '?');
        F0R (i, N) secret[i] = char('a' + rng() % 26);
    }

    if (N < 6) finish(solve(N));

    string front = solve(2 * N / 3);
    front += solve(front, N - sz(front));

    finish(front);

    // did you check N=1? did you mix up N,M?
    return 0;
}