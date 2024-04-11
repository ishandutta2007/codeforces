#ifndef YCM
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,variable-expansion-in-unroller")
#endif

// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
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

// PRNG {{{
template<class T, T x1, T x2, T x3, int y1, int y2, int y3>
struct PRNG {
    using S = typename make_signed<T>::type;
    T s;
    PRNG(T _s = 0) : s(_s) {}
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
// {{{ ModInt
template<int _MOD>
struct ModInt {
    static const auto MOD = _MOD;
    template<class T> using integral_only = typename enable_if<is_integral<T>::value>::type;

    int x;
    constexpr ModInt() : x() {}
    template<class T, integral_only<T>* = nullptr>
    ModInt(T _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt operator-() const { return {x == 0 ? 0 : MOD-x}; }
    ModInt& operator+=(ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (long long)x * rhs.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() const {
        // should work for non-prime MOD if gcd(x, MOD) = 1
        int a = x, b = MOD, u = 1, v = 0;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        return u;
    }
    template<class T, integral_only<T>* = nullptr>
    ModInt pow(T e) {
        ModInt r = 1, p = *this;
        while (e) {
            if (e & 1) r *= p;
            p *= p;
            e >>= 1;
        }
        return r;
    }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    bool operator<(ModInt rhs) const { return x < rhs.x; }
    bool operator<=(ModInt rhs) const { return x <= rhs.x; }
    bool operator>(ModInt rhs) const { return x > rhs.x; }
    bool operator>=(ModInt rhs) const { return x >= rhs.x; }
    friend string to_string(ModInt i) { return to_string(i.x); }
    friend ostream& operator<<(ostream &os, ModInt i) { return os << i.x; }
};
// }}}

const int MOD=998244353;
using mint=ModInt<MOD>;

const int N=4000;
const int M=75;

mint inv[N],fac[N],ifac[N];
void predo() {
    inv[1]=1;
    REP1(i,2,N-1) inv[i]=inv[MOD%i]*(MOD-MOD/i);
    fac[0]=1;
    REP1(i,1,N-1) fac[i]=fac[i-1]*i;
    ifac[0]=1;
    REP1(i,1,N-1) ifac[i]=ifac[i-1]*inv[i];
}

mint F( int n, int m ) {
    return fac[n+m]/fac[n]/fac[m];
}

int n1,n2,m,e1[N][2],e2[N][2],deg1[N],deg2[N];

void read_tree( int n, int e[][2], int deg[] ) {
#if 0
    REP(i,n-1) {
        int a=i+1;
        int b=r32(i+1);
        e[i][0]=a;
        e[i][1]=b;
    }
#else
    REP(i,n-1) {
        int a,b;
        R(a,b);
        a--; b--;
        e[i][0]=a;
        e[i][1]=b;
    }
#endif
    REP(i,n-1) {
        deg[e[i][0]]++;
        deg[e[i][1]]++;
    }
}

void build_cc( int n, int e[][2], int deg[], mint cc[] ) {
    static mint _dp[2][N],c[N][M];
    auto dp=_dp[0],dq=_dp[1];
    REP(i,n) {
        if ( n>=3 && deg[i]==1 ) continue;
        REP(j,n) dp[j]=0;
        dp[i]=1;
        c[i][0]=1;
        REP1(j,1,m) {
            REP(k,n) dq[k]=0;
            REP(k,n-1) {
                int a=e[k][0],b=e[k][1];
                dq[a]+=dp[b];
                dq[b]+=dp[a];
            }
            c[i][j]=dq[i];
            swap(dp,dq);
        }
    }
    REP(i,n) if ( n>=3 && deg[i]==1 ) {
        int x=-1;
        REP(j,n-1) {
            if ( e[j][0]==i ) x=e[j][1];
            if ( e[j][1]==i ) x=e[j][0];
        }
        assert(x!=-1);
        c[i][0]=1;
        REP1(j,2,m) c[i][j]=c[x][j-2];
    }
    REP(i,n) REP1(j,0,m) cc[j]+=c[i][j];
}

mint cc1[M],cc2[M];

void main() {
    predo();
    R(n1,n2,m);
    if ( m%2!=0 ) {
        W(0);
        return;
    }
    read_tree(n1,e1,deg1);
    read_tree(n2,e2,deg2);
    build_cc(n1,e1,deg1,cc1);
    build_cc(n2,e2,deg2,cc2);
    mint ans=0;
    REP1(i,0,m) {
        mint now=cc1[i]*cc2[m-i]*F(i,m-i);
        // dump(i,cc1[i],cc2[m-i],now);
        ans+=now;
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}