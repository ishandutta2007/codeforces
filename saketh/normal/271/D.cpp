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

// {{{ numeric/modnum.cpp }}}

#include <vector>
#include <chrono>
#include <random>
#include <array>
#include <cassert>
#include <iostream>

template<typename x_t, int EvaluationPoints, int AlphabetSize>
struct polynomial_hash {
    static x_t pow(int point, int exponent) {
        static std::vector<x_t> x(EvaluationPoints, 1);

        if (int(x.size()) == EvaluationPoints) {
            x.push_back(AlphabetSize);

            std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

            for (int i = 1; i < EvaluationPoints; i++)
                x.push_back(AlphabetSize + rng() % std::max(256, AlphabetSize));
        }

        while (exponent * EvaluationPoints + point >= int(x.size()))
            for (int i = 0; i < EvaluationPoints; i++)
                x.push_back(*(x.end() - EvaluationPoints) * x[EvaluationPoints + i]);

        return x[exponent * EvaluationPoints + point];
    }

    int N;
    std::array<x_t, EvaluationPoints> data;

    polynomial_hash () : N(0) { data.fill(0); }

    polynomial_hash (x_t v) : N(1) { assert(v.v < AlphabetSize); data.fill(v); }

    polynomial_hash (int _N, std::array<x_t, EvaluationPoints> _data) : N(_N), data(_data) {}

    friend polynomial_hash concatenate(polynomial_hash a, polynomial_hash b) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = a.data[i] * pow(i, b.N) + b.data[i];
        return { a.N + b.N, res };
    }

    bool operator == (const polynomial_hash &o) const {
        return N == o.N && data == o.data;
    }

    bool operator < (const polynomial_hash &o) const {
        return N != o.N ? N < o.N : data < o.data;
    }

    friend std::ostream& operator << (std::ostream& o, const polynomial_hash& h) {
        o << h.N;
        for (int i = 0; i < EvaluationPoints; i++)
            o << " " << h.data[i];
        return o;
    }

    template<typename InputIterator>
    static std::vector<polynomial_hash> get_prefixes(InputIterator begin, InputIterator end) {
        std::vector<polynomial_hash> res = { polynomial_hash{} };
        for (InputIterator iter = begin; iter != end; iter = next(iter))
            res.push_back(concatenate(res.back(), polynomial_hash(x_t(*iter))));
        return res;
    }

    static polynomial_hash get_substring(const std::vector<polynomial_hash> &prefixes, int first, int last) {
        std::array<x_t, EvaluationPoints> res;
        for (int i = 0; i < EvaluationPoints; i++)
            res[i] = prefixes[last].data[i] - pow(i, last - first) * prefixes[first].data[i];
        return { last - first, res };
    }
};

#include <iostream>
#include <algorithm>
using namespace std;

// {{{ strings/polynomial_hash.cpp }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    array<bool, 26> good;
    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        good[i] = c == '1';
    }

    int K;
    cin >> K;

    using H = polynomial_hash<modnum<int(1e9 + 7)>, 5, 256>;

    vector<H> s_prefixes = H::get_prefixes(s.begin(), s.end());

    vector<H> good_substrings;

    for (int head = 0; head < int(s.size()); head++) {
        int bad = 0;
        for (int tail = head; tail < int(s.size()); tail++) {
            if (!good[s[tail] - 'a'])
                bad++;

            if (bad > K)
                break;

            good_substrings.push_back(H::get_substring(s_prefixes, head, tail + 1));
        }
    }

    sort(good_substrings.begin(), good_substrings.end());

    cout << unique(good_substrings.begin(), good_substrings.end()) - good_substrings.begin() << endl;
}