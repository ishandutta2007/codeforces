// {{{ by shik
// #include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
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
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
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

template<typename T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<typename T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<typename T, typename F>
inline void sort_uniq( vector<T> &v, F f ) {
    sort(ALL(v),f);
    v.resize(unqiue(ALL(v))-v.begin());
}

template<typename T> using MaxHeap = priority_queue<T>;
template<typename T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;

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
    template<typename F>
    void init(int id, int l, int r, F f) {
        if (l == r) {
            dat[id] = f(l);
            return;
        }
        int m = (l + r) / 2;
        init(id * 2, l, m, f);
        init(id * 2 + 1, m + 1, r, f);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void init(int _n, T *a) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, [a](int i) { return a[i]; });
    }
    void init(int _n, T val) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, [val](int) { return val; });
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
    PII x;
    Data operator+(const Data &other) {
        return {min(x,other.x)};
    }
};


SegTreeRangeAsk<Data> seg;

const int N=1e5+10;

struct BIT {
    int dat[N];
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
    int ask( int l, int r ) {
        return ask(r)-ask(l-1);
    }
} bit;

int n;
Data a[N];
int main() {
    R(n);
    REP1(i,1,n) R(a[i].x.first);
    REP1(i,1,n) a[i].x.second=i;
    seg.init(n,a);
    REP1(i,1,n) bit.ins(i,1);
    LL ans=0;
    int p=1;
    REP(i,n) {
        auto mi1=seg.ask(1,n).x;
        auto mi2=seg.ask(p,n).x;
        int np=(mi1.first==mi2.first ? mi2.second : mi1.second);
        if ( p<=np ) {
            ans+=bit.ask(p,np);
        } else {
            ans+=bit.ask(p,n);
            ans+=bit.ask(1,np);
        }
        assert(a[np].x.first!=N);
        // dump(p,np,a[np].x,ans);
        a[np].x.first=N;
        seg.chg(np,a[np]);
        bit.ins(np,-1);
        p=(np<n ? np+1 : 1);
    }
    W(ans);
    return 0;
}