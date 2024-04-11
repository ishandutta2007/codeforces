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

LL gcd( LL a, LL b ) { return b==0 ? a : gcd(b,a%b); }
LL lcm( LL a, LL b ) { return a/gcd(a,b)*b; }

const int N=2e5+10;

int n,m;

struct P {
    int a,b;
    void read() {
        R(a,b);
        a--;
        b--;
        if ( a>b ) swap(a,b);
        int d1=b-a;
        int d2=n-d1;
        if ( d2<d1 ) swap(a,b);
    }
    int len() {
        return (b-a+n)%n;
    }
} p[N];

LL f( VI v ) {
    sort(ALL(v));
    REP1(i,1,SZ(v)-1) {
        int d=v[i]-v[0];
        if ( n%d!=0 ) continue;
        bool ok=1;
        REP(j,SZ(v)) {
            int k=(j+i)%SZ(v);
            if ( (v[k]-v[j]+n)%n!=d ) {
                ok=0;
                break;
            }
        }
        if ( ok ) return d;
    }
    return 0;
}

VI st[N];
void main() {
    R(n,m);
    REP(i,m) p[i].read();
    REP(i,m) {
        int l=p[i].len();
        st[l].PB(p[i].a);
        if ( l==n/2 ) st[l].PB(p[i].b);
    }
    LL l=1;
    REP(i,n) if ( !st[i].empty() ) {
        LL d=f(st[i]);
        if ( d==0 ) {
            W("No");
            return;
        }
        l=lcm(d,l);
        if ( l>=n ) break;
    }
    W(l<n ? "Yes" : "No");
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}