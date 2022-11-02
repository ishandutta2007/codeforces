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

const int N=5010;

auto solve( int n, mint a[] ) {
    vector<mint> ans(2*n-2+1);
    if ( n==1 ) return ans;
    auto v=solve(n-1,a+1);
    vector<mint> sa(n);
    sa[1]=1;
    REP1(i,2,n-1) sa[i]=sa[i-1]*a[i];
    REP1(i,1,n-1) ans[i]+=a[1]*sa[i];
    // dump(ans);
    mint k=a[1]*(a[1]-1);
    vector<mint> b(SZ(ans));
    REP1(i,1,n-1) {
        REP1(j,i,n-1) {
            mint now=sa[i]*sa[j];
            if ( i==j ) now/=2;
            b[i+j]+=now;
        }
    }
    REP1(i,1,2*n-2) ans[i]+=b[i]*k;
    // dump(ans);
    REP1(i,1,2*n-4) ans[i]+=a[1]*v[i];
    // dump(n,ans);
    return ans;
}

int n;
mint a[N];

mint sa[N],b[2*N];
mint _dp[2][2*N],*dp=_dp[0],*dq=_dp[1];
void shik() {
    for ( int m=2; m<=n; m++ ) {
        swap(dp,dq);
        REP1(i,1,2*m-2) dp[i]=0;
        mint d=a[n-m+1];
        mint k=d*(d-1);
        // int x=0;
        // sa[1]=1;
        // REP1(i,2,m-1) sa[i]=sa[i-1]*a[n-m+i];
        // REP1(i,1,m-1) dp[i]+=d*sa[i];
        int x=n-m;
        sa[x+1]=1;
        REP1(i,2,m-1) sa[x+i]*=a[x+2];
        REP1(i,1,m-1) dp[i]+=d*sa[x+i];
        // REP1(i,1,2*m-2) b[x+x+i]=0;
        // REP1(i,1,m-1) REP1(j,i,m-1) {
        //     mint now=sa[x+i]*sa[x+j];
        //     if ( i==j ) now/=2;
        //     b[x+x+i+j]+=now;
        // }
        REP1(i,1,2*m-1) b[x+x+i]*=a[x+2]*a[x+2];
        REP1(i,1,1) REP1(j,i,m-1) {
            mint now=sa[x+i]*sa[x+j];
            if ( i==j ) now/=2;
            b[x+x+i+j]+=now;
        }
        REP1(i,1,2*m-2) dp[i]+=b[x+x+i]*k;
        REP1(i,1,2*m-4) dp[i]+=d*dq[i];
    }
    dump(dp[n],dp[n/2]);
    W(vector<mint>(dp+1,dp+n+n-1));
}

void main() {
    R(n);
    REP1(i,1,n-1) R(a[i].x);
    shik();
    // auto ans=solve(n,a);
    // dump(ans[n],ans[n/2]);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}