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
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=110;

int n,m;
char s[3][N];
bool vis[3][N];

bool ok( int x, int y ) {
    if ( x<0 || x>=3 ) return 0;
    if ( y>=n ) return 1;
    char c=s[x][y];
    return c=='s' || c=='.';
}

bool go( int x, int y ) {
    if ( y>=n ) return 1;
    if ( vis[x][y] ) return 0;
    vis[x][y]=1;
    if ( !ok(x,y+1) ) return 0;
    y++;
    REP1(i,-1,+1) {
        int nx=x+i;
        int ny=y;
        if ( !ok(nx,ny) ) continue;
        ny++;
        if ( !ok(nx,ny) ) continue;
        ny++;
        if ( !ok(nx,ny) ) continue;
        if ( go(nx,ny) ) return 1;
    }

    return 0;
}

int main() {
    int t;
    RI(t);
    while ( t-- ) {
        memset(s,0,sizeof(s));
        RI(n,m);
        REP(i,3) scanf("%s",s[i]);
        int sx=0,sy=0;
        while ( sx<3 && s[sx][sy]!='s' ) sx++;
        assert(sx<3);
        memset(vis,0,sizeof(vis));
        puts(go(sx,sy)?"YES":"NO");
    }
    return 0;
}