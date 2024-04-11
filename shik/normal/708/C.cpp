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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

const int N=4e5+10;

int n;
VI e[N];

int sz[N];
int get_sz( int p, int f ) {
    sz[p]=1;
    for ( int i:e[p] ) if ( i!=f ) sz[p]+=get_sz(i,p);
    return sz[p];
}

int dp[N];
int get_dp( int p, int f ) {
    dp[p]=0;
    for ( int i:e[p] ) if ( i!=f ) {
        int t=get_dp(i,p);
        dp[p]=max(dp[p],t);
    }
    if ( sz[p]<=n/2 ) dp[p]=sz[p];
    return dp[p];
}

int sol[N];

void go( int p, int mx ) {
    int up=n-sz[p];
    if ( up-mx<=n/2 ) sol[p]=1;
    int w1=-1,mx1=0,w2=-1,mx2=0;
    for ( int i:e[p] ) if ( sz[i]<sz[p] && dp[i]<=n/2 ) {
        if ( dp[i]>mx1 ) {
            tie(w2,mx2)=tie(w1,mx1);
            tie(w1,mx1)=tie(i,dp[i]);
        } else if ( dp[i]>mx2 ) {
            tie(w2,mx2)=tie(i,dp[i]);
        }
    }
    for ( int i:e[p] ) if ( sz[i]<sz[p] ) {
        int nx=mx;
        if ( i!=w1 ) chkmax(nx,mx1);
        else chkmax(nx,mx2);
        if ( n-sz[i]<=n/2 ) chkmax(nx,n-sz[i]);
        go(i,nx);
    }
}

int main() {
    R(n);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    get_sz(1,0);
    int rt=0,mi=N;
    REP1(i,1,n) {
        int mx=n-sz[i];
        for ( int j:e[i] ) if ( sz[j]<sz[i] ) mx=max(mx,sz[j]);
        if ( mx<mi ) {
            rt=i;
            mi=mx;
        }
    }
    assert(mi<=n/2);
    get_sz(rt,0);
    get_dp(rt,0);
    go(rt,0);
    W(VI(sol+1,sol+n+1));
    return 0;
}