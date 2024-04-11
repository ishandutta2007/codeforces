// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

// {{{ BIT
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
// }}}

const int N=1e5+10;

struct F {
    LL u,d;
    F():u(0),d(1) {}
    F( LL _u, LL _d):u(_u),d(_d) {
        assert(u>0);
        assert(d>0);
    }
    F( LL x ) {
        assert(x>0);
        u=x;
        d=1;
    }
};

bool operator==( const F &a, const F &b ) {
    return a.u*b.d == b.u*a.d;
}

F operator/( const F &a, const F &b ) {
    return F(a.u*b.d,a.d*b.u);
}

bool operator<( const F &a, const F &b ) {
    return a.u*b.d < b.u*a.d;
}

// typedef long double T;
typedef F T;

int m;

struct P {
    int x,v,l,r;
    T tl,tr;
    P( int _x, int _v ):x(abs(_x)),v(abs(_v)) {
        l=r=-1;
        tl=T(x)/T(v+m);
        tr=T(x)/T(v-m);
    }
};

#ifdef SHIK
ostream& operator<<( ostream &s, const P &p ) {
    return s<<make_tuple(p.x,p.v,p.tl,p.tr);
}
ostream& operator<<( ostream &s, const F &f ) {
    return s<<make_tuple(f.u,f.d);
}
#endif

int n,x[N],v[N];
vector<P> pl,pr;
vector<T> vt;
VI tl,tr;

int conv( T t ) {
    return lower_bound(ALL(vt),t)-vt.begin()+1;
}

void conv( P &p ) {
    p.l=conv(p.tl);
    p.r=conv(p.tr);
}

bool cmp_lr( const P &a, const P &b ) {
    if ( a.l!=b.l ) {
        return a.l>b.l;
    } else {
        return a.r<b.r;
    }
}

LL solve( vector<P> &vp ) {
    BIT<int> bit;
    bit.init(SZ(vt));
    sort(ALL(vp),cmp_lr);
    LL ans=0;
    for ( auto &p:vp ) {
        int r=p.r;
        ans+=bit.ask(r);
        bit.add(r,+1);
    }
    return ans;
}

void main() {
    R(n,m);
    REP(i,n) R(x[i],v[i]);
    REP(i,n) {
        P p(x[i],v[i]);
        if ( x[i]<0 ) pl.PB(p);
        else pr.PB(p);
    }
    for ( auto p:pl ) {
        vt.PB(p.tl);
        vt.PB(p.tr);
    }
    for ( auto p:pr ) {
        vt.PB(p.tl);
        vt.PB(p.tr);
    }
    sort_uniq(vt);
    for ( auto &p:pl ) conv(p);
    for ( auto &p:pr ) conv(p);
    // dump(pl);
    // dump(pr);
    for ( auto p:pr ) {
        tl.PB(p.l);
        tr.PB(p.r);
    }
    sort(ALL(tl));
    sort(ALL(tr));
    LL cnt=0;
    for ( auto p:pl ) {
        int cl=lower_bound(ALL(tr),p.l)-tr.begin();
        int cr=tl.end()-upper_bound(ALL(tl),p.r);
        cnt+=cl+cr;
    }
    LL ans=(LL)SZ(pl)*SZ(pr)-cnt;
    ans+=solve(pl);
    ans+=solve(pr);
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}