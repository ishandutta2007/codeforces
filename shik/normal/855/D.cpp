// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {
    _R(head);
    R(tail...);
}

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f\n", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) {
    for (auto i = x.begin(); i != x.end(); _W(*i++)) {
        if (i != x.cbegin()) putchar(' ');
    }
}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) {
    _W(head);
    putchar(sizeof...(tail) ? ' ' : '\n');
    W(tail...);
}
#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) {
    cerr << s << "=" << head << endl;
}
template<class T, class... Args>
void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...)                                                              \
    do {                                                                       \
        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);            \
        _dump(#__VA_ARGS__, __VA_ARGS__);                                      \
    } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
    return s << "(" << p.first << "," << p.second << ")";
}
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) {
    return _out(s, ALL(c));
}
template<class T, size_t N>
ostream &operator<<(ostream &s, const array<T, N> &c) {
    return _out(s, ALL(c));
}
template<class T> ostream &operator<<(ostream &s, const set<T> &c) {
    return _out(s, ALL(c));
}
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) {
    return _out(s, ALL(c));
}
#else
#define dump(...)
#endif

template<class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
    sort(begin(v), end(v), f);
    v.resize(unique(begin(v), end(v)) - begin(v));
}

template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

constexpr int lg2( int x ) { return 31-__builtin_clz(x); }

const int N=1e5+10;
const int LGN=lg2(N)+1;

int n;
VI e[N];

int dep[N],fa[LGN][N],dp[LGN][N];
void dfs( int p, int f, int lv ) {
    dep[p]=lv;
    fa[0][p]=f;
    for ( int i:e[p] ) if ( i!=f ) dfs(i,p,lv+1);
}

int lgn;
void lca_build() {
    for (int i = 0; i < lgn; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i + 1][j] = fa[i][fa[i][j]];
            dp[i + 1][j] = dp[i][j] | dp[i][fa[i][j]];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int d = dep[b] - dep[a];
    int l = lg2(dep[b]);
    for (int i = 0; i <= l; i++) {
        if ((d >> i) & 1) b = fa[i][b];
    }
    if (a == b) return a;
    for (int i = lg2(dep[a]); i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}

int get( int p, int f ) {
    int d=dep[p]-dep[f];
    int l=lg2(d);
    int ans=0;
    REP1(i,0,l) if ( (d>>i)&1 ) {
        ans|=dp[i][p];
        p=fa[i][p];
    }
    assert(p==f);
    return ans;
}

bool solve_1( int a, int b ) {
    if ( a==b ) return 0;
    int c=lca(a,b);
    if ( c!=a ) return 0;
    return get(b,a)==1;
}

bool solve_2( int a, int b ) {
    if ( a==b ) return 0;
    int c=lca(a,b);
    if ( c==0 || c==b ) return 0;
    if ( c!=a && get(a,c)!=1 ) return 0;
    return get(b,c)==2;
}

int main() {
    R(n);
    VI rt;
    REP1(i,1,n) {
        int par,tp;
        R(par,tp);
        if ( par==-1 ) {
            rt.PB(i);
        } else {
            e[par].PB(i);
            dp[0][i]=tp+1;
        }
    }
    for ( int i:rt ) dfs(i,0,1);
    lgn=lg2(n);
    lca_build();
    int q;
    R(q);
    while ( q-- ) {
        int op,a,b;
        R(op,a,b);
        bool ans=(op==1 ? solve_1(a,b) : solve_2(a,b));
        W(ans ? "YES" : "NO");
    }
    return 0;
}