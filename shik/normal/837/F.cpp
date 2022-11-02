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


const LL INF=2e18;
LL F( LL n, LL m ) {
    LL x=1;
    REP1(i,1,m) {
        double tx=double(x)*(n+i)/i;
        if ( tx>INF ) return INF;
        x=(long double)x*(n+i)/i+0.5;
    }
    // dump(n,m,x);
    return x;
}

const int N=2e5+10;
int n;
LL k,a[N],b[N];

LL naive() {
    LL ans=0;
    while ( 1 ) {
        if ( a[n-1]>=k ) break;
        ans++;
        REP1(i,1,n-1) {
            a[i]+=a[i-1];
            if ( a[i]>=INF ) a[i]=INF;
        }
    }
    return ans;
}

bool chk( LL m ) {
    LL s=0;
    REP(i,n) {
        LL t=F(m-1,i);
        double ns=s+double(t)*a[n-i-1];
        if ( ns>=INF ) return 1;
        s+=t*a[n-i-1];
    }
    // dump(m,s);
    return s>=k;
}

int main() {
    R(n,k);
    REP(i,n) R(a[i]);
    int z=0;
    while ( a[z]==0 ) z++;
    n-=z;
    REP(i,n) a[i]=a[i+z];
    auto mx=*max_element(a,a+n);
    if ( mx>=k ) {
        W(0);
        return 0;
    }
    if ( n>=10 ) {
        W(naive());
        return 0;
    }
    LL l=1,r=k;
    while ( l!=r ) {
        LL m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m+1;
    }
    LL ans=l;
    W(ans);
    #ifdef SHIK
    LL nans=naive();
    dump(ans,nans);
    assert(ans==nans);
    #endif
    return 0;
}