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

const int N=3e5+10;
const int L=3000;
int build( int x, int y, int z, int tbl[3][L] ) {
    REP(j,L) REP(i,3) {
        if ( j==0 ) {
            tbl[i][j]=0;
            continue;
        }
        bool v[4]={};
        v[tbl[0][max(0,j-x)]]=1;
        if ( i!=1 ) v[tbl[1][max(0,j-y)]]=1;
        if ( i!=2 ) v[tbl[2][max(0,j-z)]]=1;
        int t=0;
        while ( v[t] ) t++;
        tbl[i][j]=t;
    }
    REP1(d,1,L/4) {
        bool ok=1;
        REP(i,3) REP1(j,L/4,L-d-1) if ( tbl[i][j]!=tbl[i][j+d] ) ok=0;
        if ( ok ) {
            // dump(x,y,z,d);
            return d;
        }
    }
    dump(x,y,z);
    REP(i,3) REP(j,10) dump(i,j,tbl[i][j]);
    assert(0);
    return -1;
}

int nc[6][6][6],tbl[6][6][6][3][L];
LL a[N];
void main() {
    REP1(x,1,5) REP1(y,1,5) REP1(z,1,5) {
        nc[x][y][z]=build(x,y,z,tbl[x][y][z]);
    }
    int t;
    R(t);
    while ( t-- ) {
        int n,x,y,z;
        R(n,x,y,z);
        REP(i,n) R(a[i]);
        int d=nc[x][y][z];
        auto f=[&]( int i, LL j ) {
            if ( j>L ) {
                j-=(j-L+d-1)/d*d+d;
            }
            return tbl[x][y][z][i][j];
        };
        int s=0;
        REP(i,n) s^=f(0,a[i]);
        // dump(s);
        int ans=0;
        REP(i,n) {
            int g=s^f(0,a[i]);
            if ( g==f(0,max(0LL,a[i]-x)) ) ans++;
            if ( g==f(1,max(0LL,a[i]-y)) ) ans++;
            if ( g==f(2,max(0LL,a[i]-z)) ) ans++;
        }
        W(ans);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}