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

const int N=510;
int n,m,t,a[N][N],b[N][N],dp[N][N];
void main() {
    R(n,m,t);
    REP1(i,1,n) REP1(j,1,m) scanf("%1d",a[i]+j);
    REP1(i,1,n) {
        int tot=0;
        REP1(j,1,m) tot+=a[i][j];
        b[i][0]=tot;
        REP1(j,1,m) b[i][j]=INT_MAX;
        REP1(j,1,m) {
            int s=0;
            REP1(k,j,m) {
                s+=a[i][k];
                chkmin(b[i][k-j+1],tot-s);
            }
        }
    }
    REP1(i,1,n+1) REP1(j,0,t) dp[i][j]=INT_MAX;
    dp[1][t]=0;
    REP1(i,1,n) REP1(j,0,t) {
        int me=dp[i][j];
        if ( me==INT_MAX ) continue;
        REP1(k,0,m) if ( b[i][k]<=j ) chkmin(dp[i+1][j-b[i][k]],me+k);
    }
    int ans=INT_MAX;
    REP1(i,0,t) chkmin(ans,dp[n+1][i]);
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}