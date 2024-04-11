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

template<class T>
struct BIT {
    int n;
    vector<T> dat;
    void init(int _n) {
        n = _n;
        dat.clear();
        dat.resize(n + 1);
    }
    template<bool ask_range>
    void init(int _n, T a[]) {
        init(_n);
        for (int i = 1; i <= n; i++) {
            dat[i] += ask_range ? a[i] : a[i] - a[i - 1];
            int j = i + (i & -i);
            if (j <= n) dat[j] += dat[i];
        }
    }
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) dat[i] += v;
    }
    T ask(int x) {
        T s = T();
        for (int i = x; i; i -= i & -i) s += dat[i];
        return s;
    }
    // cannot add/ask a range simultaneously!
    void add(int l, int r, T v) {
        add(l, v);
        if (r + 1 <= n) add(r + 1, -v);
    }
    T ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};

BIT<int> bit;

const int N=2e5+10;
const int M=2e5+10;

LL f( LL x ) {
    return x*(x-1)/2;
}

struct Q {
    int l,d,r,u;
    Q rotate( int n ) {
        return {d,n-r+1,u,n-l+1};
    }
} q[M];

int n,m,p[N];

void solve( LL out[M] ) {
    static VI v[N];
    REP1(i,1,n) v[i].clear();
    REP1(i,1,m) v[q[i].l].PB(i);
    bit.init(n);
    REP1(i,1,n) {
        for ( int j:v[i] ) {
            LL s=bit.ask(q[j].d-1);
            out[j]+=f(i-1)-f(s);
        }
        bit.add(p[i],1);
    }
}

void rotate() {
    static int np[N];
    REP1(i,1,n) np[p[i]]=n-i+1;
    REP1(i,1,n) p[i]=np[i];
    REP1(i,1,m) q[i]=q[i].rotate(n);
}

LL sol[M];
int main() {
    R(n,m);
    REP1(i,1,n) R(p[i]);
    REP1(i,1,m) R(q[i].l,q[i].d,q[i].r,q[i].u);
    REP(i,4) {
        solve(sol);
        rotate();
    }
    REP1(i,1,m) sol[i]=f(n)-sol[i];
    REP1(i,1,m) W(sol[i]);
    return 0;
}