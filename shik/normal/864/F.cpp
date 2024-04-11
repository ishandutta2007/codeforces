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

const int N=3010;
const int QN=4e5+10;

struct Q {
    int s,t,k;
} q[QN];

int n,m,qn,to[N];
bool con[N];
VI qt[N],e[N],re[N];

void bfs( int st ) {
    REP1(i,1,n) con[i]=0;
    static int que[N];
    int ql=0,qr=0;
    con[st]=1;
    que[qr++]=st;
    while ( ql!=qr ) {
        int p=que[ql++];
        for ( int i:re[p] ) if ( !con[i] ) {
            con[i]=1;
            que[qr++]=i;
        }
    }
}

VI qs[N],qe[N];
int stk[N],sol[QN];
void dfs( int p, int lv ) {
    stk[lv]=p;
    for ( int i:qs[p] ) {
        if ( q[i].k>lv ) sol[i]=-1;
        else sol[i]=stk[lv-q[i].k+1];
    }
    for ( int i:qe[p] ) dfs(i,lv+1);
}

int main() {
    R(n,m,qn);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        re[b].PB(a);
    }
    REP1(i,1,n) sort(ALL(e[i]));
    REP(i,qn) R(q[i].s,q[i].t,q[i].k);
    REP(i,qn) qt[q[i].t].PB(i);
    REP1(t,1,n) {
        bfs(t);
        dump(t,vector<bool>(con+1,con+n+1));
        REP1(i,1,n) {
            if ( i!=t && con[i] ) {
                to[i]=0;
                for ( int j:e[i] ) if ( con[j] ) {
                    to[i]=j;
                    break;
                }
                assert(to[i]);
            } else {
                to[i]=0;
            }
        }
        dump(VI(to+1,to+n+1));
        REP1(i,1,n) qe[i].clear();
        REP1(i,1,n) if ( to[i] ) qe[to[i]].PB(i);
        REP1(i,1,n) qs[i].clear();
        for ( int i:qt[t] ) qs[q[i].s].PB(i);
        dfs(t,1);
    }
    REP(i,qn) if ( !sol[i] ) sol[i]=-1;
    REP(i,qn) W(sol[i]);
    return 0;
}