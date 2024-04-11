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

const int N=110;

void mul( int z, int a[N][N], int b[N][N], int c[N][N] ) {
    static int _c[N][N];
    REP1(i,1,z) REP1(j,i,z) {
        int mx=0;
        REP1(k,i,j) mx=max(mx,a[i][k]+b[k][j]);
        _c[i][j]=mx;
    }
    REP1(i,1,z) REP1(j,i,z) c[i][j]=_c[i][j];
}

int n,m,z,a[N],_a[N],b[N][N],c[N][N];
int main() {
    RI(n,m);
    REP(i,n) RI(a[i]);
    REP(i,n) _a[i]=a[i];
    sort(_a,_a+n);
    int z=unique(_a,_a+n)-_a;
    REP(i,n) a[i]=lower_bound(_a,_a+z,a[i])-_a+1;
    REP1(i,1,z) {
        int dp[N]={};
        REP(j,n) {
            int mx=0;
            for ( int k=i; k<=a[j]; k++ ) mx=max(mx,dp[k]+1);
            dp[a[j]]=mx;
        }
        REP1(j,i+1,z) dp[j]=max(dp[j],dp[j-1]);
        REP1(j,1,z) b[i][j]=dp[j];
        dump(i,VI(b[i]+1,b[i]+z+1));
    }
    while ( m ) {
        if ( m&1 ) mul(z,c,b,c);
        m>>=1;
        mul(z,b,b,b);
    }
    REP1(i,1,z) dump(i,VI(c[i]+1,c[i]+z+1));
    int ans=c[1][z];
    printf("%d\n",ans);
    return 0;
}