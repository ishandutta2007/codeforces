// {{{ by shik
#pragma GCC optimize("O3")
#include <stdio.h>
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

#define y1 shik_y1_meow

const int N=1010;
const int Q=3e5+10;

void build( int n, int m, LL a[N][N] ) {
    REP1(i,1,n) REP1(j,1,m) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
}

inline LL sum( LL s[N][N], int x1, int y1, int x2, int y2 ) {
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

inline void add( LL s[N][N], int x1, int y1, int x2, int y2 ) {
    s[x1][y1]++;
    s[x2+1][y1]--;
    s[x1][y2+1]--;
    s[x2+1][y2+1]++;
}

int n,m,q,x1[Q],y1[Q],x2[Q],y2[Q];
char t[N][N],c[Q];
LL st[N][N],sq[N][N],sd[N][N],dt[Q],dis[Q];

inline void build( LL s[N][N] ) {
    build(n,m,s);
}

inline LL sum( LL s[N][N], int i ) {
    return sum(s,x1[i],y1[i],x2[i],y2[i]);
}

inline void add( LL s[N][N], int i ) {
    return add(s,x1[i],y1[i],x2[i],y2[i]);
}

int main() {
    R(n,m,q);
    REP1(i,1,n) scanf("%s",t[i]+1);
    REP1(i,1,q) R(x1[i],y1[i],x2[i],y2[i],c[i]);

    REP1(i,1,n) REP1(j,1,m) t[i][j]-='a';
    REP1(i,1,q) c[i]-='a';

    REP(i,26) {
        REP1(x,1,n) REP1(y,1,m) st[x][y]=(t[x][y]==i);
        build(st);
        REP1(j,1,q) dt[j]+=abs(c[j]-i)*sum(st,j);
    }
    dump(vector<LL>(dt+1,dt+q+1));
    REP1(i,1,q) dis[i]+=q*dt[i];
    dump(vector<LL>(dis+1,dis+q+1));
    
    LL sdt=0;
    REP1(i,1,q) sdt+=dt[i];
    dump(sdt);
    REP1(i,1,q) dis[i]+=sdt;
    dump(vector<LL>(dis+1,dis+q+1));

    REP1(i,1,q) add(sq,i);
    build(sq);
    REP(i,26) {
        REP1(x,1,n) REP1(y,1,m) sd[x][y]=abs(t[x][y]-i)*sq[x][y];
        build(sd);
        REP1(j,1,q) if ( c[j]==i ) dis[j]-=sum(sd,j);
    }
    dump(vector<LL>(dis+1,dis+q+1));

    REP(i,26) {
        memset(sq,0,sizeof(sq));
        REP1(j,1,q) if ( c[j]==i ) add(sq,j);
        build(sq);
        REP1(x,1,n) REP1(y,1,m) sd[x][y]=abs(t[x][y]-i)*sq[x][y];
        build(sd);
        REP1(j,1,q) dis[j]-=sum(sd,j);
        build(sq);
        REP1(j,1,q) dis[j]+=abs(c[j]-i)*sum(sq,j);
    }
    dump(vector<LL>(dis+1,dis+q+1));

    auto ans=*min_element(dis+1,dis+q+1);
    W(ans);
    return 0;
}