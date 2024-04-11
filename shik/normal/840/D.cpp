// {{{ by shik
#include <stdio.h>
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
    void go(int id, int l, int r, int ql, int qr, VI &qo) {
        if (ql <= l && r <= qr) {
            for ( int i:dat[id].x ) if ( i ) qo.PB(i);
            return;
        }
        int m = (l + r) / 2;
        if (ql <= m) go(id * 2, l, m, ql, qr, qo);
        if (qr > m) go(id * 2 + 1, m + 1, r, ql, qr, qo);
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

const int N=3e5+10;
const int K=5;

struct Data {
    int l,r,x[K-1];
    int& operator[]( int i ) { return x[i]; }
    int operator[]( int i ) const { return x[i]; }
};

VI v[N];

int f( int l, int r, int x ) {
    auto li=lower_bound(ALL(v[x]),l);
    auto ri=upper_bound(li,v[x].end(),r);
    return ri-li;
}

Data operator+(const Data &a, const Data &b) {
    static int vis[N],vid;
    vid++;
    Data c;
    c.l=a.l;
    c.r=b.r;
    const int g=(c.r-c.l+1)/K;
    int k=0;
    auto go=[&]( int x ) {
        if ( !x || vis[x]==vid ) return;
        vis[x]=vid;
        if ( f(c.l,c.r,x)<=g ) return;
        c[k++]=x;
    };
    for ( int i:a.x ) go(i);
    for ( int i:b.x ) go(i);
    assert(k<=K-1);
    while ( k<K-1 ) c[k++]=0;
    return c;
}

int n,m,a[N];
Data dat[N];
SegTreeRangeAsk<Data> seg;

struct SplitMix32 {
    uint32_t s;
    SplitMix32(uint32_t _s = 0) : s(_s) {}
    uint32_t operator()() {
        uint32_t z = (s += 0x9e3779b1);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
} rnd;

int main() {
    R(n,m);
    REP1(i,1,n) R(a[i]);
    // n=m=3e5;
    // REP1(i,1,n) a[i]=rnd()%2+1;
    REP1(i,1,n) v[a[i]].PB(i);
    REP1(i,1,n) dat[i]={i,i,{a[i]}};
    seg.init(n,dat);
    while ( m-- ) {
        int l,r,k;
        R(l,r,k);
        // l=rnd()%n+1;
        // r=rnd()%n+1;
        // if ( l>r ) swap(l,r);
        // k=2+rnd()%4;
        const int g=(r-l+1)/k;
        int ans=INT_MAX;
        VI qo;
        seg.go(1,1,n,l,r,qo);
        static int vis[N],vid;
        vid++;
        for ( int i:qo ) {
            if ( vis[i]==vid ) continue;
            vis[i]=vid;
            if ( i<ans && f(l,r,i)>g ) ans=i;
        }
        W(ans==INT_MAX ? -1 : ans);
    }
    return 0;
}