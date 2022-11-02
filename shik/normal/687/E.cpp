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

const int N=5140;

struct SCC {
    int n;
    vector<vector<int>> e1,e2,scc;
    vector<int> vis,ord;
    void init( int _n ) {
        n=_n;
        e1.resize(n+1);
        e2.resize(n+1);
        REP1(i,1,n) {
            e1[i].clear();
            e2[i].clear();
        }
    }
    void add( int a, int b ) {
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    void dfs1( int u ) {
        vis[u]=1;
        for ( int v:e1[u] ) if ( vis[v]==0 ) dfs1(v);
        ord.push_back(u);
    }
    void dfs2( int u ) {
        vis[u]=2;
        scc.back().push_back(u);
        for ( int v:e2[u] ) if ( vis[v]==1 ) dfs2(v);
    }
    void solve() {
        vis.clear();
        vis.resize(n+1);
        ord.clear();
        ord.reserve(n+1);
        REP1(i,1,n) if ( vis[i]==0 ) dfs1(i);
        reverse(ALL(ord));
        scc.clear();
        for ( int i:ord ) if ( vis[i]==1 ) {
            scc.emplace_back();
            dfs2(i);
        }
    }
} scc;

// VI nei[N];
// int cnt[N];
// bool vis[N];
// void dfs( int v ) {
    // cnt[v]++;
    // if ( cnt[v]<1000 ) {
        // for ( int u:nei[v] ) {
            // if ( !vis[u] ) dfs(u);
            // break;
        // }
    // }
    // vis[v]=1;
// }

int n,m;
VI e[N];

void BFS( int st, int d[N] ) {
    int ql=0,qr=0,q[N];
    REP1(i,1,n) d[i]=N;
    d[st]=0;
    q[qr++]=st;
    while ( ql!=qr ) {
        int p=q[ql++];
        for ( int i:e[p] ) if ( d[i]==N ) {
            d[i]=d[p]+1;
            q[qr++]=i;
        }
    }
}

int dis[N][N],mc[N];
bool done[N];

int main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
    }
    REP1(i,1,n) BFS(i,dis[i]);
    REP1(i,1,n) mc[i]=N;
    REP1(i,1,n) REP1(j,i+1,n) {
        int now=dis[i][j]+dis[j][i];
        mc[i]=min(mc[i],now);
        mc[j]=min(mc[j],now);
    }
    scc.init(n);
    REP1(i,1,n) for ( int j:e[i] ) scc.add(i,j);
    scc.solve();
    reverse(ALL(scc.scc));
    int ans=0;
    for ( auto v:scc.scc ) {
        dump(v);
        ans+=SZ(v);
        bool ok=0;
        for ( int i:v ) {
            if ( e[i].empty() ) ok=1;
            for ( int j:e[i] ) if ( done[j] ) ok=1;
        }
        if ( !ok ) {
            int mi=N;
            for ( int i:v ) mi=min(mi,mc[i]);
            ans+=998*mi+1;
        }
        for ( int i:v ) done[i]=1;
    }
    W(ans);
    // REP1(i,1,n) nei[i]=e[i];
    // REP1(i,1,n) if ( !vis[i] ) dfs(i);
    // int sc=0;
    // REP1(i,1,n) sc+=cnt[i];
    // dump(sc);
    return 0;
}