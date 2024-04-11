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
int n,a[N];

int al[N],ar[N];
PII hl[N];
int solve() {
    REP1(i,1,n) a[i]+=n-i+1;
    dump(VI(a+1,a+n+1));
    REP1(i,0,n) al[i]=INT_MAX;
    REP1(i,1,n) {
        int p=upper_bound(al,al+n+1,a[i])-al;
        hl[i]={p,al[p]};
        al[p]=a[i];
    }
    int mx=lower_bound(al,al+n+1,INT_MAX)-al;
    for ( int i=n; i>=1; i-- ) {
        int p=hl[i].first,v=hl[i].second;
        al[p]=v;
        int pr=upper_bound(ar,ar+n+1,v-1,greater<int>())-ar;
        dump(i,p,v,VI(al,al+n+1),VI(ar,ar+n+1),pr);
        chkmax(mx,p+pr);

        if ( i>1 ) {
            int z=hl[i-1].first;
            int zr=upper_bound(ar,ar+n+1,a[i-1]-1,greater<int>())-ar;
            dump(z,zr,a[i-1]-1);
            chkmax(mx,z+1+zr);
        }

        int q=upper_bound(ar,ar+n+1,a[i],greater<int>())-ar;
        int ql=upper_bound(al,al+n+1,a[i]+1)-al;
        chkmax(mx,q+ql);
        ar[q]=a[i];
    }
    return max(0,n-1-mx);
}

void main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    // int slow_ans=slow();
    int ans=solve();
    W(ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}