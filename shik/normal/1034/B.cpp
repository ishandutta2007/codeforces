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

template<class T = int>
struct MaxFlow {
    struct E {
        int to, rev;
        T cap;
    };
    int n;
    vector<vector<E>> e;
    vector<int> cur, dis;
    void init(int _n) {
        n = _n;
        e.clear();
        e.resize(n);
        cur.resize(n);
        dis.resize(n);
    }
    template<bool dir>
    void _add(int a, int b, T c) {
        if (a == b) return;
        e[a].push_back(E{b, (int)e[b].size() - 0, c});
        e[b].push_back(E{a, (int)e[a].size() - 1, dir ? 0 : c});
    }
    void add(int a, int b, T c) {
        _add<true>(a, b, c);
    }
    void add_bi(int a, int b, T c) {
        _add<false>(a, b, c);
    }
    bool bfs(int s, int t) {
        memset(dis.data(), -1, dis.size() * sizeof(dis[0]));
        dis[s] = 0;
        vector<int> que{s};
        for (size_t i = 0; i < que.size() && dis[t] == -1; i++) {
            auto p = que[i];
            for (auto &j : e[p]) {
                if (j.cap == 0 || dis[j.to] != -1) continue;
                dis[j.to] = dis[p] + 1;
                que.push_back(j.to);
            }
        }
        return dis[t] != -1;
    }
    T go(int p, T c, int t) {
        if (p == t) return c;
        T ret = 0;
        for (size_t i = cur[p]; i < e[p].size() && ret < c; i++) {
            auto &ei = e[p][i];
            if (ei.cap == 0 || dis[ei.to] <= dis[p]) continue;
            auto f = go(ei.to, min(ei.cap, c - ret), t);
            ret += f;
            ei.cap -= f;
            e[ei.to][ei.rev].cap += f;
        }
        if (ret == 0) dis[p] = -1;
        return ret;
    }
    T maxflow(int s, int t) {
        T f = 0;
        while (bfs(s, t)) {
            memset(cur.data(), 0, cur.size() * sizeof(cur[0]));
            f += go(s, numeric_limits<T>::max(), t);
        }
        return f;
    }
    T maxflow() { return maxflow(0, n - 1); }
};

MaxFlow<> flow;

int naive( int n, int m ) {
    auto id=[&]( int x, int y ) {
        return (x-1)*m+y;
    };
    int sink=n*m+1;
    flow.init(sink+1);
    REP1(i,1,n) REP1(j,1,m) {
        int me=id(i,j);
        if ( (i+j)%2==0 ) {
            flow.add(0,me,1);
            REP1(dx,-3,+3) REP1(dy,-3,+3) if ( abs(dx)+abs(dy)==3 ) {
                int x=i+dx;
                int y=j+dy;
                if ( x<1 || x>n || y<1 || y>m ) continue;
                flow.add(me,id(x,y),1);
            }
        } else {
            flow.add(me,sink,1);
        }
    }
    return 2*flow.maxflow();
}

LL solve( LL n, LL m ) {
    if ( n>m ) swap(n,m);
    if ( n*m<=1000 ) return naive(n,m);
    if ( n==1 ) {
        const int t[]={0,1,2,3,2,1};
        return m-t[m%6];
    }
    return n*m-n*m%2;
}

void main() {
    // REP1(i,1,50) REP1(j,1,50) {
    //     int a1=naive(i,j);
    //     int a2=solve(i,j);
    //     assert(a1==a2);
    // }
    LL n,m;
    R(n,m);
    auto ans=solve(n,m);
    W(ans) ;
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}