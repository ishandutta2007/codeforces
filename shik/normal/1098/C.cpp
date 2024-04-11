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
int n;
LL s;

LL get_min( LL b ) {
    LL rem=n-1,k=1,t=1;
    for ( int i=2; rem>0; i++ ) {
        k*=b;
        LL c=min(rem,k);
        rem-=c;
        t+=c*i;
    }
    return t;
}

LL d[N];
bool solve() {
    if ( n*(n+1LL)/2<s ) return 0;
    if ( 1+(n-1)*2>s ) return 0;
    LL b=1;
    while ( b<n && get_min(b)>s ) b++;
    assert(b<n);
    d[1]=1;
    LL rem=n-1;
    s--;
    for ( int i=2; rem>0; i++ ) {
        d[i]=min(d[i-1]*b,rem);
        rem-=d[i];
        s-=i*d[i];
    }
    assert(s>=0);
    auto chk1=[&]( int x ) {
        return d[x-1]*b>=d[x] && d[x]*b>=d[x+1];
    };
    auto chk=[&]( int x, int y ) {
        assert(chk1(x) && chk1(y));
        d[x]--; d[y]++;
        bool ret=chk1(x) && chk1(y);
        d[x]++; d[y]--;
        return ret;
    };
    // dump(s);
    while ( s>0 ) {
        int h=1;
        while ( d[h] ) h++;
        auto move=[&]( int x, int y ) {
            // dump(x,y);
            d[x]--;
            d[y]++;
            if ( y==h ) h++;
            assert(chk1(x) && chk1(y));
            s-=y-x;
        };
        for ( int i=2; i<h; i++ ) {
            // dump(i,d[i]);
            while ( s>=h-i && chk(i,h) ) move(i,h);
            while ( s>=1 && chk(i,i+1) ) move(i,i+1);
        }
    }
    assert(s==0);
    return 1;
}

VI v[N];
int sol[N];
void main() {
    R(n,s);
    if ( solve() ) {
        W("Yes");
        // dump(vector<LL>(d+1,d+n+1));
        int id=0;
        REP1(i,1,n) REP(j,d[i]) v[i].PB(++id);
        id=1;
        REP1(i,2,n) REP(j,d[i]) sol[++id]=v[i-1][j%SZ(v[i-1])];
        W(VI(sol+2,sol+n+1));
    } else {
        W("No");
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}