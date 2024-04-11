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

const int C=1e5+10;

int n,m,cl,ce,v,l[C],e[C];
void main() {
    R(n,m,cl,ce,v);
    REP(i,cl) R(l[i]);
    REP(i,ce) R(e[i]);
    sort(l,l+cl);
    sort(e,e+ce);
    int q;
    R(q);
    while ( q-- ) {
        int x1,y1,x2,y2;
        R(y1,x1,y2,x2);
        if ( x1>x2 ) {
            swap(x1,x2);
            swap(y1,y2);
        }
        int ans=INT_MAX;
        if ( y1==y2 ) {
            chkmin(ans,x2-x1);
        }
        {
            int idx=lower_bound(l,l+cl,x1)-l;
            REP1(i,idx-1,idx) if ( i>=0 && i<cl ) {
                int now=0;
                now+=abs(x1-l[i]);
                now+=abs(y1-y2);
                now+=abs(l[i]-x2);
                chkmin(ans,now);
            }
        }
        {
            int idx=lower_bound(e,e+ce,x1)-e;
            REP1(i,idx-1,idx) if ( i>=0 && i<ce ) {
                int now=0;
                now+=abs(x1-e[i]);
                now+=(abs(y1-y2)+v-1)/v;
                now+=abs(e[i]-x2);
                chkmin(ans,now);
            }
        }
        W(ans);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}