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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

inline void chkmin( int &a, int b ) {
    if ( b<a ) a=b;
}

const int N=80;
const int INF=1e8;
int n,dp[N][N][N][2];
VI a,b,c;
char s[N];
int main() {
    R(n,s);
    REP(i,n) {
        if ( s[i]=='V' ) a.PB(i);
        else if ( s[i]=='K' ) b.PB(i);
        else c.PB(i);
    }
    // dump(a,b,c);
    REP(i,N) REP(j,N) REP(k,N) REP(v,2) dp[i][j][k][v]=INF;
    dp[0][0][0][0]=0;
    REP(i,SZ(a)+1) REP(j,SZ(b)+1) REP(k,SZ(c)+1) REP(v,2) {
        auto f=[&]( int p ) {
            int cnt=0;
            REP(x,i) if ( a[x]>p ) cnt++;
            REP(x,j) if ( b[x]>p ) cnt++;
            REP(x,k) if ( c[x]>p ) cnt++;
            return cnt;
        };
        int me=dp[i][j][k][v];
        if ( me==INF ) continue;
        if ( i<SZ(a) ) chkmin(dp[i+1][j][k][1],me+f(a[i]));
        if ( j<SZ(b) && v==0 ) chkmin(dp[i][j+1][k][0],me+f(b[j]));
        if ( k<SZ(c) ) chkmin(dp[i][j][k+1][0],me+f(c[k]));
    }
    int ans=min(dp[SZ(a)][SZ(b)][SZ(c)][0],dp[SZ(a)][SZ(b)][SZ(c)][1]);
    W(ans);
    return 0;
}