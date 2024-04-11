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

inline void chkmax( LL &a, LL b ) {
    if ( b>a ) a=b;
}

const int N=210;
const int T=41000;
const LL INF=4e18+10;

int n,a[N];
LL l;
char s[N][N];

map<string,int> nodes;
void ins( string t ) {
    if ( nodes.count(t) ) return;
    int id=SZ(nodes);
    nodes[t]=id;
}

int get_score( string t ) {
    int sc=0;
    REP(i,n) {
        int len=strlen(s[i]);
        if ( len>SZ(t) ) continue;
        if ( strcmp(s[i],t.data()+SZ(t)-len)==0 ) sc+=a[i];
    }
    // dump(t,sc);
    return sc;
}

int get_fail( string t ) {
    while ( !nodes.count(t) ) t=t.substr(1);
    return nodes[t];
}

int m,b[N];
VI e[N];
string ns[N];
void build_ac() {
    ins("");
    REP(i,n) {
        int len=strlen(s[i]);
        REP1(j,1,len) ins(string(s[i],s[i]+j));
    }
    m=SZ(nodes);
    // dump(nodes);
    for ( auto i:nodes ) {
        ns[i.second]=i.first;
        b[i.second]=get_score(i.first);
        for ( char c='a'; c<='z'; c++ ) e[i.second].PB(get_fail(i.first+c));
    }
    REP(i,m) {
        sort(ALL(e[i]));
        e[i].erase(unique(ALL(e[i])),e[i].end());
    }
    // REP(i,m) dump(i,ns[i],e[i]);
}

LL dp1[T][N],dp2[T][N];
VI e1[N],e2[N];
void build_dp() {
    REP(i,m) e1[i]=e[i];
    REP(i,T) REP(j,m) dp1[0][i]=-INF;
    dp1[0][0]=0;
    REP(i,T-1) REP(j,m) for ( int k:e1[j] ) chkmax(dp1[i+1][k],dp1[i][j]+b[k]);
    
    REP(i,m) for ( int j:e[i] ) e2[j].PB(i);
    REP(i,T-1) REP(j,m) for ( int k:e2[j] ) chkmax(dp2[i+1][k],dp2[i][j]+b[j]);
}


void build_cyc( int st, LL &cv, LL &cl ) {
    static LL dp[N][N];
    cv=cl=-1;
    REP(i,m+1) REP(j,m) dp[i][j]=-INF;
    dp[0][st]=0;
    REP(i,m) REP(j,m) for ( int k:e[j] ) chkmax(dp[i+1][k],dp[i][j]+b[k]);
    REP1(i,1,m) {
        LL tv=dp[i][st];
        LL tl=i;
        if ( tv<=0 ) continue;
        // tv/tl > cv/cl
        if ( cv==-1 || tv*cl > cv*tl ) {
            cv=tv;
            cl=tl;
        }
    }
}

LL cv[N],cl[N];
void build_cyc() {
    REP(i,m) build_cyc(i,cv[i],cl[i]);
    // REP(i,m) dump(i,cv[i],cl[i]);
}

int main() {
    R(n,l);
    REP(i,n) R(a[i]);
    REP(i,n) R(s[i]);
    build_ac();
    build_dp();
    build_cyc();
    LL ans=0;
    if ( l<T ) {
        REP(i,m) chkmax(ans,dp1[l][i]);
    } else {
        REP(i,T) REP(j,m) if ( cv[j]!=-1 ) {
            LL now=0;
            now+=dp1[i][j];
            LL q=(l-i)/cl[j];
            LL r=(l-i)%cl[j];
            LL z=(min(T-1LL,l)-r)/cl[j];
            r+=z*cl[j];
            q-=z;
            now+=q*cv[j];
            now+=dp2[r][j];
            chkmax(ans,now);
        }
    }
    W(ans);
    return 0;
}