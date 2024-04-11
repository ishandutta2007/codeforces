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

const int N=1e5+10;
const int U=1e5;
const int G=300;

struct P {
    int l0,r0;
    bool neg;
    int l() { return neg ? -r0 : l0; }
    int r() { return neg ? -l0 : r0; }
};

int n,q,a[N],x[N];
bool neg[2*U+1];
char op[N];
void main() {
    R(n,q);
    REP(i,n) R(a[i]);
    REP(i,q) R(op[i],x[i]);
    vector<P> v;
    v.reserve(N);
    auto fix=[&]() {
        // dump(SZ(v));
        for ( auto &p:v ) REP1(i,p.l0,p.r0) neg[i+U]=p.neg;
        REP(i,n) if ( neg[a[i]+U] ) a[i]*=-1;
        v.clear();
        v.PB({-U,U,0});
    };
    fix();
    REP(i,q) {
        int t=x[i];
        int nv=SZ(v);
        // for ( auto &p:v ) dump(i,p.l0,p.r0,p.l(),p.r());
        if ( op[i]=='<' ) {
            REP(j,nv) {
                auto& p=v[j];
                if ( p.r()<t ) p.neg^=1;
                else if ( p.l()<t ) {
                    if ( p.neg ) {
                        v.PB({p.l0,-t,1});
                        p.l0=-t+1;
                        p.neg=0;
                    } else {
                        v.PB({t,p.r0,0});
                        p.r0=t-1;
                        p.neg=1;
                    }
                }
            }
        } else if ( op[i]=='>' ) {
            REP(j,nv) {
                auto& p=v[j];
                if ( p.l()>t ) p.neg^=1;
                else if ( p.r()>t ) {
                    if ( p.neg ) {
                        v.PB({-t,p.r0,1});
                        p.r0=-t-1;
                        p.neg=0;
                    } else {
                        v.PB({p.l0,t,0});
                        p.l0=t+1;
                        p.neg=1;
                    }
                }
            }
        } else assert(0);
        if ( SZ(v)>G ) fix();
    }
    fix();
    W(VI(a,a+n));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}