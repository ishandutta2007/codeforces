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

inline int two( int x ) { return 1<<x; }

const int L=70;
int l,dig[L];

LL dp[11][L][1<<10];
LL go( int b, int pos, bool any, int msk ) {
    if ( pos==-1 ) return msk==0;
    if ( any ) {
        auto memo=dp[b][pos][msk];
        if ( memo!=-1 ) return memo;
    }
    LL ans=0;
    int u=(any ? b-1 : dig[pos]);
    REP1(i,0,u) ans+=go(b,pos-1,any||i<u,msk^two(i));
    if ( any ) dp[b][pos][msk]=ans;
    // dump(b,pos,any,msk,ans);
    return ans;
}

void conv( int b, LL n ) {
    l=0;
    while ( n ) {
        dig[l++]=n%b;
        n/=b;
    }
    // dump(VI(dig,dig+l));
}

LL solve( int b, LL n ) {
    if ( n==0 ) return 0;
    conv(b,n);
    LL ans=0;
    REP(i,l) {
        int u=(i==l-1 ? dig[i] : b-1);
        REP1(j,1,u) {
            LL now=go(b,i-1,(i<l-1 || j<u),two(j));
            // dump(i,j,now);
            ans+=now;
        }
    }
    // dump(b,n,ans);
    return ans;
}

int main() {
    memset(dp,-1,sizeof(dp));
    int q;
    R(q);
    while ( q-- ) {
        int b;
        LL lb,rb;
        R(b,lb,rb);
        auto ans=solve(b,rb)-solve(b,lb-1);
        W(ans);
    }
    return 0;
}