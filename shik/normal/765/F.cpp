// {{{ by shik
#pragma GCC optimize("O3")
#include <stdio.h>
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

template<typename T>
struct SegTreeRangeAsk {
    int n;
    vector<T> dat;
    void init(int id, int l, int r, T a) {
        if (l == r) {
            dat[id] = a;
            return;
        }
        int m = (l + r) / 2;
        init(id * 2, l, m, a);
        init(id * 2 + 1, m + 1, r, a);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void init(int _n, T a) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, a);
    }
    T ask(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return dat[id];
        int m = (l + r) / 2;
        if (qr <= m) return ask(id * 2, l, m, ql, qr);
        if (ql > m) return ask(id * 2 + 1, m + 1, r, ql, qr);
        T tl = ask(id * 2, l, m, ql, qr);
        T tr = ask(id * 2 + 1, m + 1, r, ql, qr);
        return tl + tr;
    }
    T ask(int l, int r) {
        assert(l <= r);
        return ask(1, 1, n, l, r);
    }
    void chg(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            dat[id] = qv;
            return;
        }
        int m = (l + r) / 2;
        if (qx <= m) chg(id * 2, l, m, qx, qv);
        else chg(id * 2 + 1, m + 1, r, qx, qv);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void chg(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        chg(1, 1, n, qx, qv);
    }
};

struct Data {
    int x;
    Data operator+(const Data &other) {
        return {min(x, other.x)};
    }
};

const int N=1e5+10;
const int M=3e5+10;
const int INF=1e9+10;

struct Q {
    int l,r;
} q[M];

int n,a[N],m,ans[M];
VI e[N],qv[N];

int nsa,sa[N];
inline int get( int x ) {
    return upper_bound(sa+1,sa+nsa+1,x)-sa-1;
}

void build() {
    REP1(i,1,n) sa[i]=a[i];
    sort(sa+1,sa+n+1);
    nsa=unique(sa+1,sa+n+1)-sa-1;
    SegTreeRangeAsk<Data> seg;
    seg.init(nsa,{INF});
    for ( int i=n; i>=1; i-- ) {
        int l=get(a[i]),r=nsa;
        // dump(i,l);
        while ( 1 ) {
            int j=seg.ask(l,r).x;
            if ( j==INF ) break;
            e[i].PB(j);
            // dump(i,j,a[i],a[j]);
            if ( a[i]==a[j] ) break;
            if ( l==r ) while(1);
            int x=(a[i]+a[j])/2;
            r=get(x);
        }
        seg.chg(l,{i});
    }
}

int v[N];

int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    build();
    REP1(i,1,n) a[i]=1000000000-a[i];
    build();
    R(m);
    REP1(i,1,m) R(q[i].l,q[i].r);
    REP1(i,1,m) qv[q[i].l].PB(i);
    SegTreeRangeAsk<Data> seg;
    seg.init(n,{INF});
    REP1(i,1,n) v[i]=INF;
    for ( int i=n; i>=1; i-- ) {
        for ( int j:e[i] ) {
            int x=abs(a[i]-a[j]);
            if ( x<v[j] ) {
                seg.chg(j,{x});
                v[j]=x;
            }
        }
        for ( int j:qv[i] ) ans[j]=seg.ask(i,q[j].r).x;
    }
    // REP1(i,1,m) {
        // int mi=INF;
        // REP1(j,q[i].l,q[i].r) REP1(k,j+1,q[i].r) mi=min(mi,abs(a[j]-a[k]));
        // dump(i,mi,ans[i]);
        // assert(mi==ans[i]);
    // }
    REP1(i,1,m) W(ans[i]);
    return 0;
}