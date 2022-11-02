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

int p;

inline int op1( int x ) {
    return x+1==p ? 0 : x+1;
}

inline int op2( int x ) {
    return x==0 ? p-1 : x-1;
}

inline int op3(int x) {
    int a = x, b = p, u = 1, v = 0;
    while (b != 0) {
        int t = a / b;
        a -= t * b;
        u -= t * v;
        swap(a, b);
        swap(u, v);
    }
    if ( u<0 ) u+=p;
    return u;
}

using Dis=unordered_map<int,PII>;

unordered_map<int,PII> BFS( int x0, int lim ) {
    unordered_map<int,PII> dis;
    dis[x0]={0,0};
    vector<int> que;
    que.PB(x0);
    REP(i,SZ(que)) {
        int x=que[i];
        int lv=dis[x].first;
        auto upd=[&]( auto f, int op ) {
            int nx=f(x);
            if ( dis.count(nx) ) return;
            dis[nx]={lv+1,op};
            if ( SZ(que)<lim ) que.push_back(nx);
        };
        upd(op1,1);
        upd(op2,2);
        if ( x!=0 ) upd(op3,3);
    }
    return dis;
}

VI trace( int st, int ed, Dis &dis ) {
    VI v;
    int x=ed;
    while ( x!=st ) {
        int op=dis[x].second;
        v.PB(op);
        if ( op==1 ) {
            x=op2(x);
        } else if ( op==2 ) {
            x=op1(x);
        } else if ( op==3 ) {
            x=op3(x);
        } else {
            assert(0);
        }
    }
    reverse(ALL(v));
    return v;
}

int u,v;
void main() {
    R(u,v,p);
    int lim=1<<18;
    while ( 1 ) {
        auto du=BFS(u,lim);
        auto dv=BFS(v,lim);
        for ( auto &i:du ) {
            int x=i.first;
            if ( !dv.count(x) ) continue;
            auto p1=trace(u,x,du);
            auto p2=trace(v,x,dv);
            reverse(ALL(p2));
            for ( auto &j:p2 ) if ( j==1 || j==2 ) j=3-j;
            VI sol;
            sol.insert(end(sol),ALL(p1));
            sol.insert(end(sol),ALL(p2));
            W(SZ(sol));
            W(sol);
            return;
        }
        lim*=2;
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}