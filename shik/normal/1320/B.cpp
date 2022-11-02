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

// PRNG {{{
template<class T, T x1, T x2, T x3, int y1, int y2, int y3>
struct PRNG {
    using S = typename make_signed<T>::type;
    T s;
    PRNG() {
#ifdef SHIK
        s = 0;
#else
        s = chrono::high_resolution_clock::now().time_since_epoch().count() & numeric_limits<T>::max();
#endif
    }
    PRNG(T _s) : s(_s) {}
    T next() {
        T z = (s += x1);
        z = (z ^ (z >> y1)) * x2;
        z = (z ^ (z >> y2)) * x3;
        return z ^ (z >> y3);
    }
    T next(T n) { return next() % n; }
    S next(S l, S r) { return l + next(r - l + 1); }
    T operator()() { return next(); }
    T operator()(T n) { return next(n); }
    S operator()(S l, S r) { return next(l, r); }
    static T gen(T s) { return PRNG(s)(); }
    template<class U>
    void shuffle(U first, U last) {
        size_t n = last - first;
        for (size_t i = 0; i < n; i++) swap(first[i], first[next(i + 1)]);
    }
};

using R32 = PRNG<uint32_t, 0x9E3779B1, 0x85EBCA6B, 0xC2B2AE35, 16, 13, 16>;
R32 r32;

using R64 = PRNG<uint64_t, 0x9E3779B97F4A7C15, 0xBF58476D1CE4E5B9, 0x94D049BB133111EB, 30, 27, 31>;
R64 r64;
// }}}

const int N=2e5+10;
int n,m,pn,p[N],dis[N];
LL cnt[N],mod;
VI e[N],re[N];
void main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        re[b].PB(a);
    }
    R(pn);
    REP(i,pn) R(p[i]);
    REP1(i,1,n) dis[i]=N;
    int ed=p[pn-1];
    dis[ed]=0;
    queue<int> q;
    q.push(ed);
    vector<int> v;
    while ( !q.empty() ) {
        int u=q.front(); q.pop();
        v.PB(u);
        for ( int i:re[u] ) {
            if ( dis[i]!=N ) continue;
            dis[i]=dis[u]+1;
            q.push(i);
        }
    }
    dump(VI(dis+1,dis+n+1));
    mod=r64(1LL<<60,1LL<<61);
    REP1(i,1,n) cnt[i]=0;
    for ( int i:v ) {
        if ( i==ed ) {
            cnt[i]=1;
        } else {
            for ( int j:e[i] ) if ( dis[i]-1==dis[j] ) {
                cnt[i]+=cnt[j];
                if ( cnt[i]>=mod ) cnt[i]-=mod;
            }
        }
    }
    dump(VI(cnt+1,cnt+n+1));
    int lo=0,hi=0;
    REP(i,pn-1) {
        int a=p[i];
        int b=p[i+1];
        if ( dis[a]-1!=dis[b] ) {
            lo++;
            hi++;
        } else {
            if ( cnt[a]!=cnt[b] ) hi++;
        }
    }
    W(lo,hi);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}