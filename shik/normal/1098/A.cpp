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

const int N=1e5+10;

int n,fa[N];
LL s[N],a[N];
VI e[N];

void gg() {
    W(-1);
    exit(0);
}

void go( int p, int lv ) {
    if ( (lv%2==0)!=(s[p]==-1) ) gg();
    if ( s[p]==-1 ) {
        s[p]=s[fa[p]];
        LL mi=LLONG_MAX;
        for ( int i:e[p] ) {
            if ( s[i]==-1 ) gg();
            chkmin(mi,s[i]);
        }
        if ( mi!=LLONG_MAX ) s[p]=mi;
    }
    for ( int i:e[p] ) go(i,lv+1);
}

void main() {
    R(n);
    REP1(i,2,n) R(fa[i]);
    REP1(i,2,n) e[fa[i]].PB(i);
    REP1(i,1,n) R(s[i]);
    go(1,1);
    REP1(i,1,n) a[i]=s[i]-s[fa[i]];
    REP1(i,1,n) if ( a[i]<0 ) gg();
    dump(VI(a+1,a+n+1));
    REP1(i,1,n) if ( s[i]!=s[fa[i]]+a[i] ) gg();
    LL ans=0;
    REP1(i,1,n) ans+=a[i];
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}