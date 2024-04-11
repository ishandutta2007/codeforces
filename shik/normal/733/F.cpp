// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
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
        // if ( sz[a]>sz[b] ) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
    }
} djs;

const int N=2e5+10;
const int M=2e5+10;

struct E {
    int a,b,c,w;
} e[M];

bool cmp_w( int a, int b ) {
    return e[a].w<e[b].w;
}

int n,m,s,sid[M],fa[18][N+M];

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

int dep( int x ) {
    int d=0;
    for ( int i=17; i>=0; i-- ) if ( fa[i][x]!=0 ) {
        x=fa[i][x];
        d+=1<<i;
    }
    d++;
    return d;
}

int lca( int a, int b ) {
    int da=dep(a);
    int db=dep(b);
    if ( da>db ) {
        swap(a,b);
        swap(da,db);
    }
    for ( int i=17; i>=0; i-- ) if ( bit(db-da,i) ) b=fa[i][b];
    for ( int i=17; i>=0; i-- ) if ( fa[i][a]!=fa[i][b] ) a=fa[i][a],b=fa[i][b];
    return fa[0][a];
}

int main() {
    R(n,m);
    REP1(i,1,m) R(e[i].w);
    REP1(i,1,m) R(e[i].c);
    REP1(i,1,m) R(e[i].a,e[i].b);
    R(s);
    REP1(i,1,m) sid[i]=i;
    djs.init(n+m);
    sort(sid+1,sid+1+m,cmp_w);
    LL base=0;
    VI mst;
    REP1(ii,1,m) {
        int i=sid[ii];
        int a=djs.f(e[i].a);
        int b=djs.f(e[i].b);
        if ( a==b ) continue;
        dump(i,e[i].a,e[i].b,a,b,e[i].w);
        base+=e[i].w;
        djs.u(a,n+i);
        djs.u(b,n+i);
        fa[0][a]=fa[0][b]=n+i;
        mst.PB(i);
    }
    REP1(i,1,n) assert(fa[0][i]!=0);
    REP(i,17) REP1(j,1,n+m) fa[i+1][j]=fa[i][fa[i][j]];
    int z=0,zw=0,ban=0;
    LL mi=1e18;
    REP1(ii,1,m) {
        int i=sid[ii];
        int a=e[i].a,b=e[i].b,c=e[i].c,w=e[i].w;
        int eid=lca(a,b)-n;
        dump(a,b,eid,eid+n);
        assert(eid>=1 && eid<=m);
        LL now=base;
        now-=e[eid].w;
        now+=w-s/c;
        if ( now<mi ) {
            mi=now;
            z=i;
            ban=eid;
            zw=w-s/c;
        }
    }
    W(mi);
    for ( int i:mst ) if ( i!=ban ) W(i,e[i].w);
    W(z,zw);
    return 0;
}