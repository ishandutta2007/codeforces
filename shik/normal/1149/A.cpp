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

// sieve {{{
template<class F> void sieve(int n, F cb) {
    const int sieve_span = 1 << 19;
    const int sieve_words = sieve_span / 64;
    const int wheel_size = 3 * 5 * 7 * 11 * 13;

    static uint32_t sieve[sieve_words];
    static uint32_t wheel[wheel_size];

    auto two = [](int x) { return uint32_t(1) << x; };
    auto mark = [&](uint32_t* s, int i) { s[i >> 5] |= two(i & 31); };
    auto is_empty = [&](uint32_t* s, int i) { return (s[i >> 5] & two(i & 31)) == 0; };

    int u = sqrt(n) + 1;
    for (int i = 0; i <= u / 64; i++) sieve[i] = 0;
    for (int i = 3; i * i <= u; i += 2) {
        if (is_empty(sieve, i >> 1)) {
            for (int j = i * i / 2; j <= u / 2; j += i) mark(sieve, j);
        }
    }

    vector<int> primes;
    for (int i = 17; i <= u; i += 2) {
        if (is_empty(sieve, i / 2)) primes.push_back(i);
    }

    memset(wheel, 0, sizeof(wheel));
    for (int p : {3, 5, 7, 11, 13}) {
        for (int i = p / 2; i < wheel_size * 32; i += p) mark(wheel, i);
    }

    auto update_sieve = [&](int base) {
        int o = base % wheel_size;
        o = (o + ((o * 41) & 63) * wheel_size) >> 6;
        for (int i = 0, k; i < sieve_words; i += k, o = 0) {
            k = min(wheel_size - o, sieve_words - i);
            memcpy(sieve + i, wheel + o, sizeof(wheel[0]) * k);
        }
        if (base == 0) {
            sieve[0] |= 1;                     // 1 is not prime
            sieve[0] &= ~uint32_t(0b1101110);  // 3, 5, 7, 11, 13 are primes
            if (n >= 2) cb(2);
        }
        for (int p : primes) {
            int i = p * p;
            if (i >= base + sieve_span) break;
            if (i > base) {
                i = (i - base) / 2;
            } else {
                i = p - base % p;
                if (i % 2 == 0) i += p;
                i >>= 1;
            }
            for (; i < sieve_span / 2; i += p) mark(sieve, i);
        }
        for (int i = 0; i < min(sieve_span, n - base + 1) / 2; i++) {
            if (is_empty(sieve, i)) cb(base + i * 2 + 1);
        }
    };

    for (int i = 0; i < n; i += sieve_span) update_sieve(i);
}
// }}}

const int L=4e5+10;
bool isp[L];
void main() {
    sieve(L-1,[](int p) { isp[p]=1; });
    int n,c1=0,c2=0;
    R(n);
    REP(i,n) {
        int x;
        R(x);
        if ( x==1 ) c1++;
        if ( x==2 ) c2++;
    }
    int ans=0,t=0;
    VI sol;
    if ( c2>0 ) {
        t+=2;
        ans+=isp[t];
        c2--;
        sol.PB(2);
    }
    if ( c1>0 ) {
        t++;
        ans+=isp[t];
        c1--;
        sol.PB(1);
    }
    while ( c2>0 ) {
        t+=2;
        ans+=isp[t];
        c2--;
        sol.PB(2);
    }
    while ( c1>0 ) {
        t+=1;
        ans+=isp[t];
        c1--;
        sol.PB(1);
    }
    W(sol);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}