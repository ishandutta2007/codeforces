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

// {{{ DJS
struct DJS {
    vector<int> fa, sz;
    DJS() {}
    DJS(int n) { init(n); }
    void init(int n) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int f(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        fa[a] = b;
        sz[b] += sz[a];
    }
    int size(int x) {
        return sz[f(x)];
    }
    bool is_root(int x) {
        return x == fa[x];
    }
    bool same(int a, int b) {
        return f(a) == f(b);
    }
};
// }}}

const int N=1e5+10;
int m,n,a[N],b[N],g[N];
VI s[N];
DJS djs;
void main() {
    R(m,n);
    REP(i,m) R(a[i]);
    REP1(i,1,n) R(b[i]);
    REP(i,m) {
        int l;
        R(l);
        s[i].resize(l);
        REP(j,l) R(s[i][j]);
    }
    LL tot=0;
    vector<array<int,3>> v;
    REP(i,m) for ( int j:s[i] ) {
        tot+=a[i]+b[j];
        v.PB({{a[i]+b[j],i,j}});
    }
    // dump(tot);
    LL ans=0;
    djs.init(n);
    sort(ALL(v),greater<>());
    REP(i,m) g[i]=-1;
    for ( const auto [w,i,j]:v ) {
        // dump(w,i,j,ans);
        if ( g[i]==-1 ) {
            ans+=w;
            g[i]=j;
            continue;
        }
        int x=j;
        int y=g[i];
        if ( djs.same(x,y) ) continue;
        // dump(x,y);
        djs.u(x,y);
        ans+=w;
    }
    // dump(ans);
    ans=tot-ans;
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}