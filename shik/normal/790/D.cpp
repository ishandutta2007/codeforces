// {{{ by shik
#pragma GCC optimize("O3")
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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

const int N=3e5+10;

void build( int n, int *l, LL *s ) {
    map<LL,int> pre;
    pre[0]=0;
    l[0]=-1;
    REP1(i,1,n) {
        l[i]=l[i-1];
        if ( pre.count(s[i]) ) chkmax(l[i],pre[s[i]]);
        pre[s[i]]=i;
    }
}

int n,lu[N],ld[N],l[N],dp[N];
LL a[2][N],su[N],sd[N],s[N];
int main() {
    R(n);
    REP(i,2) REP1(j,1,n) R(a[i][j]);
    REP1(i,1,n) su[i]=su[i-1]+a[0][i];
    REP1(i,1,n) sd[i]=sd[i-1]+a[1][i];
    REP1(i,1,n) s[i]=su[i]+sd[i];
    build(n,lu,su);
    build(n,ld,sd);
    build(n,l,s);
    REP1(i,1,n) {
        // dump(i);
        int mx=0;
        if ( l[i]!=-1 ) chkmax(mx,dp[l[i]]+1);
        int c=0,ju=i,jd=i;
        while ( 1 ) {
            if ( lu[ju]!=-1 && lu[ju]>=ld[jd] ) {
                c++;
                ju=lu[ju];
            } else if ( ld[jd]!=-1 && ld[jd]>=lu[ju] ) {
                c++;
                jd=ld[jd];
            } else {
                break;
            }
            int now=dp[min(ju,jd)]+c;
            // dump(i,now,mx);
            if ( now<mx ) break;
            // if ( flag ) assert(now<=mx);
            chkmax(mx,now);
        }
        dp[i]=mx;
        // dump(i,lu[i],ld[i],l[i],dp[i]);
    }
    W(dp[n]);
    return 0;
}