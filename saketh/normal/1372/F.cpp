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
using vpll = vector<pll>;
using vpdd = vector<pdd>;

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

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

bool LOCAL = 0;
vi secret;

int Q = 0;
pii query(int l, int r) {
    Q++;
    if (LOCAL) {
        map<int, int> ct;
        FOR (k, l, r) ct[secret[k]]++;

        pii res = {-1, 0};
        trav (e, ct) {
            if (e.s > res.s)
                res = e;
        }
        return res;
    }

    cout << "? " << l+1 << " " << r << endl;
    int x, f; re(x, f); return {x, f};
}

vi res;

void solve(int l, int r) {
    if (res[l] == -1) res[l] = query(l, l+1).f;
    if (res[r] == -1) res[r] = query(r, r+1).f;
    if (r - l <= 1) return;
    if (res[l] == res[r]) {
        fill(res.begin() + l + 1, res.begin() + r, res[l]);
        return;
    }

    int m = l + (r - l) / 2;
    res[m] = query(m, m+1).f;
    //cerr << l << " " << m << " " << r << " " << "QUERY ASSOCIATED WITH " << res[m] << endl;

    //cerr << "SOLVING " << l << " " << r << endl;

    if (res[m] == res[l]) {
        int ct = query(l, r).s;
        fill(res.begin() + l, res.begin() + l + ct, res[l]);
        //cerr << l << " " << m << " " << r << " " << "QUERY ASSOCIATED WITH " << res[l] << endl;
        assert(l + ct - 1 >= m);
        solve(l + ct, r);
    } else if (res[m] == res[r]) {
        int ct = query(l+1, r+1).s;
        fill(res.begin() + r + 1 - ct, res.begin() + r + 1, res[r]);
        //cerr << l << " " << m << " " << r << " " << "QUERY ASSOCIATED WITH " << res[r] << endl;
        assert(r + 1 - ct <= m);
        solve(l, r - ct);
    } else {
        //cerr << "NEWLY DISCOVERED " << res[m] << endl;
        solve(l, m);
        solve(m, r);
    }
}

void answer() {
    if (LOCAL) {
        assert(res == secret);
        auto tmp = secret;
        dedup(tmp);
        pd(secret);
        pd(Q);
        assert(Q <= 4 * sz(tmp));
    }
    pr("! "); pc(res); cout << endl;
}

int main() {
    setIO();

    int N; re(N);
    res.resz(N, -1);

    if (LOCAL) {
        secret.resz(N);
        F0R (i, N) secret[i] = rng() % 11;
        sort(all(secret));
    }

    res[0] = query(0, 1).f;
    res[N-1] = query(N-1, N).f;

    solve(0, N-1);

    answer();

    return 0;
}