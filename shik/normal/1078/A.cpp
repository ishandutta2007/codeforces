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

using Double=double;

Double hdis( Double x1, Double y1, Double x2, Double y2 ) {
    return abs(x1-x2)+abs(y1-y2);
}

Double edis( Double x1, Double y1, Double x2, Double y2 ) {
    auto dx=x1-x2;
    auto dy=y1-y2;
    return sqrt(dx*dx+dy*dy);
}

// ax + by + c = 0
Double a,b,c,x1,y1,x2,y2;

Double get_x( Double y ) {
    return (-b * y - c) / a;
}

Double get_y( Double x ) {
    return (-a * x - c) / b;
}

void main() {
    R(a,b,c,x1,y1,x2,y2);
    Double ans=abs(x1-x2)+abs(y1-y2);
    vector<pair<Double,Double>> v1,v2;
    if ( b!=0 ) v1.PB({x1,get_y(x1)});
    if ( a!=0 ) v1.PB({get_x(y1),y1});
    if ( b!=0 ) v2.PB({x2,get_y(x2)});
    if ( a!=0 ) v2.PB({get_x(y2),y2});
    for ( auto [x3,y3]:v1 ) for ( auto [x4,y4]:v2 ) {
        Double now=hdis(x1,y1,x3,y3)+edis(x3,y3,x4,y4)+hdis(x4,y4,x2,y2);
        chkmin(ans,now);
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}