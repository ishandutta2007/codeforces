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

// SegTree {{{
template<class T>
struct SegTree {
    int n;
    vector<T> dat;
    template<class F>
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
    template<class F>
    void init(int _n, F f) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, f);
    }
    void init(int _n, const T *a) {
        init(_n, [a](int i) { return a[i]; });
    }
    void init(int _n, T v) {
        init(_n, [v](int) { return v; });
    }
    T _ask(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return dat[id];
        int m = (l + r) / 2;
        if (qr <= m) {
            return _ask(id * 2, l, m, ql, qr);
        } else if (ql > m) {
            return _ask(id * 2 + 1, m + 1, r, ql, qr);
        } else {
            T tl = _ask(id * 2, l, m, ql, qr);
            T tr = _ask(id * 2 + 1, m + 1, r, ql, qr);
            return tl + tr;
        }
    }
    T ask(int l, int r) {
        assert(l <= r);
        return _ask(1, 1, n, l, r);
    }
    void _zet(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            dat[id] = qv;
            return;
        }
        int m = (l + r) / 2;
        if (qx <= m) _zet(id * 2, l, m, qx, qv);
        else _zet(id * 2 + 1, m + 1, r, qx, qv);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void zet(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        _zet(1, 1, n, qx, qv);
    }
};
// }}}

struct Val {
    int l1,r1,l2,r2,c1,c2,dis;
};

Val operator+(Val s1, Val s2) {
    Val s;
    int a=s1.c1,b=s1.c2,c=s2.c1,d=s2.c2;

    s.dis=max(s1.dis,s2.dis);
    s.dis=max({s.dis,s1.r1+s2.l2,s1.r2+s2.l1});

    if ( b<c ) {
        s.c1=a-b+c;
        s.c2=d;
    } else {
        s.c1=a;
        s.c2=b-c+d;
    }

    s.r1=max({s2.r1,s1.r1-c+d,s1.r2+c+d});
    s.r2=max(s2.r2,s1.r2+c-d);

    s.l1=max({s1.l1,s2.l1-b+a,s2.l2+b+a});
    s.l2=max({s1.l2,s2.l2+b-a});
    return s;
}

const Val vl={0,0,0,0,0,1,0};
const Val vr={0,0,0,0,1,0,0};

Val val_of( char ch ) {
    return ch=='(' ? vl : vr;
}

SegTree<Val> seg;

const int N=2e5+10;
int n,q;
char s[N];
void main() {
    R(n,q);
    scanf("%s",s+2);
    n=2*n;
    s[1]='(';
    s[n]=')';
    seg.init(n,[&]( int i ) { return val_of(s[i]); });
    W(seg.ask(1,n).dis);
    while ( q-- ) {
        int l,r;
        R(l,r);
        l++; r++;
        swap(s[l],s[r]);
        seg.zet(l,val_of(s[l]));
        seg.zet(r,val_of(s[r]));
        int ans=seg.ask(1,n).dis;
        W(ans);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}