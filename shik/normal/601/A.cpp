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
} while (0);

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

// }}}

const int N=410;

int n,m,dis[N][N][2];
bool e[N][N],vis[N][N][2];

int main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a][b]=e[b][a]=1;
    }
    queue<int> q;
    auto push=[&]( int x, int y, int z, int d ) {
        if ( x==y && x!=n && d!=0 ) return;
        if ( vis[x][y][z]++ ) return;
        dis[x][y][z]=d;
        q.push(x);
        q.push(y);
        q.push(z);
    };
    push(1,1,0,0);
    while ( !q.empty() ) {
        int x=q.front(); q.pop();
        int y=q.front(); q.pop();
        int z=q.front(); q.pop();
        int d=dis[x][y][z];
        if ( z==0 ) {
            if ( x==n ) push(x,y,z^1,d+1);
            REP1(i,1,n) if ( i!=x && e[x][i]==1 ) push(i,y,z^1,d+1);
        } else {
            if ( y==n ) push(x,y,z^1,d+1);
            REP1(i,1,n) if ( i!=y && e[y][i]==0 ) push(x,i,z^1,d+1);
        }
    }
    const int INF=1e9;
    int ans=INF;
    if ( vis[n][n][0] ) ans=min(ans,dis[n][n][0]/2);
    if ( vis[n][n][1] ) ans=min(ans,(dis[n][n][1]+1)/2);
    if ( ans==INF ) W(-1);
    else W(ans);
    return 0;
}