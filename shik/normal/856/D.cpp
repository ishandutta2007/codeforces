// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }

template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f\n",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

template<class T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) { cerr << s << "=" << head << endl; }
template<class T, class... Args> void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...) do { fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); _dump(#__VA_ARGS__, __VA_ARGS__); } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B> ostream &operator<<(ostream &s, const pair<A, B> &p) { return s << "(" << p.first << "," << p.second << ")"; }
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) { return _out(s, ALL(c)); }
template<class T, size_t N> ostream &operator<<(ostream &s, const array<T, N> &c) { return _out(s, ALL(c)); }
template<class T> ostream &operator<<(ostream &s, const set<T> &c) { return _out(s, ALL(c)); }
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) { return _out(s, ALL(c)); }
#else
#define dump(...)
#endif
// }}}

template<class T>
struct BIT {
    int n;
    vector<T> dat;
    void init(int _n) {
        n = _n;
        dat.clear();
        dat.resize(n + 1);
    }
    template<bool ask_range>
    void init(int _n, T a[]) {
        init(_n);
        for (int i = 1; i <= n; i++) {
            dat[i] += ask_range ? a[i] : a[i] - a[i - 1];
            int j = i + (i & -i);
            if (j <= n) dat[j] += dat[i];
        }
    }
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) dat[i] += v;
    }
    T ask(int x) {
        T s = T();
        for (int i = x; i; i -= i & -i) s += dat[i];
        return s;
    }
    // cannot add/ask a range simultaneously!
    void add(int l, int r, T v) {
        add(l, v);
        if (r + 1 <= n) add(r + 1, -v);
    }
    T ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};

constexpr int lg2( int x ) { return 31-__builtin_clz(x); }

const int N=2e5+10;
const int M=2e5+10;
const int LGN=lg2(N)+1;

struct Q {
    int a,b,c;
} q[M];

int n,m;
VI e[N];

void input() {
    R(n,m);
    REP1(i,2,n) {
        int x;
        R(x);
        e[x].PB(i);
    }
    REP(i,m) R(q[i].a,q[i].b,q[i].c);
}

int dep[N],fa[LGN][N],dt[N],ot[N],ts;
void dfs( int p, int f, int lv ) {
    dep[p]=lv;
    fa[0][p]=f;
    dt[p]=++ts;
    for ( int i:e[p] ) if ( i!=f ) dfs(i,p,lv+1);
    ot[p]=ts;
}

int lgn;
void lca_build() {
    for (int i = 0; i < lgn; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i + 1][j] = fa[i][fa[i][j]];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int d = dep[b] - dep[a];
    int l = lg2(dep[b]);
    for (int i = 0; i <= l; i++) {
        if ((d >> i) & 1) b = fa[i][b];
    }
    if (a == b) return a;
    for (int i = lg2(dep[a]); i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}

VI vq[N];

void build() {
    dfs(1,0,1);
    lgn=lg2(n);
    lca_build();
    REP(i,m) {
        int p=lca(q[i].a,q[i].b);
        vq[p].PB(i);
    }
}

LL dp[N];
BIT<LL> b1,b2;

LL shik( int a, int b, int c ) {
    int d=fa[0][c];
    LL s=0;

    LL sa1=b1.ask(dt[a]);
    LL sb1=b1.ask(dt[b]);
    LL sc1=b1.ask(dt[c]);
    
    LL sa2=b2.ask(dt[a]);
    LL sb2=b2.ask(dt[b]);
    LL sc2=b2.ask(dt[c]);
    LL sd2=b2.ask(dt[d]);
    
    s+=sa2+sb2-sc2-sd2;
    s-=sa1+sb1-2*sc1;

    // dump(a,b,c,d,s);

    return s;
}

void go( int p ) {
    for ( int i:e[p] ) go(i);
    LL mx=0;
    {
        LL s=0;
        for ( int i:e[p] ) s+=dp[i];
        chkmax(mx,s);
    }
    for ( int i:vq[p] ) {
        LL now=shik(q[i].a,q[i].b,p)+q[i].c;
        chkmax(mx,now);
    }
    b1.add(dt[p],ot[p],mx);
    int f=fa[0][p];
    if ( f!=0 ) b2.add(dt[f],ot[f],mx);
    dp[p]=mx;
}

void solve() {
    b1.init(n);
    b2.init(n);
    go(1);
    W(dp[1]);
}

int main() {
    input();
    build();
    solve();
    return 0;
}