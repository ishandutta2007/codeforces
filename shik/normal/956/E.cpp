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

const int N=10010;

int n,l,r;
VI b0,b1;
void input() {
    R(n,l,r);
    static int a[N],b[N];
    REP(i,n) R(a[i]);
    REP(i,n) R(b[i]);
    REP(i,n) {
        if ( b[i]==0 ) b0.PB(a[i]);
        else b1.PB(a[i]);
    }
}

int n0,n1;
bitset<N> dp,dq;
bool chk( int m ) {
    if ( m==0 ) return 1;
    dp.reset();
    dq.reset();
    dp[0]=1;
    for ( int i:b0 ) dp|=dp<<i;
    REP(i,n1-m+1) {
        int x=b1[n1-i-1];
        dq=dq|(dq<<x)|dp;
        dp|=dp<<x;
    }
    int x=l;
    while ( x<=r && !dq[x] ) x++;
    if ( x>r ) return 0;
    dump(m,x);
    REP(i,m-1) {
        x+=b1[i];
        dump(i,x,r);
        if ( x>r ) return 0;
    }
    dump(m,"OK");
    return 1;
}

void main() {
    input();
    sort(ALL(b0));
    sort(ALL(b1));
    n0=SZ(b0);
    n1=SZ(b1);
    int ll=0,rr=SZ(b1);
    while ( ll!=rr ) {
        int m=(ll+rr+1)/2;
        if ( chk(m) ) ll=m;
        else rr=m-1;
    }
    W(ll);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}