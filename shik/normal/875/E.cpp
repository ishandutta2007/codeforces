// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
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

// {{{ Bitwise
#define F(name) \
    template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> \
    constexpr int name(T x) { return sizeof(T) <= sizeof(int) ? __builtin_ ## name(x) : __builtin_ ## name ## ll(x); }

F(clz) F(ctz) F(ffs) F(parity) F(popcount)

#undef F
#define popcnt popcount

template<class T>
T has_bit(T x, int i) { return (x >> i) & 1; }

template<class T>
constexpr int lg2(T x) { return sizeof(T) * CHAR_BIT - 1 - clz(x); }
// }}}
template<typename T, const T&(*f)(const T&, const T&)>
struct RMQ {
    int n, lgn;
    vector<vector<T>> st;
    void init(int _n, const T a[]) { // 0-based
        assert(_n > 0);
        n = _n;
        lgn = lg2(n);
        st.resize(lgn + 1);
        st[0] = {a, a + n};
        for (int i = 0; i < lgn; i++) {
            const int l = 1 << i;
            st[i + 1].resize(n - l - l + 1);
            for (int j = 0; j + l + l <= n; j++) st[i + 1][j] = f(st[i][j], st[i][j + l]);
        }
    }
    T ask(int l, int r) { // 0-based, [l, r]
        int lv = lg2(r - l + 1);
        return f(st[lv][l], st[lv][r - (1 << lv) + 1]);
    }
};

const int N=1e5+10;
int n,s1,s2,x[N];

RMQ<int,min> rmi;
RMQ<int,max> rmx;

bool chk( int m ) {
    int u=0;
    while ( u+1<=n && abs(x[u+1]-s1)<=m ) u++;
    while ( u+1<=n && abs(x[u+1]-s2)<=m ) u++;
    REP1(i,1,n) {
        if ( i>u ) return 0;
        if ( abs(x[i]-rmi.ask(i+1,u))>m ) continue;
        if ( abs(x[i]-rmx.ask(i+1,u))>m ) continue;
        while ( u+1<=n && abs(x[u+1]-x[i])<=m ) u++;
    }
    return 1;
}

void main() {
    R(n,s1,s2);
    REP1(i,1,n) R(x[i]);
    int l=abs(s1-s2),r=1e9;
    rmi.init(n+1,x);
    rmx.init(n+1,x);
    while ( l!=r ) {
        int m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m+1;
    }
    W(l);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}