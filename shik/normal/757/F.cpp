// {{{ by shik
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
const LL INF=1e18;

struct E {
    int to,len;
};

int n,m,st;
vector<E> e[N];
void input() {
    R(n,m,st);
    REP(i,m) {
        int a,b,c;
        R(a,b,c);
        e[a].PB({b,c});
        e[b].PB({a,c});
    }
}

LL dis[N];
void dijkstra() {
    REP1(i,1,n) dis[i]=INF;
    priority_queue<pair<LL,int>> q;
    dis[st]=0;
    q.push({0,st});
    while ( !q.empty() ) {
        int p=q.top().second;
        LL d=-q.top().first;
        q.pop();
        if ( dis[p]!=d ) continue;
        for ( auto i:e[p] ) {
            LL nd=dis[p]+i.len;
            if ( nd<dis[i.to] ) {
                dis[i.to]=nd;
                q.push({-nd,i.to});
            }
        }
    }
    REP1(i,1,n) dump(i,dis[i]);
}

VI e1[N],e2[N];
void build_dag() {
    REP1(i,1,n) if ( dis[i]!=INF ) {
        for ( auto j:e[i] ) if ( dis[i]+j.len==dis[j.to] ) {
            dump(i,j.to,j.len);
            e1[i].PB(j.to);
            e2[j.to].PB(i);
        }
    }
}

VI topo;
void topo_sort() {
    static int deg[N];
    REP1(i,1,n) deg[i]=SZ(e2[i]);
    queue<int> q;
    REP1(i,1,n) if ( dis[i]!=INF && deg[i]==0 ) q.push(i);
    while ( !q.empty() ) {
        int p=q.front(); q.pop();
        topo.PB(p);
        for ( int i:e1[p] ) if ( --deg[i]==0 ) q.push(i);
    }
    dump(topo);
}

int dep[N],fa[N][18];
inline int bit( int x, int i ) { return (x>>i)&1; }
int lca( int a, int b ) {
    if ( dep[a]>dep[b] ) swap(a,b);
    REP(i,18) if ( bit(dep[b]-dep[a],i) ) b=fa[b][i];
    if ( a==b ) return a;
    for ( int i=17; i>=0; i-- ) if ( fa[a][i]!=fa[b][i] ) a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}

int sz[N];
void solve() {
    for ( int i:topo ) {
        if ( e2[i].empty() ) {
            assert(i==st);
            dep[i]=1;
            continue;
        }
        int f=e2[i][0];
        for ( int j:e2[i] ) f=lca(f,j);
        dump(i,f);
        dep[i]=dep[f]+1;
        fa[i][0]=f;
        REP(j,17) fa[i][j+1]=fa[fa[i][j]][j];
    }
    int ans=0;
    reverse(ALL(topo));
    for ( int i:topo ) {
        sz[i]++;
        sz[fa[i][0]]+=sz[i];
        dump(i,sz[i]);
        if ( i!=st ) ans=max(ans,sz[i]);
    }
    W(ans);
}

int main() {
    input();
    dijkstra();
    build_dag();
    topo_sort();
    solve();
    return 0;
}