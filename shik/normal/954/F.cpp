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

const int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

struct M {
    mint x[3][3];
    const mint* operator[]( int i ) const { return x[i]; }
    mint* operator[]( int i ) { return x[i]; }
};

M operator*( const M &a, const M &b ) {
    M c;
    REP(i,3) REP(j,3) {
        mint s=0;
        REP(k,3) s+=a[i][k]*b[k][j];
        c[i][j]=s;
    }
    return c;
}

typedef array<mint,3> V;
V operator*( const M &a, const V &b ) {
    V c;
    REP(i,3) {
        mint s=0;
        REP(j,3) s+=a[i][j]*b[j];
        c[i]=s;
    }
    return c;
}

M tr[8]={
    {{{1,1,0},{1,1,1},{0,1,1}}},
};

M I={{{1,0,0},{0,1,0},{0,0,1}}};

V go( V v, int o, LL n ) {
    // (tr[o]^n)*v
    M r=I,t=tr[o];
    while ( n ) {
        if ( n&1 ) r=r*t;
        t=t*t;
        n>>=1;
    }
    return r*v;
}

const int N=10010;

struct P {
    int x;
    LL l,r;
} p[N];

vector<LL> ls;

int n,sl[N],sr[N];
LL m;

bool cmp_l( int a, int b ) { return p[a].l<p[b].l; }
bool cmp_r( int a, int b ) { return p[a].r<p[b].r; }

void main() {
    REP1(i,1,7) {
        tr[i]=tr[0];
        REP(j,3) if ( has_bit(i,j) ) REP(k,3) tr[i][k][j]=0;
    }
    R(n,m);
    REP(i,n) R(p[i].x,p[i].l,p[i].r);
    REP(i,n) p[i].x--;
    REP(i,n) sl[i]=sr[i]=i;
    sort(sl,sl+n,cmp_l);
    sort(sr,sr+n,cmp_r);
    LL y=1;
    int co[3]={},li=0,ri=0;
    V v{0,1,0};
    while ( li<n || ri<n ) {
        LL ny=LLONG_MAX;
        if ( li<n ) chkmin(ny,p[sl[li]].l);
        if ( ri<n ) chkmin(ny,p[sr[ri]].r+1);
        dump(y,v,li,ri,ny);
        int o=0;
        REP(i,3) if ( co[i] ) o|=1<<i;
        v=go(v,o,ny-y);
        while ( li<n && p[sl[li]].l==ny ) co[p[sl[li++]].x]++;
        while ( ri<n && p[sr[ri]].r+1==ny ) co[p[sr[ri++]].x]--;
        y=ny;
    }
    dump(v);
    v=go(v,0,m-y);
    dump(v);
    W(v[1]);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}