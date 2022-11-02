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
int n,x[N],cl[N],cr[N];
LL t,a[N],lo[N],hi[N];
void main() {
    R(n,t);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) R(x[i]);
    REP1(i,1,n) {
        lo[i]=0;
        hi[i]=LLONG_MAX;
    }
    int l0=0,r0=n+1;
    REP1(i,1,n) {
        chkmax(lo[x[i]],a[i]+t);
        if ( i<=x[i] ) {
            chkmax(l0,i-1);
            chkmin(r0,x[i]+1);
            if ( x[i]<n ) chkmin(hi[x[i]],a[x[i]+1]+t-1);
            cl[i]++;
            cl[x[i]]--;
        } else {
            chkmax(l0,x[i]-1);
            chkmin(r0,i+1);
            chkmin(hi[x[i]],a[x[i]]+t-1);
            cr[x[i]+1]++;
            cr[i+1]--;
        }
    }
    REP1(i,1,l0) chkmax(lo[i],a[i]+t);
    REP1(i,r0,n) chkmax(lo[i],a[i]+t);
    {
        int c=0;
        REP1(i,1,n) {
            c+=cl[i];
            assert(c>=0);
            if ( c>0 ) chkmax(lo[i],a[i+1]+t);
        }
    }
    {
        int c=0;
        REP1(i,1,n) {
            c+=cr[i];
            assert(c>=0);
            if ( c>0 ) chkmax(lo[i],a[i-1]+t);
        }
    }
    REP1(i,2,n) chkmax(lo[i],lo[i-1]+1);
    REP1(i,1,n) if ( lo[i]>hi[i] ) {
        W("No");
        return;
    }
    W("Yes");
    W(vector<LL>(lo+1,lo+n+1));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}