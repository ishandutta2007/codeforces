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

#define L 15
const int MOD=1e9+7;

inline LL inv( int x ) { return x==1?1:inv(MOD%x)*(MOD-MOD/x)%MOD; }
LL C( int n, int m ) {
    if ( m>n ) return 0;
    LL ret=1;
    REP(i,m) {
        ret=ret*(n-i)%MOD;
        ret=ret*inv(i+1)%MOD;
    }
    return ret;
}

int n,dig[L],dp[L][2][L],dp2[L][7][L];
int main() {
    RI(n);
    int len=0;
    while ( n ) {
        dig[len++]=n%10;
        n/=10;
    }
    dp[len][0][0]=1;
    for ( int i=len-1; i>=0; i-- ) REP(j,2) REP(k,10) {
        int me=dp[i+1][j][k];
        REP(d,10) if ( d<=dig[i] || j==1 ) {
            int nj=j||d<dig[i];
            int nk=k+(d==4||d==7);
            dp[i][nj][nk]+=me;
        }
    }
    REP(i,7) dp2[0][i][0]=C(dp[0][0][0]+dp[0][1][0]-1,i);
    LL ans=0;
    REP1(i,1,9) {
        int t=dp[0][0][i]+dp[0][1][i];
        REP(j,7) REP(k,10) for ( int l=0; l<=j && i*l<=k; l++ ) 
            dp2[i][j][k]=(dp2[i][j][k]+dp2[i-1][j-l][k-i*l]*C(t,l))%MOD;
        REP(j,i) ans+=1LL*t*dp2[i][6][j]%MOD;
    }
    printf("%d\n",(int)(ans*2*3*4*5*6%MOD));
    return 0;
}