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

const int N=55;
int n,m,a[5][N];

vector<array<int,3>> sol;
void move( int id, int x1, int y1, int x2, int y2 ) {
    assert(a[x1][y1]==id);
    assert(abs(x1-x2)+abs(y1-y2)==1);
    assert(a[x2][y2]==0 || a[x2][y2]==id);
    sol.PB({id,x2,y2});
    a[x1][y1]=0;
    a[x2][y2]=id;
}

PII next( int x, int y ) {
    if ( x==2 ) {
        if ( y==1 ) return {3,1};
        else return {2,y-1};
    } else {
        if ( y==n ) return {2,n};
        else return {3,y+1};
    }
}

void main() {
    R(n,m);
    REP1(i,1,4) REP1(j,1,n) R(a[i][j]);
    int rem=m,x=2,y=1,iter=0;
    while ( rem>0 && iter<10000000 ) {
        iter++;
        auto [nx,ny]=next(x,y);
        int me=a[x][y];
        if ( me ) {
            int tx=(x==2 ? 1 : 4);
            if ( a[tx][y]==me ) {
                move(me,x,y,tx,y);
                rem--;
            } else if ( a[nx][ny]==0 ) {
                move(me,x,y,nx,ny);
            }
        }
        tie(x,y)=tie(nx,ny);
        assert(SZ(sol)<20000);
    }
    if ( iter>=10000000 ) {
        W(-1);
    } else {
        W(SZ(sol));
        for ( auto i:sol ) W(i[0],i[1],i[2]);
        REP1(i,1,n) assert(a[2][i]==0 && a[3][i]==0);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}