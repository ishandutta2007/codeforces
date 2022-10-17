// modnum {{{
#include <cstdint>
#include <cassert>
#include <limits>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>

using v_t = int;
using vv_t = int64_t;

template<v_t MOD> struct modnum {
    static_assert(std::numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(std::numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");

    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend std::istream& operator >> (std::istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend std::ostream& operator << (std::ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
    friend bool operator <  (const modnum& a, const modnum& b) { return a.v <  b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; std::swap(g, r);
            x -= q * y; std::swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        std::vector<int> tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (std::gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(std::sqrt(MOD));
        static std::unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static std::vector<modnum> table{ 0, 1 };
        while (int(table.size()) <= deg) {
            modnum w = unity_root(int(table.size()));
            for (int s = int(table.size()), i = s / 2; i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum factorial(int n) {
        static std::vector<modnum> fact = {1};
        assert(n >= 0);
        if (int(fact.size()) <= n) {
            int had = fact.size();
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static std::vector<modnum> finv = {1};
        assert(n >= 0);
        if (int(finv.size()) <= n) {
            int had = finv.size();
            finv.resize(n + 1), finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);
        }
        return finv[n];
    }

    static modnum small_inv(int n) {
        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
    }
};
// }}}

// tarjan {{{
#include <vector>

struct scc {
    int components;
    std::vector<int> label;
};

// Labels strongly connected components in reverse topological order.
// That means for any edge u-->v label[u] >= label[v].
scc strongly_connected_components(const std::vector<std::vector<int>>& graph) {
    const int N = int(graph.size());

    int C = 0, V = 0, top = 0;
    std::vector<int> comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = std::min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = std::min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}
// }}}

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
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

using mn = modnum<int(998244353)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

// {{{
template<typename T>
struct matrix {
    int N, M;
    vector<T> data;

    matrix(int _N, int _M, T value = T{}) : N(_N), M(_M), data(N * M, value) {}

    typename vector<T>::iterator operator[](int i) {
        return data.begin() + i * M;
    }
    typename vector<T>::const_iterator operator[](int i) const {
        return data.begin() + i * M;
    }

    friend matrix<T> operator * (const matrix<T>& a, const matrix<T>& b) {
        assert(a.M == b.N);
        matrix<T> res(a.N, b.M);
        for (int i = 0; i < a.N; i++)
            for (int k = 0; k < a.M; k++)
                for (int j = 0; j < b.M; j++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    friend vector<T> operator * (const vector<T>& v, const matrix<T>& m) {
        assert(sz(v) == m.N);
        vector<T> res(m.M);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[j] += v[i] * m[i][j];
        return res;
    }

    friend vector<T> operator * (const matrix<T>& m, const vector<T>& v) {
        assert(m.M == sz(v));
        vector<T> res(m.N);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[i] += m[i][j] * v[j];
        return res;
    }

    matrix pow(ll e) const {
        assert(N == M);
        if (e == 0) return matrix<T>(N, N, 0, 1);
        if (e&1) return *this * pow(e - 1);
        return (*this * *this).pow(e / 2);
    }

    friend void row_reduce(matrix<T> &m) {
        int rank = 0;
        for (int j = 0; j < m.M && rank < m.N; j++) {
            for (int i = rank; i < m.N; i++) {
                if (m[i][j] != 0) {
                    swap_ranges(m[rank], m[rank] + m.M, m[i]);
                    break;
                }
            }
            if (m[rank][j] == 0)
                continue;

            T inv = 1 / m[rank][j];
            for (int k = j; k < m.M; k++)
                m[rank][k] *= inv;

            for (int i = 0; i < m.N; i++) {
                if (i != rank) {
                    T c = m[i][j];
                    for (int k = j; k < m.M; k++)
                        m[i][k] -= c * m[rank][k];
                }
            }
            rank++;
        }

        m.N = rank;
        m.data.resize(m.N * m.M);
    }

    friend ostream& operator <<(ostream& os, const matrix<T>& m) {
        for (int i = 0; i < m.N; i++) {
            os << (i ? i < m.N - 1 ? "\u2503" : "\u2517" : "\n\u250F");
            for (int j = 0; j < m.M; j++)
                os << setw(12) << m[i][j];
            os << "  " << (i ? i < m.N - 1 ? "\u2503" : "\u251B" : "\u2512") << "\n";
        }
        return os;
    }
};
// }}}

int main() {
    setIO();

    int N, M; re(N, M);

    vvi adj(N);
    F0R (e, M) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
    }

    scc s = strongly_connected_components(adj);
    assert(s.components == N);

    vi topo(N);
    iota(all(topo), 0);

    sort_by(topo, s.label[a] < s.label[b]);

    vi mex(N);

    trav (u, topo) {
        vi reach;
        trav (v, adj[u])
            reach.pb(mex[v]);

        dedup(reach);

        int m = 0;
        while (m < sz(reach) && reach[m] == m)
            m++;

        mex[u] = m;
    }

    int MAX_MEX = *max_element(all(mex)) + 1;

    if (MAX_MEX == 0) {
        ps(0);
        return 0;
    }

    while (__builtin_popcount(MAX_MEX) > 1)
        MAX_MEX++;

    vi ct(MAX_MEX);
    F0R (i, N) ct[mex[i]]++;

    matrix<mn> A(MAX_MEX + 1, MAX_MEX + 2);

    F0R (mex, MAX_MEX) {
        F0R (op, MAX_MEX) {
            A[mex][mex ^ op] = ct[op] * mn::small_inv(N + 1);
        }
        A[mex][mex] -= 1;
    }

    // good termination
    A[0][MAX_MEX] = mn::small_inv(N + 1);

    // this guy is just 1
    A[MAX_MEX][MAX_MEX] = 1;
    A[MAX_MEX][MAX_MEX + 1] = 1;

    row_reduce(A);

    ps(1 - A[0][MAX_MEX + 1]);

    return 0;
}