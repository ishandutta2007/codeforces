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

const int N=1e7+10;

int p_tbl[N],mu[N],phi[N];
VI primes;
void sieve() {
    mu[1]=phi[1]=p_tbl[1]=1;
    for ( int i=2; i<N; i++ ) {
        if ( !p_tbl[i] ) {
            primes.push_back(i);
            mu[i]=-1;
            phi[i]=i-1;
            p_tbl[i]=i;
        }
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=N ) break;
            p_tbl[x]=p;
            mu[x]=-mu[i];
            if ( i%p==0 ) {
                mu[x]=0;
                phi[x]=phi[i]*p;
                break;
            } else {
                phi[x]=phi[i]*(p-1);
            }
        }
    }
    // REP1(i,1,50) dump(i,phi[i]);
}

int n;

int dis( int a, int b ) {
    if ( a==1 || b==1 ) return 0;
    assert(a!=b);
    int p=p_tbl[a],q=p_tbl[b];
    bool f1=(gcd(a,b)>1);
    bool f2=(1LL*p*q<=n);
    bool f3=(2*max(p,q)<=n);
    assert(f1<=f2 && f2<=f3);
    if ( f1 ) return 1;
    if ( f2 ) return 2;
    if ( f3 ) return 3;
    return 0;
}

LL solve_1() {
    LL ans=0;
    REP1(i,2,n) ans+=i-phi[i]-1;
    dump(ans);
    return ans;
}

int cp[N],sp[N];
LL solve_2() {
    LL ans=0;
    REP1(i,2,n) cp[p_tbl[i]]++;
    REP1(i,2,n) sp[i]=sp[i-1]+cp[i];
    for ( int i=2,j=n; i<=n; i++ ) {
        if ( cp[i]==0 ) continue;
        while ( i*j>n ) j--;
        ans+=1LL*cp[i]*sp[j];
    }
    REP1(i,2,n) {
        if ( i*i<=n ) ans-=cp[i];
        else break;
    }
    assert(ans%2==0);
    ans/=2;
    dump(ans);
    return ans;
}

LL solve_3() {
    LL ans=0;
    REP1(i,2,n) if ( 2*p_tbl[i]<=n ) ans++;
    ans=ans*(ans-1)/2;
    dump(ans);
    return ans;
}

LL solve() {
    LL ans=0;
    ans+=3*solve_3();
    ans-=solve_2();
    ans-=solve_1();
    return ans;
}

LL slow() {
    LL ans=0;
    REP1(i,2,n) REP1(j,i+1,n) {
        int now=dis(i,j);
        // dump(i,j,now);
        ans+=now;
    }
    return ans;
}

void main() {
    sieve();
    R(n);
    auto ans=solve();
    W(ans);
#ifdef SHIK
    if ( n<=1000 ) {
        LL slow_ans=slow();
        dump(slow_ans);
    }
#endif
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}