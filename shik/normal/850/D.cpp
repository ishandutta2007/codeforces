// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }

template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f\n",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

template<class T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) { cerr << s << "=" << head << endl; }
template<class T, class... Args> void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...) do { fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); _dump(#__VA_ARGS__, __VA_ARGS__); } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B> ostream &operator<<(ostream &s, const pair<A, B> &p) { return s << "(" << p.first << "," << p.second << ")"; }
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) { return _out(s, ALL(c)); }
template<class T, size_t N> ostream &operator<<(ostream &s, const array<T, N> &c) { return _out(s, ALL(c)); }
template<class T> ostream &operator<<(ostream &s, const set<T> &c) { return _out(s, ALL(c)); }
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) { return _out(s, ALL(c)); }
#else
#define dump(...)
#endif
// }}}

const int M=32;
const int N=80;
const int INF=1e8;

int m,a[M];

int dp[N][M][N*M];
bool frm[N][M][N*M];

int go( int x, int y, int z ) {
    if ( z<0 ) return INF;
    int &ans=dp[x][y][z];
    if ( ans!=-1 ) return ans;
    if ( y==m && z==0 ) return ans=0;
    if ( y>=m ) return INF;
    int v0=go(x+1,y,z+a[y]-x);
    int v1=go(x+1,y+1,z+a[y]-x);
    if ( v0<=v1 ) {
        ans=v0+1;
        frm[x][y][z]=0;
    } else {
        ans=v1+1;
        frm[x][y][z]=1;
    }
    // dump(x,y,z,ans);
    return ans;
}

VI b;
void trace( int x, int y, int z ) {
    if ( y==m && z==0 ) return;
    b.PB(a[y]);
    if ( frm[x][y][z]==0 ) {
        trace(x+1,y,z+a[y]-x);
    } else {
        trace(x+1,y+1,z+a[y]-x);
    }
}

bool e[N][N];

int main() {
    memset(dp,-1,sizeof(dp));
    R(m);
    REP(i,m) R(a[i]);
    sort(a,a+m);
    int n=go(0,0,0);
    if ( n>=INF ) {
        W("=(");
        return 0;
    }
    trace(0,0,0);
    dump(n,b);
    assert(SZ(b)==n);
    W(n);
    vector<PII> v;
    REP(i,n) v.PB({b[i],i});
    while ( !v.empty() ) {
        sort(ALL(v));
        // dump(v);
        int d=v.back().first;
        int w=v.back().second;
        v.pop_back();
        REP(i,SZ(v)) {
            if ( i<d ) e[w][v[i].second]=1;
            else {
                e[v[i].second][w]=1;
                v[i].first--;
            }
        }
    }
    REP(i,n) {
        REP(j,n) putchar(e[i][j]?'1':'0');
        W("");
    }
    return 0;
}