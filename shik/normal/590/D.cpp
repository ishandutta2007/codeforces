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
} while (0);

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
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=155;
const int S=N*N/4;
const int INF=1e9;

inline void chkmin( int &a, int b ) {
    if ( b<a ) a=b;
}

int n,m,s,q[N],dp[2][N][S];
int main() {
    RI(n,m,s);
    REP(i,n) RI(q[i]);
    s=min(s,m*(n-m));
    int u=0;
    REP(i,m+1) REP(j,s+1) dp[u][i][j]=INF;
    dp[u][0][0]=0;
    REP(i,n) {
        REP1(j,0,m) REP1(k,0,s) dp[u^1][j][k]=INF;
        REP1(j,0,m) REP1(k,0,s) {
            int me=dp[u][j][k];
            if ( me==INF ) continue;
            chkmin(dp[u^1][j][k],me);
            chkmin(dp[u^1][j+1][k+(i-j)],me+q[i]);
        }
        u^=1;
    }
    int ans=INF;
    REP1(i,0,s) chkmin(ans,dp[u][m][i]);
    printf("%d\n",ans);
    return 0;
}