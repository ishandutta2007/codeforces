// {{{ by shik
// #include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
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
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
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

template<typename T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<typename T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<typename T, typename F>
inline void sort_uniq( vector<T> &v, F f ) {
    sort(ALL(v),f);
    v.resize(unqiue(ALL(v))-v.begin());
}

template<typename T> using MaxHeap = priority_queue<T>;
template<typename T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif
// }}}

struct DJS {
    vector<int> fa,sz;
    void init( int n ) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for ( int i=0; i<n; i++ ) sz[fa[i]=i]=1;
    }
    int f( int x ) {
        return x==fa[x]?x:fa[x]=f(fa[x]);
    }
    void u( int a, int b ) {
        a=f(a); b=f(b);
        if ( a==b ) return;
        if ( sz[a]>sz[b] ) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
    }
} djs;

const int N=2e5+10;
const int L=18;
const int M=2e5+10;
const int INF=1e9+10;

struct E {
    int id,a,b,c;
} e[M];

bool operator <( const E &a, const E &b ) { return a.c<b.c; }

int n,m;
VI te[N];

int dep[N],fa[L][N],ex[N];
void dfs( int p, int f, int lv ) {
    dep[p]=lv;
    fa[0][p]=f;
    for ( int i:te[p] ) if ( i!=ex[p] ) {
        int to=p^e[i].a^e[i].b;
        ex[to]=i;
        dfs(to,p,lv+1);
    }
}
constexpr int lg2( int x ) { return 31-__builtin_clz(x); }
inline int bit( int x, int i ) { return (x>>i)&1; }

int lgn;
void lca_build() {
    for (int i = 0; i < lgn; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i + 1][j] = fa[i][fa[i][j]];
        }
    }
}

int mi[L][N];
int lca(int a, int b, int &val) {
    val = -1;
    if (dep[a] > dep[b]) swap(a, b);
    int d = dep[b] - dep[a];
    for (int i = 0; i <= lgn; i++) {
        if ((d >> i) & 1) {
            dump(i, b, mi[i][b]);
            chkmax(val, mi[i][b]);
            b = fa[i][b];
        }
    }
    if (a == b) return a;
    for (int i = lgn; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            chkmax(val, mi[i][a]);
            chkmax(val, mi[i][b]);
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    chkmax(val, mi[0][a]);
    chkmax(val, mi[0][b]);
    return fa[0][a];
}

bool ont[M];

int tag[L][N];
void mark( int p, int d, int v ) {
    REP1(i,0,lgn) if ( bit(d,i) ) {
        chkmin(tag[i][p],v);
        p=fa[i][p];
    }
}

bool chk( int x, int mid ) {
    djs.init(n);
    REP(i,m) {
        if ( i==x ) continue;
        if ( e[i].c>mid ) break;
        djs.u(e[i].a,e[i].b);
    }
    return djs.f(e[x].a)!=djs.f(e[x].b);
}

int sol[N];
void naive() {
    REP(i,m) {
        int l=0,r=INF;
        while ( l!=r ) {
            int mid=(l+r+1)/2;
            if ( chk(i,mid) ) l=mid;
            else r=mid-1;
        }
        if ( sol[e[i].id]!=l && ((l>=INF) != (sol[e[i].id]>=INF)) ) {
            dump(e[i].id,l,sol[e[i].id]);
            assert(0);
        }
    }
}

int main() {
    R(n,m);
    REP(i,m) R(e[i].a,e[i].b,e[i].c);
    REP(i,m) e[i].id=i;
    sort(e,e+m);
    djs.init(n);
    REP(i,m) {
        int a=e[i].a;
        int b=e[i].b;
        if ( djs.f(a)==djs.f(b) ) continue;
        dump(a,b);
        te[a].PB(i);
        te[b].PB(i);
        djs.u(a,b);
    }
    ex[1]=-1;
    dfs(1,0,1);
    lgn=lg2(n);
    lca_build();
    REP1(i,2,n) mi[0][i]=e[ex[i]].c;
    REP(i,lgn) REP1(j,1,n) mi[i+1][j]=max(mi[i][j],mi[i][fa[i][j]]);
    memset(tag,0x3f,sizeof(tag));
    REP1(i,2,n) ont[ex[i]]=1;
    REP(i,m) if ( !ont[i] ) {
        int a=e[i].a;
        int b=e[i].b;
        int c=e[i].c;
        int v;
        int p=lca(a,b,v);
        dump(a,b,p,v);
        sol[e[i].id]=v-1;
        mark(a,dep[a]-dep[p],c);
        mark(b,dep[b]-dep[p],c);
    }
    for ( int i=lgn; i>=1; i-- ) {
        REP1(j,1,n) {
            chkmin(tag[i-1][j],tag[i][j]);
            chkmin(tag[i-1][fa[i-1][j]],tag[i][j]);
        }
    }
    REP1(i,2,n) sol[e[ex[i]].id]=tag[0][i]-1;
    REP(i,m) {
        int ans=(sol[i]<INF ? sol[i] : -1);
        printf("%d%c",ans,i+1==m?'\n':' ');
    }
#ifdef SHIK
    naive();
#endif
    return 0;
}