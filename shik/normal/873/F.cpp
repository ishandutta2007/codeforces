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

struct SAM {
    struct nd { int l, p; array<int, 26> e; };
    vector<nd> v;
    SAM() : v(2, nd{0, 0, {{0}}}) {}
    void push(int c) {
        int wh = v.size(), st = wh - 1, it = st;
        while (it && !v[it].e[c]) it = v[it].p;
        if (it && v[v[it].e[c]].l != v[it].l + 1) {
            int cp = wh++, ob = v[it].e[c];
            v.push_back(nd{v[it].l + 1, v[ob].p, v[ob].e});
            for (v[ob].p = cp; it && v[it].e[c] == ob; it = v[it].p) v[it].e[c] = cp;
        }
        for (it = st; it && !v[it].e[c]; it = v[it].p) v[it].e[c] = wh;
        v.push_back(nd{v[st].l + 1, it ? v[it].e[c] : 1, v[0].e});
    }
} sam;

const int N=2e5+10;
int n;
char s[N],t[N];
void main() {
    R(n,s,t);
    REP(i,n) sam.push(s[i]-'a');
    int x=1,m=SZ(sam.v);
    VI ord(m),cnt(m);
    REP(i,n) {
        x=sam.v[x].e[s[i]-'a'];
        if ( t[i]=='0' ) cnt[x]++;
    }
    REP(i,SZ(ord)) ord[i]=i;
    sort(ALL(ord),[&]( int a, int b ) { return sam.v[a].l<sam.v[b].l; });
    for ( int ii=SZ(ord)-1; ii>=1; ii-- ) {
        int i=ord[ii];
        cnt[sam.v[i].p]+=cnt[i];
    }
    LL ans=0;
    REP1(i,2,SZ(sam.v)-1) {
        LL rb=sam.v[i].l;
        LL now=rb*cnt[i];
        chkmax(ans,now);
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}