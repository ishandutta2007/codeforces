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

const int N=2e5+10;
int n,a[N];
bool bad[N];

int go( int x, int y ) {
    static set<PII> vis;
    if ( x>y ) swap(x,y);
    if ( vis.count(MP(x,y)) ) return -1;
    vis.insert(MP(x,y));
    VI s;
    REP1(i,x-1,x+1) if ( i>=1 && i<=n-1 ) s.PB(i);
    REP1(i,y-1,y+1) if ( i>=1 && i<=n-1 ) s.PB(i);
    sort(ALL(s));
    s.erase(unique(ALL(s)),s.end());
    int cnt=0;
    for ( int i:s ) {
        if ( i%2==1 && a[i]>=a[i+1] ) cnt++;
        if ( i%2==0 && a[i]<=a[i+1] ) cnt++;
    }
    swap(a[x],a[y]);
    for ( int i:s ) {
        if ( i%2==1 && a[i]>=a[i+1] ) cnt--;
        if ( i%2==0 && a[i]<=a[i+1] ) cnt--;
    }
    swap(a[x],a[y]);
    return cnt;
}

int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n-1) {
        if ( i%2==1 ) bad[i]=(a[i]>=a[i+1]);
        else bad[i]=(a[i]<=a[i+1]);
    }
    int cnt=0;
    REP1(i,1,n) if ( bad[i] ) cnt++;
    if ( cnt>6 ) {
        W(0);
        return 0;
    }
    VI v;
    REP1(i,1,n) if ( bad[i-1] || bad[i] || bad[i+1] ) v.PB(i);
    dump(v);
    int ans=0;
    for ( int i:v ) REP1(j,1,n) if ( go(i,j)==cnt ) {
        ans++;
    }
    W(ans);
    return 0;
}