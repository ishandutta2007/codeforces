// {{{ by shik
// #include <stdio.h>
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
void _W( const long long &x ) { printf("%" PRId64,x); }
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

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

struct NPC {
    int n,cnt;
    VI a;
    void init( int _n, int k ) {
        n=_n;
        cnt=0;
        a.clear();
        REP1(i,1,n) a.PB(i);
        random_shuffle(ALL(a));
        a.resize(k);
        sort(ALL(a));
        if ( k<=100 ) dump(n,k,a);
    }
    bool ask( int x, int y ) {
        assert(1<=x && x<=n);
        assert(1<=y && y<=n);
        assert(x!=y);
        cnt++;
        int dx=n,dy=n;
        for ( int i:a ) {
            chkmin(dx,abs(i-x));
            chkmin(dy,abs(i-y));
        }
        return dx<=dy;
    }
    void check( int x, int y ) {
        assert(1<=x && x<=n);
        assert(1<=y && y<=n);
        assert(x!=y);
        bool fx=0,fy=0;
        for ( int i:a ) {
            if ( i==x ) fx=1;
            if ( i==y ) fy=1;
        }
        assert(cnt<=60);
        assert(fx);
        assert(fy);
        dump(cnt,x,y,"AC!");
    }
} npc;

bool ask( int x, int y ) {
    W(1,x,y);
    fflush(stdout);
#ifdef SHIK
    return npc.ask(x,y);
#else
    char buf[10];
    R(buf);
    return strcmp(buf,"TAK")==0;
#endif
}

void check( int x, int y ) {
    W(2,x,y);
    fflush(stdout);
#ifdef SHIK
    npc.check(x,y);
#else
    exit(0);
#endif
}

int n,k;

int go( int l, int r ) {
    if ( l==r ) {
        int x=l;
        bool ok=1;
        ok&=(x==1 || ask(x,x-1));
        ok&=(x==n || ask(x,x+1));
        return ok ? x : -1;
    }
    int m=(l+r)/2;
    bool b=ask(m,m+1);
    return b ? go(l,m) : go(m+1,r);
}

int main() {
    // REP(i,10000) {
        // n=rand()%1000+2;
        // k=rand()%10+2;
    R(n,k);
#ifdef SHIK
    npc.init(n,k);
#endif
    int x=go(1,n);
    assert(x!=-1);
    int y=-1;
    if ( y==-1 && x>1 ) y=go(1,x-1);
    if ( y==-1 && x<n ) y=go(x+1,n);
    assert(y!=-1);
    check(x,y);
    // }
    return 0;
}