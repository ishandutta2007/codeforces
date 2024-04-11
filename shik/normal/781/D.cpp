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

inline void chkmax( LL &a, LL b ) {
    if ( b>a ) a=b;
}

const int N=512;
const LL INF=2e18;

int n,m;
bool dp[60][2][N][N];
bitset<N> bx[2][N],by[2][N];
LL t[N][2],nt[N][2];
int main() {
    R(n,m);
    REP(i,m) {
        int a,b,c;
        R(a,b,c);
        dp[0][c][a][b]=1;
    }
    REP(d,59) {
        REP(k,2) REP1(i,1,n) REP1(j,1,n) bx[k][i][j]=by[k][j][i]=dp[d][k][i][j];
        REP1(i,1,n) REP1(j,1,n) {
            dp[d+1][0][i][j]=(bx[0][i]&by[1][j]).any();
            dp[d+1][1][i][j]=(bx[1][i]&by[0][j]).any();
        }
        // REP1(i,1,n) REP1(j,1,n) REP1(k,1,n) {
            // dp[d+1][0][i][j]|=dp[d][0][i][k]&&dp[d][1][k][j];
            // dp[d+1][1][i][j]|=dp[d][1][i][k]&&dp[d][0][k][j];
        // }
    }
    REP1(i,1,n) REP(j,2) t[i][j]=-INF;
    t[1][0]=0;
    for ( int d=59; d>=0; d-- ) {
        memcpy(nt,t,sizeof(t));
        REP(k,2) REP1(i,1,n) REP1(j,1,n) if ( dp[d][k][i][j] ) chkmax(nt[j][k^1],t[i][k]+(1LL<<d));
        memcpy(t,nt,sizeof(t));
    }
    LL ans=-INF;
    REP1(i,1,n) REP(j,2) chkmax(ans,t[i][j]);
    if ( ans>1'000'000'000'000'000'000 ) W(-1);
    else W(ans);
    return 0;
}