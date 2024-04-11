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

const int N=3010;

int n,m,d1[N][N],d2[N][N],f1[N][3],f2[N][N];
VI e1[N],e2[N];

void BFS( int st, VI e[], int dis[], int far[] ) {
    REP1(i,1,n) dis[i]=N;
    queue<int> q;
    dis[st]=0;
    q.push(st);
    while ( !q.empty() ) {
        int p=q.front(); q.pop();
        for ( int i:e[p] ) if ( dis[i]==N ) {
            dis[i]=dis[p]+1;
            q.push(i);
        }
    }
    far[0]=far[1]=far[2]=st;
    REP1(i,1,n) if ( dis[i]!=N ) {
        REP(j,3) if ( dis[i]>dis[far[j]] ) {
            for ( int k=2; k>j; k-- ) far[k]=far[k-1];
            far[j]=i;
            break;
        }
    }
    dump(st,VI(dis+1,dis+n+1),VI(far,far+3));
}

int main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e1[a].PB(b);
        e2[b].PB(a);
    }
    REP1(i,1,n) {
        BFS(i,e1,d1[i],f1[i]);
        BFS(i,e2,d2[i],f2[i]);
    }
    int ans=0;
    VI sol;
    REP1(i,1,n) REP1(j,1,n) if ( i!=j && d1[i][j]!=N ) {
        REP(xx,3) REP(yy,3) {
            int x=f2[i][xx];
            int y=f1[j][yy];
            // x-i-j-y
            if ( x==i || x==j || x==y || i==y || j==y ) continue;
            int now=d1[x][i]+d1[i][j]+d1[j][y];
            if ( now>ans ) {
                ans=now;
                sol=VI{x,i,j,y};
            }
        }
    }
    dump(ans);
    W(sol);
    return 0;
}