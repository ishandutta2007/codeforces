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

const int N=2e5+10;
char s[N],z[N];
int n;

bool solve( int p, array<int,10> c ) {
    c[z[p]-'0']++;
    dump(p,z,c);
    {
        int odd=0;
        REP(i,10) if ( c[i]%2==1 ) odd++;
        if ( odd>n-p-1 ) return 0;
    }
    REP1(i,p+1,n-1) {
        int odd=0;
        REP(j,10) if ( c[j]%2==1 ) odd++;
        dump(i,odd,n-i);
        if ( odd==n-i ) {
            int o=9;
            while ( o>=0 && c[o]%2==0 ) o--;
            dump(o,c[o]);
            assert(o>=0 && c[o]%2==1);
            c[o]++;
            z[i]=o+'0';
        } else if ( odd<n-i ) {
            c[9]++;
            z[i]='9';
        } else assert(0);
    }
    return 1;
}

bool solve( int p ) {
    REP(i,p) z[i]=s[i];
    array<int,10> c={};
    REP(i,p) c[z[i]-'0']++;
    for ( char d=s[p]-1; d>='0'; d-- ) {
        if ( d=='0' && p==0 ) continue;
        dump(d);
        z[p]=d;
        if ( solve(p,c) ) return 1;
    }
    return 0;
}

void solve() {
    for ( int i=n-1; i>=0 && i>=n-15; i-- ) {
        if ( solve(i) ) return;
    }
    assert(n>=4);
    REP(i,n-2) z[i]='9';
    z[n-2]=0;
}

void main() {
    int t;
    R(t);
    while ( t-- ) {
        R(s);
        n=strlen(s);
        REP(i,n+1) z[i]=0;
        solve();
        W(z);
        int c[10]={};
        int m=strlen(z);
        REP(i,m) c[z[i]-'0']++;
        REP(i,10) assert(c[i]%2==0);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}