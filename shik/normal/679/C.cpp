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

const int N=514;
int n,m,a[N][N];
char inp[N][N];

bool in( int x, int y ) {
    return 1<=x&&x<=n && 1<=y&&y<=n;
}

bool vis[N][N];
int cid[N][N],nc,csz[N*N];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
void BFS( int x, int y ) {
    nc++;
    queue<int> q;
    auto push=[&]( int nx, int ny ) {
        vis[nx][ny]=1;
        cid[nx][ny]=nc;
        q.push(nx);
        q.push(ny);
    };
    push(x,y);
    while ( !q.empty() ) {
        x=q.front(); q.pop();
        y=q.front(); q.pop();
        REP(i,4) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( !in(nx,ny) || a[nx][ny] || vis[nx][ny] ) continue;
            push(nx,ny);
        }
    }
}

int ci[N*N],cb[N*N],ssz,sci;
inline void add_i( int x ) {
    if ( ci[x]+cb[x]==0 ) ssz+=csz[x];
    ci[x]++;
    sci++;
}
inline void add_b( int x ) {
    if ( ci[x]+cb[x]==0 ) ssz+=csz[x];
    cb[x]++;
}
inline void del_i( int x ) {
    ci[x]--;
    sci--;
    if ( ci[x]+cb[x]==0 ) ssz-=csz[x];
}
inline void del_b( int x ) {
    cb[x]--;
    if ( ci[x]+cb[x]==0 ) ssz-=csz[x];
}
inline void clear() {
    memset(ci,0,sizeof(ci));
    memset(cb,0,sizeof(cb));
    ssz=sci=0;
}

#define WRAP(f) inline void f( int x, int y ) { if ( cid[x][y] ) f(cid[x][y]); }
WRAP(add_i)
WRAP(add_b)
WRAP(del_i)
WRAP(del_b)

int main() {
    R(n,m);
    REP1(i,1,n) scanf("%s",inp[i]+1);
    REP1(i,1,n) REP1(j,1,n) a[i][j]=(inp[i][j]=='X');
    REP1(i,1,n) REP1(j,1,n) if ( !a[i][j] && !vis[i][j] ) BFS(i,j);
    REP1(i,1,n) REP1(j,1,n) if ( !a[i][j] ) csz[cid[i][j]]++;
    int ans=0;
    auto upd=[&]( int x, int y ) {
        int s=m*m+ssz-sci;
        dump(x,y,ssz,sci,s);
        ans=max(s,ans);
    };
    REP1(i,1,n-m+1) {
        REP1(j,1,n-m+1) {
            if ( j==1 ) {
                clear();
                REP(x,m) REP1(y,1,m) add_i(i+x,y);
                if ( i-1>=1 ) REP1(k,1,m) add_b(i-1,k);
                if ( i+m<=n ) REP1(k,1,m) add_b(i+m,k);
                if ( m+1<=n ) REP(k,m) add_b(i+k,m+1);
            } else {
                REP(k,m) del_b(i+k,j+m-1);
                REP(k,m) add_i(i+k,j+m-1);
                if ( j+m<=n ) REP(k,m) add_b(i+k,j+m);
                if ( i-1>=1 ) add_b(i-1,j+m-1);
                if ( i+m<=n ) add_b(i+m,j+m-1);
            }
            upd(i,j);
            if ( j-1>=1 ) REP(k,m) del_b(i+k,j-1);
            REP(k,m) del_i(i+k,j);
            REP(k,m) add_b(i+k,j);
            if ( i-1>=1 ) del_b(i-1,j);
            if ( i+m<=n ) del_b(i+m,j);
        }
    }
    W(ans);
    return 0;
}