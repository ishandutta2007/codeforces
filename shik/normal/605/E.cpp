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

const int N=1010;
const double INF=1e100;

int n;
double p[N][N],dis[N],rp[N],sd[N];
bool vis[N];

/*
VI v;
double get( int x ) {
    double rp=1,sd=0;
    for ( int i:v ) {
        sd+=rp*p[x][i]*dis[i];
        rp*=(1-p[x][i]);
    }
    if ( rp==1 ) return INF;
    else return (sd+1)/(1-rp);
}
*/

void relax( int a, int b ) {
    if ( rp[a]==0 ) return;
    sd[a]+=rp[a]*p[a][b]*dis[b];
    rp[a]*=(1-p[a][b]);
    if ( rp[a]==1 ) dis[a]=INF;
    else dis[a]=(sd[a]+1)/(1-rp[a]);
}

int main() {
    R(n);
    REP1(i,1,n) REP1(j,1,n) {
        int pp;
        R(pp);
        p[i][j]=pp/100.0;
    }
    REP1(i,1,n) {
        dis[i]=INF;
        rp[i]=1;
        sd[i]=0;
    }
    dis[n]=0;
    vis[n]=1;
    REP1(i,1,n-1) relax(i,n);
    REP(i,n-1) {
        int w=0;
        REP1(j,1,n) if ( !vis[j] && (!w || dis[j]<dis[w]) ) w=j;
        dump(w,dis[w]);
        vis[w]=1;
        REP1(j,1,n) if ( !vis[j] ) relax(j,w);
    }
    double ans=dis[1];
    printf("%.12f\n",ans);
    return 0;
}