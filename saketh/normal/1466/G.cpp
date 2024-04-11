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

// {{{
#include <vector>
#include <numeric>
#include <algorithm>

namespace stable_counting_sort {
    template<typename T = int>
    T identity(const T& t) { return t; }

    template<typename T_extract_key = int(*)(const int&)>
    const std::vector<int>& permutation(int SZ, int MAX_KEY,
            const T_extract_key &extract_key = identity) {

        static std::vector<int> p;
        p.resize(SZ);

        if (SZ < 256) {
            std::iota(p.begin(), p.end(), 0);
            std::sort(p.begin(), p.end(), [&](int a, int b) {
                return extract_key(a) < extract_key(b);
            });
        } else {
            static std::vector<int> count;
            count.assign(MAX_KEY, 0);
            for (int i = 0; i < SZ; i++)
                count[extract_key(i)]++;
            for (int i = 0; i < MAX_KEY - 1; i++)
                count[i + 1] += count[i];
            for (int i = SZ - 1; i >= 0; i--)
                p[--count[extract_key(i)]] = i;
        }

        return p;
    }
}
// }}}

// kmp {{{
#include <vector>

struct knuth_morris_pratt {
    int SZ;
    std::vector<int> pattern;
    std::vector<int> suffix_link;

    int append(int matched, int c) const {
        while (matched > 0 && pattern[matched] != c)
            matched = suffix_link[matched];
        return matched + int(pattern[matched] == c);
    }

    knuth_morris_pratt() : SZ(0) { }

    template<typename InputIterator>
    knuth_morris_pratt(InputIterator begin, InputIterator end) {
        initialize(begin, end);
    }

    template<typename InputIterator>
    void initialize(InputIterator begin, InputIterator end) {
        pattern.resize(end - begin);
        copy(begin, end, pattern.begin());

        SZ = int(pattern.size());
        suffix_link.resize(SZ + 1);

        for (int matched = 1; matched < SZ; matched++)
            suffix_link[matched + 1] = append(suffix_link[matched], pattern[matched]);
    }

    template<typename InputIterator, typename F>
    void find_matches(InputIterator begin, InputIterator end, F consume) const {
        int i = 0;
        int matched = 0;
        for (InputIterator iter = begin; iter != end; iter++, i++) {
            matched = append(matched, *iter);
            if (matched == SZ) {
                consume(i - SZ + 1);
                matched = suffix_link[matched];
            }
        }
    }

    template<typename InputIterator>
    int count_matches(InputIterator begin, InputIterator end) const {
        int count = 0;
        find_matches(begin, end, [&](__attribute((unused))int index) { count++; });
        return count;
    }

    template<typename InputIterator>
    std::vector<int> indices_of_matches(InputIterator begin, InputIterator end) const {
        std::vector<int> indices;
        find_matches(begin, end, [&](int index) { indices.push_back(index); });
        return indices;
    }
};
// }}}

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
            finv.resz(n + 1), finv[n] = factorial(n).inv();
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
using mn = modnum<int(1e9 + 7)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;

const int MAXL = 1e6;

int main() {
    setIO();

    int N, Q;
    string s, t;
    re(N, Q, s, t);

    vs names(Q);
    vi song(Q);
    vmn ans(Q);

    vector<knuth_morris_pratt> kmp;

    F0R (q, Q) {
        re(song[q], names[q]);
        kmp.eb(all(names[q]));
    }

    // generate until they are long enough
    vs songs = { s };
    {
        F0R (q, Q) {
            ans[q] = kmp[q].count_matches(all(s));
        }

        int did = 0;
        while (did < N && sz(songs.back()) < MAXL) {
            songs.push_back(songs.back() + t[did] + songs.back());
            did++;

            F0R (q, Q) {
                if (song[q] < did)
                    continue;

                ans[q] *= 2;

                int tpos = sz(songs.back()) / 2;

                int inx_min = max(0, tpos - sz(names[q]) + 1);
                int inx_max = min(sz(songs.back()), tpos + sz(names[q]));

                ans[q] += kmp[q].count_matches(songs.back().begin() + inx_min, songs.back().begin() + inx_max);
            }
        }
    }

    // count copies created by joins for each possible center char
    vector<array<int, 26>> upon_join(Q);
    {
        const int LSZ = sz(songs.back());

        F0R (q, Q) {
            int M = 0;

            int LOC = 0;
            FOR (i, LSZ - sz(names[q]) + 1, LSZ) {
                LOC = kmp[q].append(LOC, songs.back()[i]);
                if (LOC == sz(names[q])) {
                    M++;
                    LOC = kmp[q].suffix_link[LOC];
                }
            }

            F0R (c, 26) {
                int m = M;

                int loc = kmp[q].append(LOC, 'a' + c);
                if (loc == sz(names[q])) {
                    m++;
                    loc = kmp[q].suffix_link[loc];
                }

                F0R (i, sz(names[q]) - 1) {
                    loc = kmp[q].append(loc, songs.back()[i]);
                    if (loc == sz(names[q])) {
                        m++;
                        loc = kmp[q].suffix_link[loc];
                    }
                }

                upon_join[q][c] = m;
            }
        }
    }

    // extrapolate results
    {
        vector<array<mn, 27>> coeff(N + 1);
        coeff[sz(songs) - 1].back() = 1;

        FOR (i, sz(songs), sz(coeff)) {
            coeff[i] = coeff[i - 1];
            trav (e, coeff[i])
                e += e;
            coeff[i][t[i - 1] - 'a'] += 1;
        }

        F0R (q, Q) {
            if (song[q] >= sz(songs)) {
                ans[q] *= coeff[song[q]].back();
                F0R (c, 26)
                    ans[q] += upon_join[q][c] * coeff[song[q]][c];
            }
        }
    }

    trav (e, ans) {
        ps(e);
    }

    return 0;
}