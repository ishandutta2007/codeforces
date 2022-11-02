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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

struct SplitMix32 {
    uint32_t s;
    SplitMix32(uint32_t _s = 0) : s(_s) {}
    uint32_t operator()() {
        uint32_t z = (s += 0x9e3779b1);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
    int i( int l, int r ) {
        auto x=(*this)();
        return l+x%(r-l+1);
    }
} rng;

const int L=1e8;
const int INF=1e9;

struct NPC {
    vector<int> vx,vy;
    void init( int n, int m ) {
        vx.clear();
        vy.clear();
        // REP(i,n) vx.PB(-L+i*20000+rng.i(0,10));
        // REP(i,m) vy.PB(-L+i*20000+rng.i(0,10));
        REP(i,n) vx.PB(rng.i(-L,+L));
        REP(i,m) vy.PB(rng.i(-L,+L));
        sort(ALL(vx));
        sort(ALL(vy));
    }
    static int ask( const VI &v, int x ) {
        int mi=INF;
        auto it=lower_bound(ALL(v),x);
        if ( it!=v.end() ) mi=min(mi,*it-x);
        if ( it!=v.begin() ) {
            it--;
            mi=min(mi,x-*it);
        }
        assert(mi!=INF);
        return mi;
    }
    int ask( int x, int y ) {
        int mi=INF;
        mi=min(mi,ask(vx,x));
        mi=min(mi,ask(vy,y));
        return mi;
    }
} npc;

int ask_cnt;
int ask( int x, int y ) {
    ask_cnt++;
#ifdef SHIK
    return npc.ask(x,y);
#else
    printf("0 %d %d\n",x,y);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    if ( res==-1 ) exit(0);
    return res;
#endif
}

struct Range {
    int l,r;
    int mid() { return l+(r-l)/2; }
    int len() const { return r-l+1; }
    bool operator <( const Range &rhs ) const { return len()<rhs.len(); }
};

template<typename F>
VI solve( F f ) {
    VI v;
    priority_queue<Range> q;
    q.push({-L,+L});
    while ( !q.empty() ) {
        auto t=q.top(); q.pop();
        int m=t.mid();
        int d=f(m);
        if ( d==0 ) {
            v.PB(m);
            d++;
        }
        int l1=t.l;
        int r1=m-d;
        int l2=m+d;
        int r2=t.r;
        if ( l1<=r1 ) q.push({l1,r1});
        if ( l2<=r2 ) q.push({l2,r2});
    }
    return v;
}

int main() {
    npc.init(10000,10000);
    int mx=-1,ox=0,oy=0;
    REP(i,2000) {
        int x=rng.i(-L,+L);
        int y=rng.i(-L,+L);
        int now=ask(x,y);
        if ( now>mx ) tie(mx,ox,oy)=tie(now,x,y);
    }
    assert(mx>0);
    dump(mx,ox,oy);
    auto vx=solve([&]( int m ) { return ask(m,oy); });
    auto vy=solve([&]( int m ) { return ask(ox,m); });
    sort(ALL(vx));
    sort(ALL(vy));
    W(1,SZ(vx),SZ(vy));
    W(vx);
    W(vy);
#ifdef SHIK
    dump(ask_cnt);
    assert(vx==npc.vx);
    assert(vy==npc.vy);
#endif
    return 0;
}