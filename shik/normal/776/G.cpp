// {{{ by shik
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

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

const int L=20;
const int Z=1<<16;

bool single( LL n ) {
    int s=0;
    LL x=n;
    while ( x ) {
        s|=1<<(x%16);
        x/=16;
    }
    return (n^s)<n;
}

LL slow( LL n ) {
    LL ans=0;
    for ( LL i=1; i<=n; i++ ) if ( single(i) ) ans++;
    return ans;
}

int dig[L],dn;
void conv( LL n ) {
    REP(i,L) {
        dig[i]=n%16;
        n/=16;
    }
    dn=L-1;
    while ( dn>0 && dig[dn-1]==0 ) dn--;
}

LL dp[L][16][Z];
LL go( int pos, bool any, int mx, int msk ) {
    // dump(pos,any,mx,msk);
    if ( pos==-1 ) return bit(msk,mx);
    if ( any && dp[pos][mx][msk]!=-1 ) return dp[pos][mx][msk];
    LL ans=0;
    int u=any?15:dig[pos];
    REP1(i,0,u) {
        int nmsk=msk;
        if ( pos<4 ) nmsk|=i<<(pos*4);
        LL now=go(pos-1,any||i<dig[pos],max(mx,i),nmsk);
        ans+=now;
    }
    if ( any ) dp[pos][mx][msk]=ans;
    return ans;
}

LL solve( LL n ) {
    if ( n<=0 ) return 0;
    conv(n);
    LL ans=go(dn-1,0,0,0);
    // LL ans_slow=slow(n);
    // dump(n,ans,ans_slow);
    // assert(ans==ans_slow);
    return ans;
}

int main() {
    memset(dp,-1,sizeof(dp));
    int q;
    R(q);
    while ( q-- ) {
        char sl[L],sr[L];
        R(sl,sr);
        LL l=strtoll(sl,NULL,16);
        LL r=strtoll(sr,NULL,16);
        LL ans=solve(r)-solve(l-1);
        W(ans);
    }
    return 0;
}