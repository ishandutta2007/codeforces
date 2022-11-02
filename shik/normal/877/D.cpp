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

const int N=1010;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

struct P {
    unsigned x:10,y:10,z:2;
    bool operator<( const P& ) const { return false; }
};

int n,m,k,sx,sy,ex,ey;
char s[N][N];
int dis[N][N][4];

inline bool out( int x, int y ) {
    return x<1 || x>n || y<1 || y>m;
}

void main() {
    R(n,m,k);
    REP1(i,1,n) scanf("%s",s[i]+1);
    R(sx,sy,ex,ey);
    if ( sx==ex && sy==ey ) {
        W(0);
        return;
    }
    REP1(i,1,n) REP1(j,1,m) REP(z,4) dis[i][j][z]=INT_MAX;
    MinHeap<pair<int,P>> h;
    auto push=[&]( unsigned x, unsigned y, unsigned z, int d ) {
        if ( chkmin(dis[x][y][z],d) ) h.push({d,{x,y,z}});
    };
    REP(i,4) push(sx,sy,i,1<<10);
    while ( !h.empty() ) {
        auto p=h.top().second;
        auto d=h.top().first;
        h.pop();
        if ( d!=dis[p.x][p.y][p.z] ) continue;
        // dump((int)p.x,(int)p.y,(int)p.z,d);
        REP(i,4) {
            auto x=p.x+dx[i];
            auto y=p.y+dy[i];
            if ( out(x,y) || s[x][y]!='.' ) continue;
            auto nd=(i==p.z && (d&1023)<k ? d+1 : (d&~1023)+1025);
            push(x,y,i,nd);
        }
    }
    int ans=INT_MAX>>10;
    REP(i,4) chkmin(ans,dis[ex][ey][i]>>10);
    W(ans==INT_MAX>>10 ? -1 : ans);
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}