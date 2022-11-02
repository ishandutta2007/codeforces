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

const int N=4e5+10;
const int M=4e5+10;

struct E {
    int a,b;
} e[M];

int n,m,fe[N],dep[N];
VI es[N];
bool vis[N],te[M];

bool cmp_dep( int x, int y ) {
    return dep[x]>dep[y];
}

void dfs( int p, int lv ) {
    dep[p]=lv;
    vis[p]=1;
    for ( int i:es[p] ) {
        int to=p^e[i].a^e[i].b;
        if ( vis[to] ) continue;
        te[i]=1;
        fe[to]=i;
        if ( p!=e[i].a ) swap(e[i].a,e[i].b);
        dfs(to,lv+1);
    }
}

VI g;
int gf[N],c[N];
bool chk( int mid ) {
    for ( int i:g ) c[i]=djs.sz[i];
    for ( int i:g ) {
        if ( i==1 ) return c[i]>=mid;
        if ( c[i]>=mid ) {
            c[gf[i]]+=c[i];
            if ( e[fe[i]].b!=i ) swap(e[fe[i]].a,e[fe[i]].b);
        } else {
            if ( e[fe[i]].a!=i ) swap(e[fe[i]].a,e[fe[i]].b);
        }
    }
    assert(0);
}

int main() {
    R(n,m);
    REP1(i,1,m) R(e[i].a,e[i].b);
    REP1(i,1,m) {
        es[e[i].a].PB(i);
        es[e[i].b].PB(i);
    }
    dfs(1,1);
    djs.init(n);
    REP1(i,1,m) if ( te[i] ) dump(i,e[i].a,e[i].b);
    REP1(i,1,m) if ( !te[i] ) {
        int a=e[i].a;
        int b=e[i].b;
        if ( dep[a]<dep[b] ) {
            swap(a,b);
            swap(e[i].a,e[i].b);
        }
        b=djs.f(b);
        while ( (a=djs.f(a))!=b ) djs.u(a,e[fe[a]].a);
    }
    REP1(i,1,n) if ( djs.f(i)==i ) {
        g.PB(i);
        if ( i!=1 ) gf[i]=djs.f(e[fe[i]].a);
    }
    sort(ALL(g),cmp_dep);
    dump(g);
    int l=0,r=n;
    while ( l!=r ) {
        int mid=(l+r+1)/2;
        if ( chk(mid) ) l=mid;
        else r=mid-1;
    }
    chk(l);
    W(l);
    REP1(i,1,m) W(e[i].a,e[i].b);
    return 0;
}