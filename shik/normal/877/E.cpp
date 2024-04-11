#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
// #include <stdio.h>
#endif
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

// {{{ Bitwise
#define F(name) \
    template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> \
    constexpr int name(T x) { return sizeof(T) <= sizeof(int) ? __builtin_ ## name(x) : __builtin_ ## name ## ll(x); }

F(clz) F(ctz) F(ffs) F(parity) F(popcount)

#undef F
#define popcnt popcount

template<class T>
T has_bit(T x, int i) { return (x >> i) & 1; }

template<class T>
constexpr int lg2(T x) { return sizeof(T) * CHAR_BIT - 1 - clz(x); }
// }}}

const int N=2e5+10;
int n,m,f[N],t[N],st[N],ed[N],ts;

uint32_t b[N/32+1];
inline int get( int i ) { return has_bit(b[i/32],i%32); }
inline void flip( int i ) { b[i/32]^=1u<<(i%32); }

VI e[N];
void dfs( int p ) {
    st[p]=++ts;
    for ( int i:e[p] ) dfs(i);
    ed[p]=ts;
}
void main() {
    R(n);
    REP1(i,2,n) R(f[i]);
    REP1(i,1,n) R(t[i]);
    REP1(i,2,n) e[f[i]].PB(i);
    dfs(1);
    REP1(i,1,n) if ( t[i] ) flip(st[i]-1);
    R(m);
    REP(mi,m) {
        char op[5];
        int x;
        R(op,x);
        int l=st[x]-1,r=ed[x]-1;
        // dump(op,x,l,r);
        if ( op[0]=='g' ) {
            int ans=0;
            if ( r-l<=64 ) {
                REP1(i,l,r) ans+=get(i);
            } else {
                while ( l%32!=0 ) ans+=get(l++);
                while ( r%32!=0 ) ans+=get(r--);
                ans+=get(r--);
                int li=l/32,ri=r/32;
                REP1(i,li,ri) ans+=popcnt(b[i]);
            }
            W(ans);
        } else if ( op[0]=='p' ) {
            if ( r-l<=64 ) {
                REP1(i,l,r) flip(i);
            } else {
                while ( l%32!=0 ) flip(l++);
                while ( r%32!=0 ) flip(r--);
                flip(r--);
                int li=l/32,ri=r/32;
                REP1(i,li,ri) b[i]=~b[i];
            }
        } else while(1);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}