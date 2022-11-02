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

const int N=2e5+10;
int n,fa[N],deg[N];
VI e[N];

bool dp[N][2];
void go( int p ) {
    for ( int i:e[p] ) go(i);
    int c0=0,c1=0,c01=0,gg=0;
    for ( int i:e[p] ) {
        if ( dp[i][0] && dp[i][1] ) c01++;
        else if ( dp[i][0] ) c0++;
        else if ( dp[i][1] ) c1++;
        else gg++;
    }
    if ( gg ) {
        // nop
    } else if ( c01 ) {
        dp[p][0]=dp[p][1]=1;
    } else {
        int d=SZ(e[p]);
        d-=c1;
        dp[p][d%2]=1;
    }
    // dump(p,dp[p][0],dp[p][1]);
}

VI sol;
void poke( int p ) {
    // dump(p);
    assert(deg[p]%2==0);
    sol.PB(p);
    deg[fa[p]]--;
    for ( int i:e[p] ) deg[i]--;
}

bool vis[N];
void trace( int p, int q ) {
    // dump(p,q);
    assert(!vis[p]);
    assert(dp[p][q]);
    vis[p]=1;
    for ( int i:e[p] ) if ( !dp[i][0] && dp[i][1] ) trace(i,1);
    if ( deg[p]%2==1 ) {
        bool found=0;
        for ( int i:e[p] ) if ( dp[i][0] && dp[i][1] ) {
            trace(i,1);
            found=1;
            break;
        }
        assert(found);
        assert(deg[p]%2==0);
    }
    poke(p);
    for ( int i:e[p] ) if ( !vis[i] ) trace(i,0);
}

void main() {
    R(n);
    REP1(i,1,n) R(fa[i]);
    REP1(i,1,n) if ( fa[i]!=0 ) {
        deg[i]++;
        deg[fa[i]]++;
    }
    REP1(i,1,n) e[fa[i]].PB(i);
    int rt=e[0][0];
    go(rt);
    if ( !dp[rt][0] ) {
        W("NO");
    } else {
        trace(rt,0);
        W("YES");
        for ( int i:sol ) W(i);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}