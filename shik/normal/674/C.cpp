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

const int N=2e5+10;
const int M=55;
typedef long double Double;

int n,m,t[N];
Double s1[N],s2[N],s3[N];

inline Double w( int l, int r ) {
    Double ans=0;
    ans+=s3[r]-s3[l-1];
    ans-=(s2[r]-s2[l-1])*s1[l-1];
    return ans;
}

Double dp[M][N];
void go( int lv, int l1, int r1, int l2, int r2 ) {
    int m1=(l1+r1)/2;
    int m2=-1,lb=max(lv,l2),rb=min(r2,m1);
    Double mi=1e300;
    REP1(i,lb,rb) {
        Double now=dp[lv-1][i-1]+w(i,m1);
        if ( now<mi ) {
            mi=now;
            m2=i;
        }
    }
    dp[lv][m1]=mi;
    if ( l1<=m1-1 ) go(lv,l1,m1-1,l2,m2);
    if ( m1+1<=r1 ) go(lv,m1+1,r1,m2,r2);
}

int main() {
    R(n,m);
    REP1(i,1,n) R(t[i]);
    REP1(i,1,n) {
        s1[i]=s1[i-1]+t[i];
        s2[i]=s2[i-1]+1.0L/t[i];
        s3[i]=s3[i-1]+s1[i]/t[i];
    }
    // dump(vector<Double>(s1+1,s1+n+1));
    // dump(vector<Double>(s2+1,s2+n+1));
    // dump(vector<Double>(s3+1,s3+n+1));
    // dump(w(1,1),w(2,4));
    REP1(i,1,n) dp[1][i]=w(1,i);
    REP1(i,2,m) go(i,i,n,1,n);
    printf("%.14f\n",(double)dp[m][n]);
    return 0;
}