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

const int N=1e5+10;
int n;
LL m,a[N],b[N],c[N],ord[N];

bool cmp( int x, int y ) {
    return abs(a[x]-b[x])>abs(a[y]-b[y]);
}

LL go( LL qa, LL qb ) {
    LL ans=0;
    LL ra=qa*m,rb=qb*m;

    auto take=[&]( LL &r, LL &cnt, LL &val ) {
        LL t=min(r,cnt);
        r-=t;
        cnt-=t;
        ans+=t*val;
    };

    REP(ii,n) {
        int i=ord[ii];
        LL cnt=c[i];
        if ( a[i]>b[i] ) {
            take(ra,cnt,a[i]);
            take(rb,cnt,b[i]);
        } else {
            take(rb,cnt,b[i]);
            take(ra,cnt,a[i]);
        }
        assert(cnt==0);
    }
    dump(qa,qb,ans);
    return ans;
}

void main() {
    R(n,m);
    REP(i,n) R(c[i],a[i],b[i]);
    LL sa=0,sb=0;
    REP(i,n) {
        if ( a[i]>b[i] ) sa+=c[i];
        else sb+=c[i];
    }
    LL sc=sa+sb;
    LL qa=(sa+m-1)/m;
    LL qb=(sb+m-1)/m;
    LL qc=(sc+m-1)/m;
    dump(sc,qa,qb,qc);
    if ( qa+qb==qc ) {
        LL ans=0;
        REP(i,n) ans+=c[i]*max(a[i],b[i]);
        W(ans);
    } else {
        REP(i,n) ord[i]=i;
        sort(ord,ord+n,cmp);
        LL a1=go(qa-1,qb);
        LL a2=go(qa,qb-1);
        LL ans=max(a1,a2);
        W(ans);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}