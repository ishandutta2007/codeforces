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

template<typename T>
using MinHeap=priority_queue<T,vector<T>,greater<T>>;

const int N=1e5+10;
const LL INF=1e18;

int nid;

struct Seg {
    int n,a[4*N];
    template<typename F>
    void init( int id, int l, int r, F f ) {
        a[id]=++nid;
        if ( l==r ) return;
        int m=(l+r)/2;
        init(id*2,l,m,f);
        init(id*2+1,m+1,r,f);
        f(a[id],a[id*2]);
        f(a[id],a[id*2+1]);
    }
    template<typename F>
    void init( int _n, F f ) {
        n=_n;
        init(1,1,n,f);
    }
    void ask( int id, int l, int r, int ql, int qr, VI &qv ) {
        if ( ql<=l && r<=qr ) {
            qv.PB(a[id]);
            return;
        }
        int m=(l+r)/2;
        if ( ql<=m ) ask(id*2,l,m,ql,qr,qv);
        if ( qr>m ) ask(id*2+1,m+1,r,ql,qr,qv);
    }
    VI ask( int ql, int qr ) {
        vector<int> v;
        ask(1,1,n,ql,qr,v);
        return v;
    }
} s1,s2;

struct E {
    int to,len;
};

int n,m,st;
vector<E> e[8*N];
LL dis[8*N];

void add( int a, int b, int c ) {
    dump(a,b,c);
    e[a].PB({b,c});
}

void add( const VI &va, const VI &vb, int c ) {
    for ( int a:va ) for ( int b:vb ) add(a,b,c);
}

int main() {
    R(n,m,st);
    s1.init(n,[&]( int a, int b ) { add(b,a,0); });
    s2.init(n,[&]( int a, int b ) { add(a,b,0); });
    REP1(i,1,n) {
        auto v1=s1.ask(i,i);
        auto v2=s2.ask(i,i);
        assert(SZ(v1)==1);
        assert(SZ(v2)==1);
        add(v2,v1,0);
    }
    REP(i,m) {
        int op;
        R(op);
        if ( op==1 ) {
            int a,b,c;
            R(a,b,c);
            auto va=s1.ask(a,a);
            auto vb=s2.ask(b,b);
            assert(SZ(va)==1);
            assert(SZ(vb)==1);
            add(va,vb,c);
        } else if ( op==2 ) {
            int a,bl,br,c;
            R(a,bl,br,c);
            auto va=s1.ask(a,a);
            assert(SZ(va)==1);
            auto vb=s2.ask(bl,br);
            add(va,vb,c);
        } else if ( op==3 ) {
            int b,al,ar,c;
            R(b,al,ar,c);
            auto va=s1.ask(al,ar);
            auto vb=s2.ask(b,b);
            assert(SZ(vb)==1);
            add(va,vb,c);
        } else assert(0);
    }
    MinHeap<pair<LL,int>> h;
    auto push=[&]( int x, LL d ) {
        if ( dis[x]<=d ) return;
        dis[x]=d;
        h.push({d,x});
    };
    REP1(i,1,nid) dis[i]=INF;
    auto vs=s2.ask(st,st);
    assert(SZ(vs)==1);
    push(vs[0],0);
    dump(vs);
    while ( !h.empty() ) {
        auto x=h.top().second;
        auto d=h.top().first;
        h.pop();
        if ( dis[x]!=d ) continue;
        dump(x,d);
        for ( auto &i:e[x] ) push(i.to,d+i.len);
    }
    REP1(i,1,n) {
        auto vi=s2.ask(i,i);
        assert(SZ(vi)==1);
        LL ans=dis[vi[0]];
        if ( ans>=INF ) ans=-1;
        printf("%lld%c",ans,i==n?'\n':' ');
    }
    return 0;
}