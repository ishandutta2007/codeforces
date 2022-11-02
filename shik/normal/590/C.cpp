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

const int N=1010;
const int INF=1e8;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int n,m,dis[4][N][N];
char s[N][N];

bool out( int x, int y ) {
    return x<1 || x>n || y<1 || y>m;
}

void bfs( int state, int d[N][N] ) {
    REP1(i,1,n) REP1(j,1,m) d[i][j]=INF;
    queue<int> q;
    auto push=[&]( int x, int y, int z ) {
        d[x][y]=z;
        q.push(x);
        q.push(y);
    };
    REP1(i,1,n) REP1(j,1,m) if ( s[i][j]==state+'0' ) push(i,j,0);
    while ( !q.empty() ) {
        int x=q.front(); q.pop();
        int y=q.front(); q.pop();
        int nd=d[x][y]+1;
        REP(i,4) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( out(nx,ny) || s[nx][ny]=='#' || d[nx][ny]!=INF ) continue;
            push(nx,ny,nd);
        }
    }
}

int d_two( int a, int b ) {
    int ans=INF;
    char cb=b+'0';
    REP1(i,1,n) REP1(j,1,m) if ( s[i][j]==cb ) ans=min(ans,dis[a][i][j]-1);
    return ans;
}

int main() {
    RI(n,m);
    REP1(i,1,n) scanf("%s",s[i]+1);
    REP1(i,1,3) bfs(i,dis[i]);
    int ans=INF;
    ans=min(ans,d_two(1,2)+d_two(1,3));
    ans=min(ans,d_two(2,1)+d_two(2,3));
    ans=min(ans,d_two(3,1)+d_two(3,2));
    REP1(i,1,n) REP1(j,1,m) if ( s[i][j]=='.' ) {
        int now=0;
        REP1(k,1,3) now+=dis[k][i][j];
        now-=2;
        ans=min(ans,now);
    }
    if ( ans>=INF/2 ) ans=-1;
    printf("%d\n",ans);
    return 0;
}