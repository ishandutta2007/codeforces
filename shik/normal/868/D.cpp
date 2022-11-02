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

const int L=14;
struct P {
    set<uint32_t> st[L+1];
    string l,r;
    void add( const string &s ) {
        REP(i,SZ(s)) {
            uint32_t x=0;
            REP1(j,1,L) {
                if ( i+j>SZ(s) ) break;
                x=x*2+(s[i+j-1]-'0');
                st[j].insert(x);
            }
        }
    }
    P() {}
    P( string s ) {
        if ( SZ(s)<=L ) {
            l=r=s;
        } else {
            l=s.substr(0,L);
            r=s.substr(SZ(s)-L);
        }
        st[0].insert(0);
        add(s);
    }
    int lv() {
        int x=0;
        while ( x<L && SZ(st[x])==(1<<x) ) x++;
        assert(x!=L);
        return x-1;
    }
};

P operator+( const P &a, const P &b ) {
    P c;
    c.l=(a.l+b.l);
    c.r=(a.r+b.r);
    if ( SZ(c.l)>L ) c.l=c.l.substr(0,L);
    if ( SZ(c.r)>L ) c.r=c.r.substr(SZ(c.r)-L);
    REP(i,L) {
        c.st[i].insert(ALL(a.st[i]));
        c.st[i].insert(ALL(b.st[i]));
    }
    c.add(a.r+b.l);
    return c;
}

const int N=210;

int n,m;
string s[N];
P p[N];
void main() {
    R(n);
    REP1(i,1,n) R(s[i]);
    REP1(i,1,n) p[i]=s[i];
    R(m);
    REP1(i,1,m) {
        int a,b;
        R(a,b);
        p[n+i]=p[a]+p[b];
        int ans=p[n+i].lv();
        W(ans);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}