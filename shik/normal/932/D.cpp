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

const int N=4e5+10;
const int L=19;
int n,last;

int fa[L][N],mx[L][N],nx[L][N],lv[N];
LL we[N],sm[L][N];

int get_nx( int p, int w ) {
    int q=fa[0][p];
    // dump(q,we[q],p,w);
    for ( int i=L-1; i>=0; i-- ) if ( mx[i][q]<w ) q=fa[i][q];
    assert(q==0 || we[q]>=w);
    return q;
}

void solve_add( int p, int w ) {
    n++;
    we[n]=w;

    fa[0][n]=p;
    REP(i,L-1) fa[i+1][n]=fa[i][fa[i][n]];

    mx[0][n]=w;
    REP(i,L-1) mx[i+1][n]=max(mx[i][fa[i][n]],mx[i][n]);

    nx[0][n]=get_nx(n,w);
    REP(i,L-1) nx[i+1][n]=nx[i][nx[i][n]];

    lv[n]=lv[nx[0][n]]+1;

    sm[0][n]=w;
    REP(i,L-1) sm[i+1][n]=sm[i][nx[i][n]]+sm[i][n];
    
    // dump(n,lv[n],we[n],fa[0][n],mx[0][n],nx[0][n],sm[0][n]);
}

int solve_ask( int p, LL u ) {
    int l=lv[p];
    int ans=0;
    for ( int i=L-1; i>=0; i-- ) {
        // dump(i,p,sm[i][p],u);
        if ( sm[i][p]<=u ) {
            u-=sm[i][p];
            p=nx[i][p];
            ans+=1<<i;
        }
    }
    chkmin(ans,l);
    return ans;
}

void main() {
    n++;
    lv[1]=1;
    int q;
    R(q);
    while ( q-- ) {
        int op;
        LL x,y;
        R(op,x,y);
        x^=last;
        y^=last;
        dump(op,x,y);
        assert(1<=x && x<=n);
        if ( op==1 ) {
            assert(0<=y && y<=1000000000);
            solve_add(x,y);
        } else if ( op==2 ) {
            assert(0<=y && y<=1000000000000000);
            int ans=solve_ask(x,y);
            W(ans);
            last=ans;
        } else assert(0);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}