// {{{ by shik
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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

inline char next_char() {
    static char buf[1<<16];
    static char *p = buf, *end = buf;
    if ( p==end ) {
        end=buf+fread(buf,1,sizeof(buf),stdin);
        p=buf;
    }
    return *p++;
}

inline void gn( int &x ) {
    int c;
    while ( (c=next_char())<'0' || c>'9' );
    x=c-'0';
    while ( (c=next_char())>='0' && c<='9' ) x=x*10+c-'0';
}

#define putchar meow

char buf[1<<16],*pbuf=buf;
inline void meow( char c ) {
    *pbuf++=c;
    if ( pbuf==end(buf) ) {
        fwrite(buf,1,sizeof(buf),stdout);
        pbuf=buf;
    }
}

inline void pn( int x ) {
    char s[16],*p=s;
    do {
        *p++=x%10+'0';
        x/=10;
    } while ( x );
    do {
        putchar(*--p);
    } while ( p!=s );
}

#define lg2(n) (31-__builtin_clz(n))

const int N=1010;
const int LGN=lg2(N)+1;

struct RMQ_2D {
    int16_t v[LGN][LGN][N][N];
    void init( int n, int m, int16_t a[N][N] ) {
        const int lgn=lg2(n);
        const int lgm=lg2(m);
        REP1(i,0,lgn) REP1(j,0,lgm) {
            int ux=n-(1<<i);
            int uy=m-(1<<j);
            REP1(x,0,ux) REP1(y,0,uy) {
                auto &me=v[i][j][x][y];
                if ( i==0 && j==0 ) me=a[x][y];
                else if ( i==0 ) me=max(v[i][j-1][x][y],v[i][j-1][x][y+(1<<(j-1))]);
                else me=max(v[i-1][j][x][y],v[i-1][j][x+(1<<(i-1))][y]);
            }
        }
    }
    int ask( int x1, int y1, int x2, int y2 ) { // [x1,y1] ~ [x2,y2]
        const int lx=lg2(x2-x1+1);
        const int ly=lg2(y2-y1+1);
        auto *me=v[lx][ly];
        x2-=(1<<lx)-1;
        y2-=(1<<ly)-1;
        return max(max(me[x1][y1],me[x1][y2]),max(me[x2][y1],me[x2][y2]));
    }
} rmq;

int n,m,a[N][N],q;
int16_t b[N][N];
int main() {
    gn(n); gn(m);
    REP1(i,1,n) REP1(j,1,m) gn(a[i][j]);
    REP1(i,1,n) REP1(j,1,m) if ( a[i][j] ) b[i][j]=min(min(b[i-1][j],b[i][j-1]),b[i-1][j-1])+1;
    rmq.init(n+1,m+1,b);
    gn(q);
    while ( q-- ) {
        int x1,y1,x2,y2;
        gn(x1); gn(y1); gn(x2); gn(y2);
        int l=0,r=min(x2-x1+1,y2-y1+1);
        while ( l!=r ) {
            int mid=(l+r+1)/2;
            int t=rmq.ask(x1+mid-1,y1+mid-1,x2,y2);
            if ( t>=mid ) l=mid;
            else r=mid-1;
        }
        pn(l);
        putchar('\n');
    }
    fwrite(buf,1,pbuf-buf,stdout);
    return 0;
}