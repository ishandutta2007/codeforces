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

typedef long double Double;

const int M=70;
int n,a[M][M];

Double p[M][M],win[4*M][M],dp[4*M][M];
void go( int id, int l, int r ) {
    if ( l+1==r ) {
        win[id][l]=1;
        return;
    }
    int m=(l+r)/2;
    int w=(r-l)/2;
    go(id*2,l,m);
    go(id*2+1,m,r);
    REP1(i,l,m-1) {
        Double s=0;
        REP1(j,m,r-1) s+=win[id*2+1][j]*p[i][j];
        s*=win[id*2][i];
        win[id][i]=s;
        dp[id][i]=w*s+dp[id*2][i]+*max_element(dp[id*2+1]+m,dp[id*2+1]+r);
    }
    REP1(i,m,r-1) {
        Double s=0;
        REP1(j,l,m-1) s+=win[id*2][j]*p[i][j];
        s*=win[id*2+1][i];
        win[id][i]=s;
        dp[id][i]=w*s+dp[id*2+1][i]+*max_element(dp[id*2]+l,dp[id*2]+m);
    }
    REP1(i,l,r-1) dump(id,l,r,w,i,win[id][i],dp[id][i]);
}

int main() {
    R(n);
    int m=1<<n;
    REP(i,m) REP(j,m) R(a[i][j]);
    REP(i,m) REP(j,m) p[i][j]=a[i][j]/Double(100);
    go(1,0,m);
    auto ans=*max_element(dp[1],dp[1]+m);
    printf("%.14f\n",(double)ans);
    return 0;
}