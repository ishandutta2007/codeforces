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

template<typename T, typename U>
struct Seg {
    int n;
    vector<T> val;
    vector<U> upd;
    template<typename F>
    void _init(int id, int l, int r, F f) {
        if (l == r) {
            val[id] = f(l);
            return;
        }
        int m = (l + r) / 2;
        _init(id * 2, l, m, f);
        _init(id * 2 + 1, m + 1, r, f);
        pull(id);
    }
    template<class F>
    void init(int _n, F f) {
        n = _n;
        val.clear();
        val.resize(4 * (n + 1));
        upd.clear();
        upd.resize(4 * (n + 1));
        _init(1, 1, n, f);
    }
    void init(int _n, T *a) {
        _init(_n, [a](int i) { return a[i]; });
    }
    void init(int _n, T v) {
        _init(_n, [v](int) { return v; });
    }
    T get(int id) {
        return upd[id](val[id]);
    }
    void pull(int id) {
        val[id] = get(id * 2) + get(id * 2 + 1);
    }
    void push(int id) {
        upd[id * 2] += upd[id];
        upd[id * 2 + 1] += upd[id];
        upd[id] = U();
    }
    T _ask(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return get(id);
        push(id);
        int m = (l + r) / 2;
        if (qr <= m) {
            T t = _ask(id * 2, l, m, ql, qr);
            pull(id);
            return t;
        } else if (ql > m) {
            T t = _ask(id * 2 + 1, m + 1, r, ql, qr);
            pull(id);
            return t;
        } else {
            T tl = _ask(id * 2, l, m, ql, qr);
            T tr = _ask(id * 2 + 1, m + 1, r, ql, qr);
            pull(id);
            return tl + tr;
        }
    }
    T ask(int l, int r) {
        assert(l <= r);
        return _ask(1, 1, n, l, r);
    }
    void _update(int id, int l, int r, int ql, int qr, U qv) {
        if (ql <= l && r <= qr) {
            upd[id] += qv;
            return;
        }
        push(id);
        int m = (l + r) / 2;
        if (ql <= m) _update(id * 2, l, m, ql, qr, qv);
        if (qr > m) _update(id * 2 + 1, m + 1, r, ql, qr, qv);
        pull(id);
    }
    void update(int ql, int qr, U qv) {
        assert(ql <= qr);
        _update(1, 1, n, ql, qr, qv);
    }
    void _zet(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            upd[id] = U();
            val[id] = qv;
            return;
        }
        push(id);
        int m = (l + r) / 2;
        if (qx <= m) _zet(id * 2, l, m, qx, qv);
        else _zet(id * 2 + 1, m + 1, r, qx, qv);
        pull(id);
    }
    void zet(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        zet(1, 1, n, qx, qv);
    }
};

struct Val {
    LL x;
    Val(LL _x = 0) : x(_x) {}
};
Val operator +(Val a, Val b) {
    return {max(a.x, b.x)};
}

struct Upd {
    LL d;
    Upd(LL _d = 0) : d(_d) {}
    Val operator()(Val v) {
        return {v.x + d};
    }
    Upd& operator +=(Upd rhs) {
        d += rhs.d;
        return *this;
    }
};


const int N=2e5+10;
const int L=1e6+10;
const LL INF=1e15;

int n,m,p;
int a[N],ca[N],b[N],cb[N],x[N],y[N],z[N];
LL ma[L],mb[L];

bool cmp( int s, int t ) {
    return tie(x[s],y[s])<tie(x[t],y[t]);
}

void main() {
    R(n,m,p);
    REP(i,n) R(a[i],ca[i]);
    REP(i,m) R(b[i],cb[i]);
    REP(i,p) R(x[i],y[i],z[i]);

    REP(i,L) ma[i]=mb[i]=INF;
    REP(i,n) chkmin(ma[a[i]],(LL)ca[i]);
    REP(i,m) chkmin(mb[b[i]],(LL)cb[i]);
    for ( int i=L-2; i>=0; i-- ) chkmin(ma[i],ma[i+1]);
    for ( int i=L-2; i>=0; i-- ) chkmin(mb[i],mb[i+1]);
    VI ord;
    REP(i,p) ord.PB(i);
    sort(ALL(ord),cmp);
    Seg<Val,Upd> seg;
    seg.init(L-1,[]( int i ) { return Val(-mb[i]); });
    LL ans=-(ma[0]+mb[0]);
    REP(ii,p) {
        int i=ord[ii];
        int xi=x[i];
        int yi=y[i];
        int zi=z[i];
        if ( ma[xi+1]==INF || mb[yi+1]==INF ) continue;
        seg.update(yi+1,L-1,Upd(zi));
        LL mx=seg.ask(1,L-1).x;
        LL now=mx-ma[xi+1];
        chkmax(ans,now);
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}