#if !defined(SHIK) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx2")
#include <stdio.h>
#endif

// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

struct SplitMix64 {
    uint64_t s;
    SplitMix64(uint64_t _s = 0) : s(_s) {}
    uint64_t operator()() {
        uint64_t z = (s += 0x9E3779B97F4A7C15);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EB;
        return z ^ (z >> 31);
    }
} rnd;

uint64_t mod_mul64(uint64_t a, uint64_t b, uint64_t m) {
    static_assert(sizeof(long double) >= 10, "long double is too short");
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    uint64_t q = (long double)a * b / m;
    int64_t r = (int64_t)(a * b - q * m) % (int64_t)m;
    return r < 0 ? r + m : r;
}

uint64_t mod_exp64(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = 1;
    while (b) {
        if (b & 1) r = mod_mul64(r, a, m);
        a = mod_mul64(a, a, m);
        b >>= 1;
    }
    return r;
}

bool miller_rabin(uint64_t n, uint64_t a) {
    if (n % a == 0) return false; 
    uint64_t d = n - 1;
    int s = 0;
    for (; d % 2 == 0; d /= 2) s++;
    auto x = mod_exp64(a, d, n);
    if (x == 1) return true;
    for (int i = 1; i < s && x != n - 1; i++) x = mod_mul64(x, x, n);
    return x == n - 1;
}

bool is_prime(uint64_t n) {
    for (uint64_t i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}) {
        if (n == i) return true;
        if (n % i == 0) return false;
    }
    if (n < 53 * 53) return n > 1;
    if (n < 4759123141) {
        for (uint64_t i : {2, 7, 61}) if (!miller_rabin(n, i)) return false;
    } else {
        for (uint64_t i : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) if (!miller_rabin(n, i)) return false;
    }
    return true;
}

int64_t gcd(int64_t u, int64_t v) {
#define ctz __builtin_ctzll
    if (!u || !v) return u + v;
    // u = abs(u); v = abs(v);
    int shift = ctz(u | v);
    u >>= ctz(u);
    while (v != 0) {
        v >>= ctz(v);
        if (u > v) swap(u, v);
        v -= u;
    }
    return u << shift;
#undef ctz
}

int64_t pollard_rho(int64_t n) {
    auto f = [n](int64_t x) {
        x = mod_mul64(x, x, n);
        return ++x == n ? 0 : x;
    };
    while (true) {
        int64_t x = rnd() % (n - 2) + 2, y = f(x), step = 0, lim = 1, m = 1, d[16];
        for (; x != y; y = f(y)) {
            d[step++ % 16] = abs(x - y);
            m = mod_mul64(m, abs(x - y), n);
            if (step % 16 == 0 && gcd(n, m) != 1) {
                for (auto i : d) {
                    auto g = gcd(n, i);
                    if (g != 1) return g;
                }
            }
            if (step == lim) {
                lim *= 2;
                x = y;
            }
        }
    }
}

template<int N>
struct Sieve {
    int pf[N];
    vector<int> primes;
    Sieve() {
        for (int i = 2; i < N; i++) {
            if (!pf[i]) {
                pf[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                int x = i * p;
                if (x >= N) break;
                pf[x] = p;
                if (i % p == 0) break;
            }
        }
    }
};

vector<int64_t> factor(int64_t n) {
    const int N = 100000;
    static Sieve<N> sieve;
    if (n == 1) return {};
    vector<int64_t> f;
    for (int i = 0; i < 100 && n != 1; i++) {
        for (int p = sieve.primes[i]; n % p == 0; n /= p) f.push_back(p);
    }
    if (n > 1) f.push_back(n);
    for (size_t i = f.size() - 1; i < f.size(); i++) {
        if (is_prime(f[i])) continue;
        auto d = f[i] < N ? sieve.pf[f[i]] : pollard_rho(f[i]);
        f.push_back(d);
        f[i] /= d;
        i--;
    }
    sort(f.begin(), f.end());
    return f;
}

// PRNG {{{
template<class T, T x1, T x2, T x3, int y1, int y2, int y3>
struct PRNG {
    using S = typename make_signed<T>::type;
    T s;
    PRNG() {
#ifdef SHIK
        s = 0;
#else
        s = chrono::high_resolution_clock::now().time_since_epoch().count() & numeric_limits<T>::max();
#endif
    }
    PRNG(T _s) : s(_s) {}
    T next() {
        T z = (s += x1);
        z = (z ^ (z >> y1)) * x2;
        z = (z ^ (z >> y2)) * x3;
        return z ^ (z >> y3);
    }
    T next(T n) { return next() % n; }
    S next(S l, S r) { return l + next(r - l + 1); }
    T operator()() { return next(); }
    T operator()(T n) { return next(n); }
    S operator()(S l, S r) { return next(l, r); }
    static T gen(T s) { return PRNG(s)(); }
    template<class U>
    void shuffle(U first, U last) {
        size_t n = last - first;
        for (size_t i = 0; i < n; i++) swap(first[i], first[next(i + 1)]);
    }
};

using R32 = PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16>;
R32 r32;

using R64 = PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31>;
R64 r64;
// }}}

const int N=2e5+10;
int n;
LL a[N];
void main() {
    R(n);
    REP(i,n) R(a[i]);
    r32.shuffle(a,a+n);
    int ans=0;
    REP(i,n) ans+=a[i]%2;
    int m=min(n,2000);
    vector<LL> f;
    REP(i,m) {
        REP1(j,-1,+1) if( a[i]+j>1 ) {
            auto fac=factor(a[i]+j);
            f.insert(f.end(),ALL(fac));
        }
    }
    sort_uniq(f);
    dump(SZ(f));
    for ( LL p:f ) {
        int s=0;
        REP(i,n) {
            LL r=a[i]%p;
            if ( p-r<r || a[i]<p ) s+=p-r;
            else s+=r;
            if ( s>ans ) break;
            // dump(p,i,a[i],s);
        }
        // dump(p,s);
        chkmin(ans,s);
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}