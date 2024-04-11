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

const LL U=1e14;
const LL INF=1e18;

struct Maxflow {
    struct E {
        int id;
        int to;
        LL cap;
        int rev;
        E() {}
        E( int _id, int _to, LL _cap, int _rev ):id(_id),to(_to),cap(_cap),rev(_rev) {}
    };
    int n;
    vector< vector<E> > e;
    vector< vector<E>::iterator > cur;
    vector<int> dis;
    void init( int _n ) {
        n=_n;
        e.resize(n);
        cur.resize(n);
        dis.resize(n);
        REP(i,n) e[i].clear();
    }
    void add( int id, int a, int b, LL c ) {
        if ( a==b ) return;
        e[a].PB(E(id,b,c,e[b].size()));
        e[b].PB(E(id,a,c,e[a].size()-1));
    }
    bool bfs() {
        fill(dis.begin(),dis.end(),-1);
        queue<int> q;
        dis[0]=0; q.push(0);
        while ( !q.empty() && dis[n-1]==-1 ) {
            int p=q.front(); q.pop();
            FOR(it,e[p]) {
                if ( it->cap==0 || dis[it->to]!=-1 ) continue;
                dis[it->to]=dis[p]+1;
                q.push(it->to);
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0;
        for ( auto &it=cur[p]; it!=e[p].end(); it++ ) {
            if ( it->cap==0 || dis[it->to]!=dis[p]+1 ) continue;
            LL now=go(it->to,min(it->cap,c-ret));
            ret+=now;
            it->cap-=now;
            e[it->to][it->rev].cap+=now;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow( LL ub ) {
        LL ret=0;
        while ( ret<=ub && bfs() ) {
            REP(i,n) cur[i]=e[i].begin();
            ret+=go(0,INF);
        }
        return ret;
    }
    VI get_cut() {
        assert(!bfs());
        VI cut;
        REP(a,n) if ( dis[a]!=-1 ) for ( auto &j:e[a] ) {
            int b=j.to;
            if ( dis[b]==-1 ) cut.PB(j.id);
        }
        return cut;
    }
} flow;

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

const int M=30010;

struct E {
    int a,b,c;
} e[M];

int n,m,st,ed;
bool span[M];

int min_cut() {
    int sink=n+1;
    flow.init(sink+1);
    flow.add(-1,0,st,INF);
    flow.add(-1,ed,sink,INF);
    REP(i,m) flow.add(i,e[i].a,e[i].b,1);
    LL f=flow.maxflow(3);
    return f;
}

bool conn( int ban ) {
    djs.init(n);
    REP(i,m) if ( i!=ban ) {
        int a=e[i].a,b=e[i].b;
        if ( djs.f(a)==djs.f(b) ) continue;
        djs.u(a,b);
        if ( djs.f(st)==djs.f(ed) ) return 1;
    }
    return 0;
}

int main() {
    R(n,m,st,ed);
    REP(i,m) R(e[i].a,e[i].b,e[i].c);

    int mc=min_cut();

    if ( mc==0 ) {
        W(0);
        W(0);
        W("");
        return 0;
    }

    if ( mc>2 ) {
        W(-1);
        return 0;
    }

    djs.init(n);
    REP(i,m) {
        int a=e[i].a,b=e[i].b;
        if ( djs.f(a)==djs.f(b) ) continue;
        span[i]=1;
        djs.u(a,b);
    }

    int sink=n+1;
    flow.init(sink+1);
    flow.add(-1,0,st,INF);
    flow.add(-1,ed,sink,INF);

    LL ans=INF;
    VI sol;
    REP(i,m) {
        if ( !span[i] || conn(i) ) {
            flow.add(i,e[i].a,e[i].b,U+e[i].c);
        } else {
            flow.add(i,e[i].a,e[i].b,INF);
            if ( e[i].c<ans ) {
                ans=e[i].c;
                sol=VI{i};
            }
        }
    }
    LL f=flow.maxflow(3*U);
    dump(f);
    if ( f/U==2 ) {
        LL now=f%U;
        if ( now<ans ) {
            ans=now;
            sol=flow.get_cut();
        }
    }

    for ( auto &i:sol ) i++;

    W(ans);
    W(SZ(sol));
    W(sol);
    return 0;
}