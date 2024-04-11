// {{{ by shik
#pragma GCC optimize("O3")
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

const LL MOD=1e9+7;
const LL INV2=(MOD+1)/2;

struct M {
    LL x[2][2];
    LL* operator[]( int i ) { return x[i]; }
    const LL* operator[]( int i ) const { return x[i]; }
};

inline M operator *( const M &a, const M &b ) {
    M c;
	c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
	c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
	c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
	c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
    return c;
}

M A{{
    {0,1},
	{2,1}
}};

M IA={{
    {MOD-INV2,INV2},
    {1,0}
}};

M I{{ {1,0},{0,1} }};

inline M pw( M a, LL n ) {
    M s=I,r=a;
    while ( n ) {
        if ( n&1 ) s=s*r;
        r=r*r;
        n>>=1;
    }
    return s;
}

inline LL pw( LL x, LL n ) {
    LL s=1,r=x;
    while ( n ) {
        if ( n&1 ) s=s*r%MOD;
        r=r*r%MOD;
        n>>=1;
    }
    return s;
}

const int N=1e5+10;
int n;
LL a[N];
int main() {
    R(n);
    REP(i,n) R(a[i]);
    M X=A;
    LL Y=2;
    REP(i,n) {
        X=pw(X,a[i]);
        Y=pw(Y,a[i]);
    }
    LL x=(X*IA)[0][1]%MOD;
    LL y=Y*INV2%MOD;
    printf("%lld/%lld\n",x,y);
    return 0;
}