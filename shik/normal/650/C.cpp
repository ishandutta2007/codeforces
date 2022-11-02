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

const int N=1e6+10;

struct DJS {
    int fa[N];
    void init( int n ) {
        REP(i,n) fa[i]=i;
    }
    int F( int x ) {
        return x==fa[x]?x:fa[x]=F(fa[x]);
    }
    void U( int a, int b ) {
        fa[F(a)]=F(b);
    }
} djs;

int n,m,a[N],sa[N],ind[N],b[N];
vector<int> e[N];

inline bool cmp( int x, int y ) {
    return a[x]<a[y];
}

int main() {
    R(n,m);
    REP(i,n*m) R(a[i]);
    djs.init(n*m);
    vector<PII> es;
    REP(i,n) {
        REP(j,m) sa[j]=i*m+j;
        sort(sa,sa+m,cmp);
        REP(j,m-1) {
            int x=sa[j],y=sa[j+1];
            if ( a[x]==a[y] ) djs.U(x,y);
            else es.PB(MP(x,y));
        }
    }
    REP(i,m) {
        REP(j,n) sa[j]=j*m+i;
        sort(sa,sa+n,cmp);
        REP(j,n-1) {
            int x=sa[j],y=sa[j+1];
            if ( a[x]==a[y] ) djs.U(x,y);
            else es.PB(MP(x,y));
        }
    }
    dump(es);
    for ( auto i:es ) e[djs.F(i.first)].PB(djs.F(i.second));
    REP(i,n*m) if ( djs.F(i)==i ) for ( int j:e[i] ) ind[j]++;
    VI v;
    REP(i,n*m) if ( djs.F(i)==i && ind[i]==0 ) v.PB(i);
    int iter=0;
    while ( !v.empty() ) {
        iter++;
        VI nv;
        for ( int i:v ) {
            b[i]=iter;
            for ( int j:e[i] ) if ( --ind[j]==0 ) nv.PB(j);
        }
        v.swap(nv);
    }
    REP(i,n*m) if ( !b[i] ) {
        assert(djs.F(i)!=i);
        b[i]=b[djs.F(i)];
    }
    REP(i,n) REP(j,m) printf("%d%c",b[i*m+j],j+1==m?'\n':' ');
    return 0;
}