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

// {{{ Bitwise
#define F(name) \
    template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> \
    constexpr int name(T x) { return sizeof(T) <= sizeof(int) ? __builtin_ ## name(x) : __builtin_ ## name ## ll(x); }

F(clz) F(ctz) F(ffs) F(parity) F(popcount)

#undef F
#define popcnt popcount

template<class T>
T has_bit(T x, int i) { return (x >> i) & 1; }

template<class T>
constexpr int lg2(T x) { return sizeof(T) * CHAR_BIT - 1 - clz(x); }
// }}}
// {{{ gcd
template<class T>
T gcd(T u, T v) {
    if (!u || !v) return u + v;
    // u = abs(u); v = abs(v);
    int shift = ctz(u | v);
    u >>= ctz(u);
    while (v) {
        v >>= ctz(v);
        if (u > v) swap(u, v);
        v -= u;
    }
    return u << shift;
}
// }}}
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

const int N=500010;
int n,m;
LL c[N];
VI e[N];
uint64_t h[N];
uint64_t z[N];

void solve() {
    REP1(i,1,n) h[i]=r64();
    REP1(i,1,n) z[i]=0;
    REP1(i,1,n) for ( int j:e[i] ) z[i]^=h[j];
    map<uint64_t,LL> mp;
    REP1(i,1,n) if ( z[i]>0 ) mp[z[i]]+=c[i];
    LL ans=0;
    for ( auto [_,s]:mp ) {
        ans=gcd(ans,s);
    }
    W(ans);
}

void main() {
    int t;
    R(t);
    while ( t-- ) {
        R(n,m);
        REP1(i,1,n) R(c[i]);
        REP1(i,1,n) e[i].clear();
        REP(i,m) {
            int a,b;
            R(a,b);
            e[b].PB(a);
        }
        solve();
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}