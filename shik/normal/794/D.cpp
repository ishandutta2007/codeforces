// {{{ by shik
// #include <stdio.h>
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
void _W( const long long &x ) { printf("%" PRId64,x); }
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

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

struct SplitMix64 {
    uint64_t s;
    SplitMix64(uint64_t _s = 0) : s(_s) {}
    uint64_t operator()() {
        uint64_t z = (s += 0x9E3779B97F4A7C15);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EB;
        return z ^ (z >> 31);
    }
} rnd;

const int N=3e5+10;
int n,m,sol[N];
VI e[N];
uint64_t r[N],h[N];
map<uint64_t,set<uint64_t>> f;
map<uint64_t,int> lb;

bool solve() {
    REP1(i,1,n) r[i]=rnd();
    REP1(i,1,n) {
        h[i]=r[i];
        for ( int j:e[i] ) h[i]^=r[j];
    }
    REP1(i,1,n) {
        auto &s=f[h[i]];
        for ( int j:e[i] ) if ( h[i]!=h[j] ) s.insert(h[j]);
    }
    for ( auto &i:f ) if ( SZ(i.second)>2 ) return 0;
    PII mi{N,0};
    REP1(i,1,n) chkmin(mi,{SZ(f[h[i]]),i});
    if ( mi.first>=2 ) return 0;
    queue<uint64_t> q;
    int t=0;
    auto push=[&]( uint64_t x ) {
        if ( lb.count(x) ) return;
        lb[x]=++t;
        q.push(x);
    };
    push(h[mi.second]);
    while ( !q.empty() ) {
        auto x=q.front(); q.pop();
        for ( auto i:f[x] ) push(i);
    }
    REP1(i,1,n) sol[i]=lb[h[i]];
    REP1(i,1,n) for ( int j:e[i] ) assert(abs(sol[i]-sol[j])<=1);
    return 1;
}

int main() {
    rnd.s=time(0)^getpid();
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    if ( solve() ) {
        W("YES");
        W(VI(sol+1,sol+n+1));
    } else {
        W("NO");
    }
    return 0;
}