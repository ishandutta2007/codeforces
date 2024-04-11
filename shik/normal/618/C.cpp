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

inline int sgn( LL x ) { return (x>0)-(x<0); }

const int N=1e5+10;

struct P {
    int id;
    LL x,y;
} p[N];

P operator -( P a, P b ) { return {0,a.x-b.x,a.y-b.y}; }
LL X( P a, P b ) { return a.x*b.y-b.x*a.y; }
LL X( P o, P a, P b ) { return X(a-o,b-o); }
int dir( P o, P a, P b ) { return sgn(X(o,a,b)); }

inline bool in( P a, P b, P c, P d ) {
    int d1=dir(a,b,d);
    int d2=dir(b,c,d);
    int d3=dir(c,a,d);
    return d1*d2>=0 && d1*d3>=0 && d2*d3>=0;
}

inline bool on( P a, P b, P c ) {
    if ( c.x<min(a.x,b.x) || c.x>max(a.x,b.x) ) return 0;
    if ( c.y<min(a.y,b.y) || c.y>max(a.y,b.y) ) return 0;
    return dir(a,b,c)==0;
}

int main() {
    int n;
    R(n);
    REP(i,n) {
        p[i].id=i+1;
        R(p[i].x,p[i].y);
    }
    REP1(i,2,n-1) if ( dir(p[0],p[1],p[i])!=0 ) {
        swap(p[2],p[i]);
        break;
    }
    REP1(i,3,n-1) {
        if ( on(p[0],p[1],p[i]) ) swap(p[0],p[i]);
        else if ( on(p[1],p[2],p[i]) ) swap(p[1],p[i]);
        else if ( on(p[2],p[0],p[i]) ) swap(p[2],p[i]);
        else if ( in(p[0],p[1],p[2],p[i]) ) swap(p[0],p[i]);
    }
    REP1(i,3,n-1) assert(!in(p[0],p[1],p[2],p[i]));
    W(p[0].id,p[1].id,p[2].id);
    return 0;
}