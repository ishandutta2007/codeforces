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

const int N=8;

bool flag;
void upd( string &a, const string &b ) {
    if ( a.empty() || SZ(b)<SZ(a) || (SZ(a)==SZ(b) && b<a) ) {
        flag=1;
        a=b;
    }
}

string se[1<<N],st[1<<N],sf[1<<N];
void predo() {
    sf[0b00001111]="x";
    sf[0b00110011]="y";
    sf[0b01010101]="z";
    while ( 1 ) {
        flag=0;
        REP(i,1<<N) {
            if ( !st[i].empty() ) upd(se[i],st[i]);
            if ( se[i].empty() ) continue;
            REP(j,1<<N) if ( !st[j].empty() ) {
                upd(se[i|j],se[i]+"|"+st[j]);
            }
        }
        REP(i,1<<N) {
            if ( !sf[i].empty() ) upd(st[i],sf[i]);
            if ( st[i].empty() ) continue;
            REP(j,1<<N) if ( !sf[j].empty() ) {
                upd(st[i&j],st[i]+"&"+sf[j]);
            }
        }
        REP(i,1<<N) {
            int inv=(~i)&((1<<N)-1);
            if ( !sf[inv].empty() ) upd(sf[i],"!"s+sf[inv]);
            if ( !se[i].empty() ) upd(sf[i],"("s+se[i]+")");
        }
        if ( !flag ) break;
    }
    REP(i,1<<N) dump(i,se[i]);
}

void main() {
    predo();
    int t;
    R(t);
    while ( t-- ) {
        char s[16];
        R(s);
        int v=strtol(s,NULL,2);
        W(se[v]);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}