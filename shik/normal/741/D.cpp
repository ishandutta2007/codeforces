// {{{ by shik
#ifndef YCM
#pragma GCC optimize("O3")
#endif
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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

const int N=5e5+10;

int n,fa[N],fc[N],sz[N],dep[N],val[N];
VI e[N];
bool cmp( int x, int y ) {
    return sz[x]<sz[y];
}

int st[N],ed[N],ord[N],ts;
void dfs( int p ) {
    st[p]=++ts;
    ord[ts]=p;
    for ( int i:e[p] ) dfs(i);
    ed[p]=ts;
}

multiset<int> dat[1<<22];
int dmx[1<<22];
void ins( int x, int v ) {
    // dump(x,v);
    dat[x].insert(v);
    chkmax(dmx[x],v);
}
void del( int x, int v ) {
    // dump(x,v);
    dat[x].erase(dat[x].find(v));
    if ( v==dmx[x] ) dmx[x]=dat[x].empty() ? -N : *dat[x].rbegin();
}
int ask( int x ) {
    int mx=dmx[x];
    REP(i,22) chkmax(mx,dmx[x^(1<<i)]);
    return mx;
}

int a[N],b[N];

void ins_tree( int p ) {
    REP1(i,st[p],ed[p]) ins(a[i],b[i]);
}

void del_tree( int p ) {
    REP1(i,st[p],ed[p]) del(a[i],b[i]);
}

int ask_tree( int p ) {
    int mx=-N;
    REP1(i,st[p],ed[p]) {
        int now=ask(a[i]);
        chkmax(mx,now+b[i]);
    }
    return mx;
}

int dp[N];
void go( int p ) {
    // dump(p);
    if ( e[p].empty() ) {
        ins(val[p],dep[p]);
        return;
    }
    int last=e[p].back();
    for ( int i:e[p] ) {
        go(i);
        chkmax(dp[p],dp[i]);
        if ( i!=last ) del_tree(i);
    }
    int mx=-N;
    for ( int i:e[p] ) if ( i!=last ) {
        chkmax(mx,ask_tree(i));
        ins_tree(i);
    }
    chkmax(mx,ask(val[p])+dep[p]);
    ins(val[p],dep[p]);
    chkmax(dp[p],mx-2*dep[p]);
}

int main() {
    R(n);
    // n=500000;
    REP1(i,2,n) {
        int p;
        char c;
        R(p,c);
        // p=i/2;
        // c=rand()%22+'a';
        fa[i]=p;
        fc[i]=c-'a';
        e[p].PB(i);
    }
    for ( int i=n; i>=1; i-- ) {
        sz[i]++;
        sz[fa[i]]+=sz[i];
    }
    REP1(i,1,n) dep[i]=dep[fa[i]]+1;
    REP1(i,2,n) val[i]=val[fa[i]]^(1<<fc[i]);
    REP1(i,1,n) sort(ALL(e[i]),cmp);
    dfs(1);
    REP1(i,1,n) {
        a[i]=val[ord[i]];
        b[i]=dep[ord[i]];
    }
    // REP1(i,1,n) dump(i,sz[i],dep[i],val[i],st[i],ed[i],a[i],b[i]);
    REP(i,1<<22) dmx[i]=-N;
    go(1);
    REP1(i,1,n) printf("%d%c",dp[i],i==n?'\n':' ');
    fflush(stdout);
    _Exit(0);
    return 0;
}