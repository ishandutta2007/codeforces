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

const int B=512;
const int N=1e5+10;
const int M=1e5+10;

struct Q {
    int l,r,id;
} q[M];

bool operator<( const Q &a, const Q &b ) {
    return MP(a.l/B,a.r)<MP(b.l/B,b.r);
}

int n,k,t[N],a[N],m,b[N][3],cnt[3*N];
LL s[N],sol[M];

void main() {
    R(n,k);
    REP1(i,1,n) R(t[i]);
    REP1(i,1,n) R(a[i]);
    R(m);
    REP(i,m) {
        R(q[i].l,q[i].r);
        q[i].id=i;
    }
    REP1(i,1,n) if ( t[i]==2 ) a[i]*=-1;
    REP1(i,1,n) s[i]=s[i-1]+a[i];
    vector<LL> v;
    REP1(i,0,n) REP1(j,-1,+1) v.PB(s[i]+j*k);
    sort_uniq(v);
    REP1(i,0,n) REP(j,3) b[i][j]=lower_bound(ALL(v),s[i]+(j-1)*k)-v.begin();
    LL now=0;
    cnt[b[0][1]]++;
    int l=1,r=0;
    sort(q,q+m);
    REP(i,m) {
        int ql=q[i].l,qr=q[i].r;
        // dump(i,ql,qr,l,r,now,cnt);
        while ( r<qr ) {
            r++;
            // now+=cnt[s[r]-k];
            now+=cnt[b[r][0]];
            cnt[b[r][1]]++;
        }
        while ( l>ql ) {
            l--;
            // now+=cnt[s[l-1]+k];
            now+=cnt[b[l-1][2]];
            cnt[b[l-1][1]]++;
        }
        while ( r>qr ) {
            cnt[b[r][1]]--;
            // now-=cnt[s[r]-k];
            now-=cnt[b[r][0]];
            r--;
        }
        while ( l<ql ) {
            cnt[b[l-1][1]]--;
            // now-=cnt[s[l-1]+k];
            now-=cnt[b[l-1][2]];
            l++;
        }
        sol[q[i].id]=now;
    }
    REP(i,m) W(sol[i]);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}