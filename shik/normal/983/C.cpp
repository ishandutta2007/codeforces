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

const int L=715;
const int N=2001;

int tbl[10][10][10][10];
void predo() {
    int id=0;
    REP(i,10000) {
        int x=i,a[4];
        REP(j,4) {
            a[j]=x%10;
            x/=10;
        }
        if ( is_sorted(ALL(a)) ) {
            tbl[a[0]][a[1]][a[2]][a[3]]=id++;
        }
    }
    dump(id);
    assert(id==L);
}


int n,a[N],b[N];
int dp[9][N][L];

struct P {
    int lv,nx,in[4];
    int& operator()() const {
        return dp[lv-1][nx][tbl[in[0]][in[1]][in[2]][in[3]]];
    }
    void open() {
        bool f=0;
        REP(i,4) if ( in[i]==lv ) {
            in[i]=0;
            f=1;
        }
        if ( f ) sort(ALL(in));
        while ( in[0]==0 && nx<n && a[nx]==lv ) {
            in[0]=b[nx++];
            sort(ALL(in));
        }
    }
};

void main() {
    predo();
    R(n);
    REP(i,n) R(a[i],b[i]);
    memset(dp,-1,sizeof(dp));
    queue<P> q;
    auto push=[&]( P p, int nd ) {
        p.open();
        int &d=p();
        if ( d!=-1 ) return;
        d=nd;
        q.push(p);
    };
    push({1,0,{0,0,0,0}},0);
    while ( !q.empty() ) {
        auto p=q.front(); q.pop();
        int d=p();
        if ( p.lv<9 ) {
            p.lv++;
            push(p,d+1);
            p.lv--;
        }
        if ( p.lv>1 ) {
            p.lv--;
            push(p,d+1);
            p.lv++;
        }
    }
    int ans=INT_MAX;
    REP(i,9) chkmin(ans,dp[i][n][0]);
    ans+=2*n;
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}