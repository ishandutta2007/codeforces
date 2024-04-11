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

const int N=120;
const int INF=1e9;
int n,a[N][5],ac[5];

int ans,fr[5];

int get_score( int t[5] ) {
    int s=0;
    REP(i,5) if ( t[i]!=-1 ) {
        int mx=(fr[i]+1)*500;
        int now=mx-mx/250*t[i];
        s+=now;
    }
    return s;
}

void solve() {
    if ( get_score(a[0])<=get_score(a[1]) ) return;
    int c[5];
    memcpy(c,ac,sizeof(ac));
    int m=n;
    while ( m<5000 ) {
        int l[5],r[5];
        REP(i,5) {
            if ( fr[i]==5 ) l[i]=0;
            else l[i]=(m>>(fr[i]+1))+1;
            r[i]=m>>fr[i];
            // dump(i,fr[i],m,l[i],r[i]);
            // assert(l[i]<=r[i]);
        }
        bool ok=1;
        REP(i,5) ok&=(l[i]<=c[i] && c[i]<=r[i]);
        if ( ok ) {
            ans=min(ans,m-n);
            if ( m-n==ans ) dump(m,m-n,VI(ALL(fr)),VI(ALL(c)),VI(ALL(l)),VI(ALL(r)),get_score(a[0]),get_score(a[1]));
            return;
        }
        REP(i,5) {
            if ( c[i]<r[i] && a[0][i]!=-1 ) c[i]++;
        }
        m++;
    }
}

// 7776
void dfs( int p ) {
    if ( p==5 ) {
        solve();
        return;
    }
    REP(i,6) {
        fr[p]=i;
        dfs(p+1);
    }
}

int main() {
    R(n);
    REP(i,n) REP(j,5) R(a[i][j]);
    REP(i,n) REP(j,5) if ( a[i][j]!=-1 ) ac[j]++;
    ans=INF;
    dfs(0);
    W(ans<INF ? ans : -1);
    return 0;
}