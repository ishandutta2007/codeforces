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

const int N=3010;
int n,a[N],ord[N],b[N],sol[N];
PII dp[N][N];

bool cmp( int x, int y ) {
    return a[x]>a[y];
}

void main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) ord[i]=i;
    sort(ord+1,ord+n+1,cmp);
    REP1(i,1,n) b[i]=a[ord[i]]-a[ord[i+1]];
    REP1(i,1,n) {
        dp[i][i]={b[i],i};
        REP1(j,i+1,n) dp[i][j]=max(dp[i][j-1],{b[j],j});
    }
    array<int,6> mx{{-1,-1,-1,-1,-1,-1}};
    REP1(i,1,n) REP1(j,i+1,n) {
        int n1=i,n2=j-i;
        if ( max(n1,n2)>2*min(n1,n2) ) continue;
        int l3=(max(n1,n2)+1)/2;
        int r3=min(n1,n2)*2;
        int kl=j+l3;
        int kr=min(j+r3,n);
        if ( kl>kr ) continue;
        int k=dp[kl][kr].second;
        int n3=k-j;
        assert(n1>0 && n2>0 && n3>0 && max({n1,n2,n3})<=2*min({n1,n2,n3}));
        array<int,6> now{{b[i],b[j],b[k],i,j,k}};
        chkmax(mx,now);
    }
    assert(mx[0]!=-1);
    dump(mx);
    REP1(i,1,n) {
        auto &r=sol[ord[i]];
        if ( i<=mx[3] ) r=(1);
        else if ( i<=mx[4] ) r=(2);
        else if ( i<=mx[5] ) r=(3);
        else r=(-1);
    }
    W(VI(sol+1,sol+n+1));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}