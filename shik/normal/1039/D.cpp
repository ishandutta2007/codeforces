#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
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

const int N=1e5+10;

int n,k;
VI e[N];

void make_tree( int p ) {
    for ( int i:e[p] ) {
        e[i].erase(find(ALL(e[i]),p));
        make_tree(i);
    }
}

PII go( int p ) {
    int s=0,r=0,a1=0,a2=0;
    for ( int i:e[p] ) {
        auto t=go(i);
        s+=t.first;
        int x=t.second;
        if ( x>=a1 ) {
            a2=a1;
            a1=x;
        } else if ( x>=a2 ) {
            a2=x;
        }
    }
    if ( a1+a2+1>=k ) {
        s++;
    } else {
        r=a1+1;
    }
    // dump(p,s,r);
    return {s,r};
}

int shik( int _k ) {
    k=_k;
    return go(1).first;
}

int ans[N];
void solve( int l, int r, int al, int ar ) {
    if ( r-l<=1 ) return;
    if ( al==ar ) {
        REP1(i,l,r) ans[i]=al;
        return;
    }
    int m=(l+r)/2;
    int am=shik(m);
    ans[m]=am;
    solve(l,m,al,am);
    solve(m,r,am,ar);
}

void main() {
    R(n);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    make_tree(1);
    ans[1]=n;
    solve(1,n+1,n,0);
    REP1(i,1,n) W(ans[i]);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}