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

struct LiChao_min
{
    struct line
    {
        int64_t a, b;
        line() { a = 0; b = 0; }
        line(int64_t _a, int64_t _b) { a = _a; b = _b; }
        int64_t eval(int x) { return a * 1ll * x + (int64_t)b; }
    };
 
    struct node
    {
        node *l, *r; line f;
 
        node() { f = line(); l = nullptr; r = nullptr; }
        node(int64_t a, int64_t b) { f = line(a, b); l = nullptr; r = nullptr; }
        node(line v) { f = v; l = nullptr; r = nullptr; }
    };
 
    typedef node* pnode;
 
    pnode root; int sz;
    void init(int _sz) { sz = _sz + 1; root = nullptr; }
 
    void add_line(int64_t a, int64_t b) { line v = line(a, b); insert(v, -sz, sz, root); }
    int64_t query(int x) { return query(x, -sz, sz, root); }
 
    void insert(line &v, int l, int r, pnode &nd)
    {
        if(!nd) { nd = new node(v); return; }
 
        int64_t trl = nd->f.eval(l), trr = nd->f.eval(r);
        int64_t vl = v.eval(l), vr = v.eval(r);
 
        if(trl <= vl && trr <= vr) return;
        if(trl > vl && trr > vr) { nd->f = v; return; }
 
        int mid = (l + r) >> 1;
        if(trl > vl) swap(nd->f, v);
        if(nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else swap(nd->f, v), insert(v, l, mid, nd->l);
    }
 
    int64_t query(int x, int l, int r, pnode &nd)
    {
        if(!nd) return LLONG_MAX;
        if(l == r) return nd->f.eval(x);
 
        int mid = (l + r) >> 1;
        if(mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
        return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
};

const int N=1e5+10;

int n;
LL a[N],b[N];
VI e[N];

int sz[N];
void dfs( int p ) {
    sz[p]=1;
    for ( int i:e[p] ) {
        e[i].erase(find(ALL(e[i]),p));
        dfs(i);
        sz[p]+=sz[i];
    }
}

bool cmp_sz( int x, int y ) {
    return sz[x]>sz[y];
}

LL sol[N];
LiChao_min dp[N];

void go2( int p, LiChao_min &t ) {
    t.add_line(b[p],sol[p]);
    for ( int i:e[p] ) go2(i,t);
}

void go( int p ) {
    for ( int i:e[p] ) go(i);
    if ( e[p].empty() ) {
        dp[p].init(100000);
    } else {
        dp[p]=dp[e[p][0]];
        REP1(i,1,SZ(e[p])-1) go2(e[p][i],dp[p]);
        sol[p]=dp[p].query(a[p]);
    }
    dp[p].add_line(b[p],sol[p]);
}

void main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) R(b[i]);
    REP(i,n-1) {
        int u,v;
        R(u,v);
        e[u].PB(v);
        e[v].PB(u);
    }
    dfs(1);
    REP1(i,1,n) sort(ALL(e[i]),cmp_sz);
    go(1);
    W(vector<LL>(sol+1,sol+n+1));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}