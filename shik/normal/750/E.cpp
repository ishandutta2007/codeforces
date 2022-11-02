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
const int INF=1e8;

struct P {
    int x[4][4];
    int* operator[]( int i ) { return x[i]; }
    const int* operator[]( int i ) const { return x[i]; }
};

P operator *( const P &a, const P &b ) {
    P c;
    REP(i,4) REP1(j,i,3) {
        int mi=INF;
        REP1(k,i,j) mi=min(mi,a[i][k]+b[k][j]);
        c[i][j]=mi;
    }
    return c;
}

const int idx[10]={1,2,0,-1,-1,-1,3,-1,-1,-1};
struct Seg {
    P t[4*N];
    void init( int id, int l, int r, int a[] ) {
        if ( l==r ) {
            REP(i,4) REP1(j,i,3) t[id][i][j]=(i==j ? 0 : INF);
            int x=idx[a[l]];
            if ( x!=-1 ) {
                t[id][x][x]=1;
                if ( x!=3 ) t[id][x][x+1]=1;
            }
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        t[id]=t[id*2]*t[id*2+1];
    }
    P ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return t[id];
        int m=(l+r)/2;
        if ( qr<=m ) return ask(id*2,l,m,ql,qr);
        else if ( ql>m ) return ask(id*2+1,m+1,r,ql,qr);
        else {
            P pl=ask(id*2,l,m,ql,qr);
            P pr=ask(id*2+1,m+1,r,ql,qr);
            return pl*pr;
        }
    }
} seg;

int n,m,a[N];
VI v[10];

int pre( int d, int x ) {
    auto it=upper_bound(ALL(v[d]),x);
    return *--it;
}

int cnt( int d, int x ) {
    auto it=upper_bound(ALL(v[d]),x);
    return it-v[d].begin()-1;
}

int cnt( int d, int l, int r ) {
    return cnt(d,r)-cnt(d,l-1);
}

int main() {
    static char buf[N];
    R(n,m,buf);
    REP1(i,1,n) a[i]=buf[i-1]-'0';
    REP(i,10) v[i].PB(0);
    REP1(i,1,n) v[a[i]].PB(i);
    seg.init(1,1,n,a);
    // REP(i,4) REP1(j,i,3) dump(i,j,seg.t[1][i][j]);
    while ( m-- ) {
        int l,r;
        R(l,r);
        int x7=pre(7,r);
        if ( x7<l ) {
            W(-1);
            continue;
        }
        int ans=0;
        ans+=cnt(6,x7+1,r);
        // dump(ans);
        P p=seg.ask(1,1,n,l,x7);
        // REP(i,4) REP1(j,i,3) dump(i,j,p[i][j]);
        ans+=p[0][3]-3;
        if ( ans>N ) W(-1);
        else W(ans);
    }
    return 0;
}