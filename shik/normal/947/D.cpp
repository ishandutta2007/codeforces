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

void build( int n, char s[N], int a[N], int bc[N] ) {
    REP1(i,1,n) a[i]=(s[i]=='A' ? a[i-1]+1 : 0);
    REP1(i,1,n) bc[i]=bc[i-1]+(s[i]=='B' || s[i]=='C');
}

bool solve( int as, int at, int bcs, int bct ) {
    if ( bcs==0 && bct>0 ) {
        REP1(i,1,3) if ( i<=as && solve(as-i,at,2,bct) ) return 1;
        return 0;
    }
    if ( bcs>bct ) return 0;
    if ( bcs%2!=bct%2 ) return 0;
    if ( as<at ) return 0;
    if ( as%3!=at%3 && bcs==bct ) return 0;
    return 1;
}

char s[N],t[N];
int as[N],at[N],bcs[N],bct[N];

void main() {
    // REP(i,4) REP(j,4) REP(k,3) REP(l,3) if ( i+k>0 && j+l>0 ) dump(i,j,k,l,solve(i,j,k,l));
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1);
    int m=strlen(t+1);
    build(n,s,as,bcs);
    build(m,t,at,bct);
    string ans;
    int q;
    R(q);
    REP(iq,q) {
        int l1,r1,l2,r2;
        R(l1,r1,l2,r2);
        dump(string(s+l1,s+r1+1),string(t+l2,t+r2+1));
        int xs=bcs[r1]-bcs[l1-1];
        int xt=bct[r2]-bct[l2-1];
        bool ok=solve(min(as[r1],r1-l1+1),min(at[r2],r2-l2+1),xs,xt);
        // assert(ok);
        ans.PB(ok ? '1' : '0');
    }
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}