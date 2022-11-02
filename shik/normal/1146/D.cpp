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

const int N=1e6;

int m,a,b,dp[N];
LL f[N];
void main() {
    R(m,a,b);
    REP(i,N) dp[i]=INT_MAX;
    dp[0]=0;
    MinHeap<PII> h;
    auto push=[&]( int p ) { h.push({dp[p],p}); };
    h.push({0,0});
    while ( !h.empty() ) {
        int d=h.top().first;
        int p=h.top().second;
        h.pop();
        if ( dp[p]!=d ) continue;
        if ( p+a<N && chkmin(dp[p+a],max(d,p+a)) ) push(p+a);
        if ( p-b>=0 && chkmin(dp[p-b],max(d,p-b)) ) push(p-b);
    }
    REP(i,N) if ( dp[i]!=INT_MAX ) f[dp[i]]++;
    REP(i,N-1) f[i+1]+=f[i];
    if ( m<N ) {
        LL ans=0;
        REP1(i,0,m) ans+=f[i];
        W(ans);
        return;
    }
    LL ans=0;
    REP(i,N) ans+=f[i];
    LL g=__gcd((uint32_t)a,(uint32_t)b);
    LL lo=(N-1)/g*g+g;
    LL hi=m/g*g;
    if ( lo>=hi ) {
        LL x=f[N-1];
        REP1(j,N,m) {
            if ( j%g==0 ) x++;
            ans+=x;
        }
        W(ans);
        return;
    }
    LL x=f[N-1];
    ans+=(lo-N)*x;
    LL ng=(hi-lo)/g;
    LL sg=(x+1+x+ng)*ng/2;
    x+=ng;
    ans+=sg*g;
    x++;
    ans+=(m-hi+1)*x;
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}