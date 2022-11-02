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

const int N=1010;

int ask( int a, int b ) {
    W("?",a,b);
    fflush(stdout);
    int c;
    R(c);
    return c;
}

void out( int ans ) {
    W("!",ans);
    fflush(stdout);
}

int n,fa[N];
VI e[N],lf;

void go( int p, int f ) {
    if ( SZ(e[p])==1 ) lf.PB(p);
    for ( int i:e[p] ) if ( i!=f ) go(i,p);
}

bool mark( int p, int q, int f ) {
    if ( p==q ) return 1;
    for ( int i:e[p] ) if ( i!=f && mark(i,q,p) ) {
        assert(fa[i]==0 || fa[i]==p);
        fa[i]=p;
        return 1;
    }
    return 0;
}

int find( int x ) {
    while ( fa[x]!=0 ) x=fa[x];
    return x;
}

void main() {
    R(n);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    if ( n==2 ) {
        int ans=ask(1,2);
        out(ans);
        return;
    }
    int p=0;
    REP1(i,1,n) if ( SZ(e[i])>1 ) p=i;
    go(p,0);
    int nl=SZ(lf);
    int d=nl/2;
    REP(i,nl-d) {
        int a=lf[i];
        int b=lf[i+d];
        int c=ask(a,b);
        mark(c,a,0);
        mark(c,b,0);
    }
    int rt=find(1);
    REP1(i,1,n) assert(find(i)==rt);
    out(rt);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}