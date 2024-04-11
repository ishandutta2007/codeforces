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

struct MCMF {
    struct E { int to,c,w,r; };

    int n;
    vector<vector<E>> e;
    vector<vector<E>::iterator> cur;
    vector<int> dis;
    vector<char> vis;
    
    void init( int _n ) {
        n=_n;
        e.resize(n);
        for ( int i=0; i<n; i++ ) e[i].clear();
        cur.resize(n);
        dis.resize(n);
        vis.resize(n);
    }
    
    void add( int a, int b, int c, int w ) {
        dump(a,b,c,w);
        e[a].push_back({b,c,w,(int)e[b].size()});
        e[b].push_back({a,0,-w,(int)e[a].size()-1});
    }
    
    int aug( int u, int f ) {
        if ( u==n-1 ) return f;
        vis[u]=1;
        int ret=0;
        for ( auto &it=cur[u]; it!=e[u].end(); it++ ) if ( it->c>0 ) {
            int v=it->to;
            if ( vis[v] || dis[u]!=dis[v]+it->w ) continue;
            int tf=aug(v,min(f-ret,it->c));
            ret+=tf;
            it->c-=tf;
            e[v][it->r].c+=tf;
            if ( ret==f ) break;
        }
        return ret;
    }
    
    bool relabel() {
        int d=INT_MAX;
        for ( int u=0; u<n; u++ ) if ( vis[u] )
            for ( auto &i:e[u] ) if ( i.c>0 && !vis[i.to] ) d=min(d,dis[i.to]+i.w-dis[u]);
        if ( d==INT_MAX ) return 0;
        for ( int i=0; i<n; i++ ) if ( vis[i] ) dis[i]+=d;
        return 1;
    }
    
    pair<long long,int> mcmf( int mf ) {
        long long w=0;
        int f=0;
        fill(dis.begin(),dis.end(),0);
        do {
            for ( int i=0; i<n; i++ ) cur[i]=e[i].begin();
            while ( 1 ) {
                fill(vis.begin(),vis.end(),0);
                int tf=aug(0,INT_MAX);
                if ( tf==0 ) break;
                dump(dis[0]);
                w+=1LL*tf*dis[0];
                f+=tf;
            }
        } while ( f!=mf && relabel() );
        return {w,f};
    }
} mcmf;

const int N=2222;
int n,k,a[N],b[N];
int main() {
    R(n,k);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) R(b[i]);
    int sink=n+1;
    mcmf.init(sink+1);
    REP1(i,1,n) mcmf.add(0,i,1,a[i]);
    REP1(i,1,n-1) mcmf.add(i,i+1,N,0);
    REP1(i,1,n) mcmf.add(i,sink,1,b[i]);
    auto wf=mcmf.mcmf(k);
    dump(wf);
    W(wf.first);
    return 0;
}