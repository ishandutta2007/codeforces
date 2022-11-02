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
const int M=1010;
int n,m,nxt[N][26],fa[3][M],qp[M][3],ec[3][M];
VI e[3][M];
char wu[N];

int nq[3]={1,1,1};
vector<int> _dp;
int& dp( int a, int b, int c ) {
    return _dp[a*nq[1]*nq[2]+b*nq[2]+c];
}
void main() {
    R(n,m,wu);
    REP(i,26) nxt[n][i]=n;
    for ( int i=n-1; i>=0; i-- ) {
        REP(j,26) nxt[i][j]=nxt[i+1][j];
        nxt[i][wu[i]-'a']=i;
    }
    int p[3]={};
    REP(i,m) {
        char op;
        int id;
        R(op,id);
        id--;
        if ( op=='+' ) {
            char ch;
            R(ch);
            e[id][p[id]].PB(nq[id]);
            ec[id][nq[id]]=ch-'a';
            fa[id][nq[id]]=p[id];
            p[id]=nq[id]++;
        } else if ( op=='-' ) {
            p[id]=fa[id][p[id]];
        } else assert(0);
        REP(j,3) qp[i][j]=p[j];
        // dump(i,p[0],p[1],p[2]);
    }
    // dump(nq[0],nq[1],nq[2]);
    _dp.resize(nq[0]*nq[1]*nq[2]);
    for ( int &x:_dp ) x=n;
    dp(0,0,0)=-1;
    REP(i,nq[0]) REP(j,nq[1]) REP(k,nq[2]) {
        int me=dp(i,j,k);
        if ( me==n ) continue;
        // dump(i,j,k,me,e[0][i],e[1][j],e[2][k]);
        for ( int to:e[0][i] ) chkmin(dp(to,j,k),nxt[me+1][ec[0][to]]);
        for ( int to:e[1][j] ) chkmin(dp(i,to,k),nxt[me+1][ec[1][to]]);
        for ( int to:e[2][k] ) chkmin(dp(i,j,to),nxt[me+1][ec[2][to]]);
    }
    REP(i,m) {
        int x=dp(qp[i][0],qp[i][1],qp[i][2]);
        W(x<n?"YES":"NO");
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}