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

const int N=3e5+10;
const int M=3e5+10;

struct E {
    int a,b;
};

int n,m,st;
VI de[N],ue[N];
vector<E> ues;

bool rev_mx[M];
bool vis_mx[N];
void dfs_mx( int p ) {
    vis_mx[p]=1;
    for ( int i:de[p] ) if ( !vis_mx[i] ) dfs_mx(i);
    for ( int i:ue[p] ) {
        int to=p^ues[i].a^ues[i].b;
        if ( vis_mx[to] ) continue;
        rev_mx[i]=(p==ues[i].b);
        dfs_mx(to);
    }
}
void solve_max() {
    dfs_mx(st);
    int ans=count(vis_mx+1,vis_mx+n+1,true);
    W(ans);
    REP(i,SZ(ues)) putchar(rev_mx[i] ? '-' : '+');
    W("");
}

bool rev_mi[M];
bool vis_mi[N];
void dfs_mi( int p ) {
    vis_mi[p]=1;
    for ( int i:de[p] ) if ( !vis_mi[i] ) dfs_mi(i);
    for ( int i:ue[p] ) {
        int to=p^ues[i].a^ues[i].b;
        if ( vis_mi[to] ) continue;
        rev_mi[i]=(p==ues[i].a);
    }
}
void solve_min() {
    dfs_mi(st);
    int ans=count(vis_mi+1,vis_mi+n+1,true);
    W(ans);
    REP(i,SZ(ues)) putchar(rev_mi[i] ? '-' : '+');
    W("");
}

void main() {
    R(n,m,st);
    REP(i,m) {
        int t,a,b;
        R(t,a,b);
        if ( t==1 ) {
            de[a].PB(b);
        } else {
            int id=SZ(ues);
            ue[a].PB(id);
            ue[b].PB(id);
            ues.PB({a,b});
        }
    }
    solve_max();
    solve_min();
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}