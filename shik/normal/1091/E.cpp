#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,variable-expansion-in-unroller")
#pragma GCC target("avx")
#include <stdio.h>
#endif

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

const int N=5e5+10;

int dat[N];

struct P {
    int k;
    LL ssl,nr;
    P() : k(0), ssl(0),nr(0) {
        memset(dat,0,sizeof(dat));
    }
    // sl: <k
    // sr: >=k
    void ins( int x ) {
        // assert(k==0);
        dat[x]++;
        nr++;
        // sr.insert(x);
    }
    void del( int x ) {
        if ( x<k ) {
            ssl-=x;
        } else {
            dat[x]--;
            nr--;
        }
    }
    void inc( int nk ) {
        // assert(k<=nk);
        while ( k<nk ) {
            ssl+=(LL)k*dat[k];
            nr-=dat[k];
            dat[k]=0;
            k++;
        }
    }
    LL get() {
        return ssl+(LL)k*nr;
    }
};

bool chk( int n, int d[] ) {
    LL sd=0;
    REP1(i,1,n) sd+=d[i];
    if ( sd%2==1 ) return 0;
    sort(d+1,d+n+1,greater<int>());
    P p;
    REP1(i,1,n) p.ins(d[i]);
    LL s=0;
    REP1(i,1,n) {
        p.del(d[i]);
        p.inc(i);
        s+=d[i];
        LL t=i*(i-1LL)+p.get();
        if ( s>t ) return 0;
    }
    return 1;
}

int n,a[N],d[N];

bool chk( int i ) {
    REP1(j,1,n) d[j]=a[j];
    d[n+1]=i;
    return chk(n+1,d);
}

VI slow() {
    VI ans;
    REP1(i,0,n) if ( chk(i) ) ans.PB(i);
    return ans;
}

void main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    sort(a+1,a+n+1,greater<int>());
    P p;
    REP1(i,1,n) p.ins(a[i]);
    LL s=0,cnt=0;
    REP1(i,1,n) {
        p.del(a[i]);
        p.inc(i);
        s+=a[i];
        LL t=i*(i-1LL)+p.get();
        if ( s>t ) {
            cnt+=s-t;
            s=t;
        }
    }
    LL o=0;
    REP1(i,1,n) o+=a[i];
    if ( cnt%2!=o%2 ) cnt++;
    if ( cnt>n || !chk(cnt) ) {
        W(-1);
        return;
    }
    int lo=cnt,hi=cnt;
    for ( int i=18; i>=1; i-- ) {
        if ( hi+(1<<i)<=n && chk(hi+(1<<i)) ) hi+=1<<i;
    }
    VI ans;
    for ( int i=lo; i<=hi; i+=2 ) ans.PB(i);
    // assert(ans==slow());
    W(ans);
    // NO CACHE PLZ
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}