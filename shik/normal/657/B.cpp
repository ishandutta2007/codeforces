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

const LL P[]={2213823697,2062562767,2240860157,2394503777,2258256673,2440789333,2358462233,2104107451,2492388911,2338398607};
const int N=2e5+10;
const int NP=sizeof(P)/sizeof(P[0]);
const LL magic=1LL<<50;

LL pw( LL a, LL b, LL m ) {
    LL r=1;
    while ( b ) {
        if ( b&1 ) r=r*a%m;
        a=a*a%m;
        b>>=1;
    }
    return r;
}

LL inv( LL x, LL m ) {
    return pw(x,m-2,m);
}

int n,k,a[N];
LL i2[NP],p2[NP][N],ip2[NP][N],s[NP];
int main() {
    R(n,k);
    REP1(i,0,n) R(a[i]);
    REP(i,NP) {
        i2[i]=inv(2,P[i]);
        p2[i][0]=1;
        REP(j,n) p2[i][j+1]=p2[i][j]*2%P[i];
        ip2[i][0]=1;
        REP(j,n) ip2[i][j+1]=ip2[i][j]*i2[i]%P[i];
    }
    REP(i,NP) {
        REP1(j,0,n) s[i]+=a[j]*p2[i][j]%P[i];
        s[i]=(s[i]%P[i]+P[i])%P[i];
    }
    int ans=0;
    REP1(i,0,n) {
        bool ok=1;
        LL tar=magic;
        REP(j,NP) {
            LL ns=((s[j]-a[i]*p2[j][i])%P[j]+P[j])%P[j];
            LL x=(ns==0 ? 0 : ip2[j][i]*(P[j]-ns)%P[j]);
            if ( x>k ) x-=P[j];
            if ( x<-k ) ok=0;
            // dump(i,j,s[j],ns,x);
            if ( i==n && x==0 ) ok=0;
            if ( tar==magic ) tar=x;
            if ( tar!=x ) ok=0;
            if ( !ok ) break;
        }
        if ( ok ) ans++;
    }
    W(ans);
    return 0;
}