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

struct DJS {
    vector<int> fa,sz;
    void init( int n ) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for ( int i=0; i<n; i++ ) sz[fa[i]=i]=1;
    }
    int f( int x ) {
        return x==fa[x]?x:fa[x]=f(fa[x]);
    }
    void u( int a, int b ) {
        a=f(a); b=f(b);
        if ( a==b ) return;
        if ( sz[a]>sz[b] ) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
    }
} djs;

struct SplitMix64 {
    uint64_t s;
    SplitMix64(uint64_t _s = 31337) : s(_s) {}
    uint64_t operator()() {
        uint64_t z = (s += 0x9E3779B97F4A7C15);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EB;
        return z ^ (z >> 31);
    }
} rnd;

vector<VI> read() {
    static char s[10000];
    vector<VI> vv;
    R(s);
    char *p=s;
    while ( *p ) {
        int l,t,r;
        r=sscanf(p,"%d%n",&l,&t);
        assert(r==1);
        p+=t;
        assert(*p==':');
        p++;
        VI v(l);
        REP(i,l) {
            r=sscanf(p,"%d%n",&v[i],&t);
            assert(r==1);
            p+=t;
            if ( *p==',' ) p++;
        }
        sort(ALL(v));
        vv.PB(v);
        if ( *p=='-' ) p++;
    }
    sort(ALL(vv));
    return vv;
}

const int N=1010;

int n;
vector<VI> vv[N];
uint64_t r[N],h[N][N];
vector<PII> es;

VI e[N];

void dfs( int p, int f, VI &o ) {
    o.PB(p);
    for ( int i:e[p] ) if ( i!=f ) dfs(i,p,o);
}

bool check() {
    if ( SZ(es)!=n-1 ) return 0;
    djs.init(n);
    for ( auto i:es ) {
        int a=i.first,b=i.second;
        if ( djs.f(a)==djs.f(b) ) return 0;
        djs.u(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP1(i,1,n) {
        vector<VI> uu;
        for ( int j:e[i] ) {
            VI u;
            dfs(j,i,u);
            sort(ALL(u));
            uu.PB(u);
        }
        sort(ALL(uu));
        dump(i,uu,vv[i]);
        if ( uu!=vv[i] ) return 0;
    }
    return 1;
}

int main() {
    R(n);
    REP1(i,1,n) vv[i]=read();
    REP1(i,1,n) dump(i,vv[i]);
    REP1(i,1,n) r[i]=rnd();
    REP1(i,1,n) {
        for ( auto &v:vv[i] ) {
            uint64_t s=0;
            for ( int j:v ) s^=r[j];
            for ( int j:v ) h[i][j]=s;
        }
    }
    uint64_t g=0;
    REP1(i,1,n) g^=r[i];
    REP1(i,1,n) REP1(j,i+1,n) if ( (h[i][j]^h[j][i])==g ) es.PB({i,j});
    dump(es);
    if ( check() ) {
        W(n-1);
        for ( auto i:es ) W(i.first,i.second);
    } else {
        W(-1);
    }
    return 0;
}