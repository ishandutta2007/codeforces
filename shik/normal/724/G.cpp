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

inline int bit( LL x, int i ) {
    return (x>>i)&1;
}

const int N=1e5+10;
const int M=2e5+10;
const LL MOD=1e9+7;

LL pw2[100];
void predo() {
    pw2[0]=1;
    REP(i,99) pw2[i+1]=2*pw2[i]%MOD;
}

struct E {
    int a,b;
    LL c;
} e[M];

int n,m;
VI es[N];

int cc[N],cn;
LL v[N];
void go( int p, LL x ) {
    cc[p]=cn;
    v[p]=x;
    for ( int i:es[p] ) {
        int to=p^e[i].a^e[i].b;
        if ( v[to]!=-1 ) continue;
        go(to,x^e[i].c);
    }
}

VI cv[N],ce[M];

int main() {
    predo();
    R(n,m);
    REP(i,m) R(e[i].a,e[i].b,e[i].c);
    REP(i,m) {
        es[e[i].a].PB(i);
        es[e[i].b].PB(i);
    }
    REP1(i,1,n) v[i]=-1;
    REP1(i,1,n) if ( v[i]==-1 ) {
        cn++;
        go(i,0);
    }
    REP1(i,1,n) cv[cc[i]].PB(i);
    REP(i,m) {
        assert(cc[e[i].a]==cc[e[i].b]);
        ce[cc[e[i].a]].PB(i);
    }
    LL ans=0;
    REP1(ci,1,cn) {
        LL bv[60][2]={};
        for ( int i:cv[ci] ) REP(j,60) bv[j][bit(v[i],j)]++;
        vector<LL> a;
        for ( int i:ce[ci] ) {
            LL x=e[i].c^v[e[i].a]^v[e[i].b];
            if ( x!=0 ) a.PB(x);
        }
        // dump(ci,a);
        int rk=0;
        REP(i,60) {
            REP1(j,rk,SZ(a)-1) if ( bit(a[j],i) ) {
                swap(a[rk],a[j]);
                break;
            }
            if ( rk==SZ(a) || !bit(a[rk],i) ) continue;
            REP1(j,rk+1,SZ(a)-1) if ( bit(a[j],i) ) a[j]^=a[rk];
            rk++;
        }
        a.resize(rk);
        // dump(ci,a);
        LL be[60][2]={};
        for ( LL i:a ) REP(j,60) be[j][bit(i,j)]++;
        REP(i,60) {
            LL c=0;
            LL v0=(bv[i][0]*(bv[i][0]-1)/2+bv[i][1]*(bv[i][1]-1)/2)%MOD;
            LL v1=bv[i][0]*bv[i][1]%MOD;
            if ( be[i][1]==0 ) {
                c+=v1*pw2[rk]%MOD;
            } else {
                assert(rk>0);
                c+=v0*pw2[rk-1]%MOD;
                c+=v1*pw2[rk-1]%MOD;
            }
            // if ( c>0 ) dump(i,c,c*pw2[i]);
            ans+=c*pw2[i]%MOD;
        }
    }
    ans%=MOD;
    W(ans);
    return 0;
}