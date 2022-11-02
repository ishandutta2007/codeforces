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

const int N=2e5+10;
int n,m,a[N],t[N],ord[N];

bool cmp_t( int x, int y ) {
    return t[x]<t[y];
}

bool chk( int k, bool out=0 ) {
    int st=0;
    VI sol;
    REP1(ii,1,n) {
        int i=ord[ii];
        if ( a[i]<k ) continue;
        st+=t[i];
        if ( st>m ) break;
        sol.PB(i);
        if ( SZ(sol)==k ) {
            if ( out ) W(sol);
            return 1;
        }
    }
    assert(!out);
    return 0;
}

void main() {
    R(n,m);
    REP1(i,1,n) R(a[i],t[i]);
    REP1(i,1,n) ord[i]=i;
    sort(ord+1,ord+n+1,cmp_t);
    int l=0,r=n;
    while ( l!=r ) {
        int mid=(l+r+1)/2;
        if ( chk(mid) ) l=mid;
        else r=mid-1;
    }
    W(l);
    W(l);
    if ( l==0 ) W("");
    else chk(l,1);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}