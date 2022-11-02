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

const int N=1010;
const int M=10010;
const int INF=1e9+10;

struct E {
    int a,b,c;
    void read() {
        R(a,b,c);
    }
} es[M];

int n,m,l,st,ed;

int dis[N];
VI e[N];
int sssp() {
    REP(i,n) {
        dis[i]=INF;
        e[i].clear();
    }
    REP(i,m) {
        e[es[i].a].PB(i);
        e[es[i].b].PB(i);
    }
    priority_queue<PII> q;
    auto push=[&]( int x, int d ) {
        if ( d>=dis[x] ) return;
        dis[x]=d;
        q.push(MP(-d,x));
    };
    push(st,0);
    while ( !q.empty() ) {
        int p=q.top().second;
        int d=-q.top().first;
        q.pop();
        if ( dis[p]!=d ) continue;
        for ( int i:e[p] ) {
            int to=p^es[i].a^es[i].b;
            push(to,d+es[i].c);
        }
    }
    // dump(dis[ed]);
    return dis[ed];
}

bool er[M];
bool solve() {
    REP(i,m) if ( er[i] ) es[i].c=1;
    if ( sssp()>l ) return 0;
    REP(i,m) if ( er[i] ) es[i].c=INF;
    if ( sssp()<l ) return 0;
    int ll=0,rr=m;
    while ( ll!=rr ) {
        int mm=(ll+rr+1)/2;
        REP(i,m) if ( er[i] ) es[i].c=(i<mm?INF:1);
        if ( sssp()<=l ) ll=mm;
        else rr=mm-1;
    }
    if ( ll<m ) {
        int idx=ll;
        assert(er[idx]);
        REP(i,m) if ( er[i] ) es[i].c=(i<idx?INF:1);
        ll=0;
        rr=INF;
        while ( ll!=rr ) {
            int mm=(ll+rr+1)/2;
            es[idx].c=mm;
            if ( sssp()<=l ) ll=mm;
            else rr=mm-1;
        }
        es[idx].c=ll;
    }
    assert(sssp()==l);
    return 1;
}

int main() {
    R(n,m,l,st,ed);
    REP(i,m) es[i].read();
    REP(i,m) er[i]=(es[i].c==0);
    if ( solve() ) {
        W("YES");
        REP(i,m) W(es[i].a,es[i].b,es[i].c);
    } else {
        W("NO");
    }
    return 0;
}