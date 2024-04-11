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

typedef long double Double;

const int N=55;
const int T=5010;
int n,g,a[N],b[N],p[N],sb[N];

Double dp[N][T];
bool chk( Double m ) {
    REP1(i,0,sb[n]) dp[n][i]=(i<=g ? 0 : m);
    for ( int i=n-1; i>=0; i-- ) {
        Double pa=p[i]/Double(100);
        Double pb=1-pa;
        REP1(j,0,sb[i]) {
            auto t=pa*(a[i]+dp[i+1][j+a[i]])+pb*(b[i]+dp[i+1][j+b[i]]);
            dp[i][j]=min(t,m);
        }
    }
    // dump(m,dp[0][0]);
    return dp[0][0]<m;
}

void main() {
    R(n,g);
    REP(i,n) R(a[i],b[i],p[i]);
    REP1(i,1,n) sb[i]=sb[i-1]+b[i-1];
    Double l=0,r=1e9;
    REP(i,80) {
        auto m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m;
    }
    auto ans=(l+r)/2;
    printf("%.14f\n",(double)ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}