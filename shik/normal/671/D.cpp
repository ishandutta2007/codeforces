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

const int N=3e5+10;

struct F {
    int to,len;
};

int n,m;
VI e[N];
vector<F> f[N];

int dep[N],sz[N];
void dfs( int p, int lv ) {
    dep[p]=-lv;
    sz[p]=SZ(f[p]);
    for ( int i:e[p] ) {
        e[i].erase(find(ALL(e[i]),p));
        dfs(i,lv+1);
        sz[p]+=sz[i];
    }
    if ( !e[p].empty() ) {
        int w=0;
        REP(i,SZ(e[p])) if ( sz[e[p][i]]>sz[e[p][w]] ) w=i;
        swap(e[p][0],e[p][w]);
    }
}

inline void ins( map<int,LL> &mp, int k, LL v ) {
    {
        auto it=mp.lower_bound(k);
        if ( it!=mp.end() && it->second<=v ) return;
    }
    while ( 1 ) {
        auto it=mp.upper_bound(k);
        if ( it==mp.begin() ) break;
        it--;
        if ( it->second<v ) break;
        mp.erase(it);
    }
    mp[k]=v;
}

struct DP {
    LL d;
    map<int,LL> mp;
    void ins( int k, LL v ) {
        ::ins(mp,k,v-d);
    }
    LL min() {
        return mp.begin()->second+d;
    }
};

inline void merge( DP &a, DP &b ) {
    for ( auto &i:b.mp ) a.ins(i.first,i.second+b.d);
}

DP dp[N];
int dpi[N];
bool go( int p ) {
    for ( int i:e[p] ) if ( !go(i) ) return 0;
    LL base=0;
    for ( int i:e[p] ) {
        auto &j=dp[dpi[i]];
        base+=j.min();
    }
    for ( int i:e[p] ) {
        auto &j=dp[dpi[i]];
        j.d+=base-j.min();
        if ( !dpi[p] ) dpi[p]=dpi[i];
        else merge(dp[dpi[p]],j);
    }
    if ( !dpi[p] ) dpi[p]=p;
    auto &me=dp[dpi[p]];
    for ( auto &i:f[p] ) me.ins(dep[i.to],base+i.len);
    while ( !me.mp.empty() && me.mp.begin()->first<=(dep[p]-(p==1)) ) me.mp.erase(me.mp.begin());
    dump(p,base,me.d,me.mp);
    return !me.mp.empty();
}

int main() {
    R(n,m);
    if ( n==1 ) {
        W(0);
        return 0;
    }
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP(i,m) {
        int a,b,c;
        R(a,b,c);
        f[a].PB(F{b,c});
    }
    dfs(1,1);
    if ( !go(1) ) W(-1);
    else W(dp[dpi[1]].min());
    return 0;
}