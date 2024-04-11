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

// {{{ SCC
struct SCC {
    int n;
    vector<vector<int>> e1, e2, scc;
    vector<int> grp, ord;
    void init(int _n) {
        n = _n;
        e1.clear();
        e1.resize(n);
        e2.clear();
        e2.resize(n);
    }
    void add(int a, int b) {
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    void dfs1(int u) {
        grp[u] = -1;
        for (int v : e1[u]) if (grp[v] == 0) dfs1(v);
        ord.push_back(u);
    }
    void dfs2(int u) {
        grp[u] = scc.size() - 1;
        scc.back().push_back(u);
        for (int v : e2[u]) if (grp[v] == -1) dfs2(v);
    }
    void solve() {
        grp.clear();
        grp.resize(n);
        ord.clear();
        ord.reserve(n);
        for (int i = 0; i < n; i++) if (grp[i] == 0) dfs1(i);
        reverse(ord.begin(), ord.end());
        scc.clear();
        grp.resize(n);
        for (int i : ord) if (grp[i] == -1) {
            scc.emplace_back();
            dfs2(i);
        }
    }
};
// }}}
// 2SAT {{{
struct TwoSAT {
    template<class T> struct BinOp;
    struct Imply {}; struct And {}; struct Or {}; struct Xor {};
    struct Var {
        int id;
        Var(int x, bool v = true) : id(2 * x + v) {}
        Var operator!() const { return Var(id / 2, 1 - id % 2); }
        operator int() const { return id; }
        BinOp<Imply> operator>>(Var rhs) const { return {*this, rhs}; }
        BinOp<And> operator&&(Var rhs) const { return {*this, rhs}; }
        BinOp<Or> operator||(Var rhs) const { return {*this, rhs}; }
        BinOp<Xor> operator^(Var rhs) const { return {*this, rhs}; }
    };
    template<class T> struct BinOp { Var a, b; };
    int n;
    vector<bool> var;
    SCC scc;
    void init(int _n) {
        n = _n;
        scc.init(2 * n);
    }
    void add(Var x) {
        scc.add(!x, x);
    }
    void add(BinOp<Imply> p) {
        scc.add(p.a, p.b);
        scc.add(!p.b, !p.a);
    }
    void add(BinOp<And> p) {
        add(p.a);
        add(p.b);
    }
    void add(BinOp<Or> p) {
        add(BinOp<Imply>{!p.a, p.b});
    }
    void add(BinOp<Xor> p) {
        add(BinOp<Imply>{p.a, !p.b});
        add(BinOp<Imply>{!p.a, p.b});
    }
    bool solve() {
        scc.solve();
        var.clear();
        for (int i = 0; i < n; i++) if (scc.grp[2 * i] == scc.grp[2 * i + 1]) return false;
        var.resize(n);
        for (int i = 0; i < n; i++) var[i] = (scc.grp[2 * i] < scc.grp[2 * i + 1]);
        return true;
    }
};
// }}}

const int N=1e5+10;
const int M=1e5+10;

int n,m,l[N];
VI s[N];

VI sol;
bool solve() {
    TwoSAT sat;
    sat.init(m);
    using v=TwoSAT::Var;
    REP(i,n-1) {
        int x=0;
        while ( x<l[i] && x<l[i+1] && s[i][x]==s[i+1][x] ) x++;
        if ( x==l[i] ) continue;
        if ( x==l[i+1] ) return 0;
        int c1=s[i][x];
        int c2=s[i+1][x];
        auto v1=v(c1),v2=v(c2);
        if ( c1<c2 ) {
            sat.add(v2 >> v1);
        } else {
            sat.add(v1 && !v2);
        }
    }
    if ( !sat.solve() ) return 0;
    REP(i,m) if ( sat.var[i] ) sol.PB(i+1);
    return 1;
}

void main() {
    R(n,m);
    REP(i,n) {
        R(l[i]);
        s[i].resize(l[i]);
        REP(j,l[i]) R(s[i][j]);
    }
    REP(i,n) for ( auto &j:s[i] ) j--;
    if ( solve() ) {
        W("Yes");
        W(SZ(sol));
        W(sol);
    } else {
        W("No");
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}