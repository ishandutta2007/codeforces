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

struct Rec {
    int x1,y1,x2,y2;
};

int n;

int ask( int x1, int y1, int x2, int y2 ) {
    assert(1<=x1 && x1<=x2 && x2<=n);
    assert(1<=y1 && y1<=y2 && y2<=n);
    W("?",x1,y1,x2,y2);
    fflush(stdout);
    int ret;
    R(ret);
    assert(0<=ret && ret<=2);
    return ret;
}

int split_x() {
    int l=1,r=n;
    while ( l<r ) {
        int m=(l+r)/2;
        int t=ask(1,1,m,n);
        if ( t==0 ) l=m+1;
        else if ( t==1 ) r=m;
        else if ( t==2 ) r=m-1;
    }
    if ( l<=r && ask(1,1,l,n)==1 && ask(l+1,1,n,n)==1 ) return l;
    else return 0;
}

int split_y() {
    int l=1,r=n;
    while ( l<r ) {
        int m=(l+r)/2;
        int t=ask(1,1,n,m);
        if ( t==0 ) l=m+1;
        else if ( t==1 ) r=m;
        else if ( t==2 ) r=m-1;
    }
    if ( l<=r && ask(1,1,n,l)==1 && ask(1,l+1,n,n)==1 ) return l;
    else return 0;
}

pair<Rec,Rec> split() {
    int x=split_x();
    if ( x ) return {{1,1,x,n},{x+1,1,n,n}};
    int y=split_y();
    if ( y ) return {{1,1,n,y},{1,y+1,n,n}};
    assert(0);
}

Rec shrink( int x1, int y1, int x2, int y2 ) {
    assert(ask(x1,y1,x2,y2)==1);
    for ( int i=1<<15; i; i>>=1 ) if ( x1+i<=x2 && ask(x1+i,y1,x2,y2)==1 ) x1+=i;
    for ( int i=1<<15; i; i>>=1 ) if ( y1+i<=y2 && ask(x1,y1+i,x2,y2)==1 ) y1+=i;
    for ( int i=1<<15; i; i>>=1 ) if ( x2-i>=x1 && ask(x1,y1,x2-i,y2)==1 ) x2-=i;
    for ( int i=1<<15; i; i>>=1 ) if ( y2-i>=y1 && ask(x1,y1,x2,y2-i)==1 ) y2-=i;
    return {x1,y1,x2,y2};
}

int main() {
    R(n);
    Rec r1,r2;
    tie(r1,r2)=split();
    r1=shrink(r1.x1,r1.y1,r1.x2,r1.y2);
    r2=shrink(r2.x1,r2.y1,r2.x2,r2.y2);
    W("!",r1.x1,r1.y1,r1.x2,r1.y2,r2.x1,r2.y1,r2.x2,r2.y2);
    return 0;
}