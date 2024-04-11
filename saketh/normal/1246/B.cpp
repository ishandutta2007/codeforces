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

// sieve {{{
template<size_t N> struct sieve {
    vi primes;
    struct num {
        int lp;   // least prime divisor
        char lpk; // multiplicity of least prime divisor
        int pp;  // lp ** lpk
        int pd;   // largest proper divisor (num / lp)
        int wlp;  // largest divisor without the least prime (num / (lp ** lpk))
        int phi;  // euler's totient function
        char mu;  // mobius function
    };
    vector<num> nums;
    const num& operator[](int i){ return nums[i]; }

    sieve() : nums(N + 1) {
        nums[1] = { -1, 0, 1, -1, -1, 1, 1 };
        for (int i = 2; i <= N; i++) {
            num& n = nums[i];
            if (!n.lp) {
                n = { i, 1, i, 1, 1, i-1, -1 };
                primes.pb(i);
            }
            for (int p : primes) {
                if (p > n.lp || p * i > N) break;
                if (p < n.lp) nums[p * i] = { p, 1, p, i, i, n.phi * (p - 1), -n.mu };
                else nums[p * i] = { p, n.lpk + 1, n.pp * p, i, n.wlp, n.phi * p, 0 };
            }
        }
    }

    bool is_prime(int v) {
        assert(0 < v && v <= N);
        return nums[v].lp == v;
    }

    vpii factor(int v) {
        assert(0 < v && v <= N);
        vpii res;
        for (; v > 1; v = nums[v].wlp)
            res.emplace_back(nums[v].lp, nums[v].lpk);
        reverse(all(res));
        return res;
    }

    vi divisors(int v) {
        assert(0 < v && v <= N);
        if (v == 1) return {1};
        vi res;
        for (int d : divisors(nums[v].wlp))
            for (int k = 0; k <= nums[v].lpk; k++, d *= nums[v].lp)
                res.pb(d);
        return res;
    }

    int gcd(int a, int b) {
        if (a == 0) return b; else assert(0 < a && a <= N);
        if (b == 0) return a; else assert(0 < b && b <= N);
        int g = 1;
        while (a > 1 && b > 1) {
            const num &na = nums[a], &nb = nums[b];
            if (na.lp == nb.lp) {
                g *= min(na.pp, nb.pp);
                a = na.wlp, b = nb.wlp;
            } else if (na.lp < nb.lp) a = na.wlp;
            else b = nb.wlp;
        }
        return g;
    }
};
// }}}
const int MVAL = 1e5 + 1;
sieve<MVAL> sv;

int main() {
    setIO();

    int N, K; re(N, K); vi a(N); re(a);

    ll ans = 0;
    map<ll, int> have;

    trav (e, a) {
        ll x = 1, y = 1;
        trav (p, sv.factor(e)) {
            p.s %= K;
            if (p.s) {
                F0R (k, K) {
                    if (k < p.s) x *= p.f;
                    else if (y <= LLONG_MAX / p.f) y *= p.f;
                    else y = LLONG_MAX;
                }
            }
        }
        ans += have[y];
        have[x]++;
    }

    ps(ans);

    // did you check n=1?
    return 0;
}