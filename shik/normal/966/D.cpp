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

const int N=3e5+10;
int n,m;
VI e[N];

int ans;
VI sol;

int bd[N],pre[N];
void BFS() {
    REP1(i,1,n) bd[i]=N;
    queue<int> q;
    auto push=[&]( int f, int x, int d ) {
        if ( bd[x]!=N ) return;
        q.push(x);
        bd[x]=d;
        pre[x]=f;
    };
    push(0,1,0);
    while ( !q.empty() ) {
        int p=q.front(); q.pop();
        for ( int i:e[p] ) push(p,i,bd[p]+1);
    }
    if ( chkmin(ans,bd[n]) ) {
        VI v;
        for ( int i=n; i; i=pre[i] ) v.PB(i);
        reverse(ALL(v));
        sol=v;
    }
}

bool has( int a, int b ) {
    return binary_search(ALL(e[a]),b);
}

void chk4() {
    if ( ans<=4 ) return;
    REP1(i,1,n) if ( bd[i]==2 ) {
        ans=4;
        sol={1,pre[i],i,1,n};
        return;
    }
}

VI cc;
bool vis[N];
void go( int p ) {
    cc.PB(p);
    vis[p]=1;
    for ( int i:e[p] ) if ( !vis[i] ) go(i);
}

bool chk_cc() {
    if ( SZ(cc)<3 ) return 0;
    REP(i,SZ(cc)) {
        REP(j,i) {
            if ( !has(cc[i],cc[j]) ) {
                assert(i>=2);
                bool found=0;
                REP(k,SZ(cc)) if ( has(cc[i],cc[k]) && has(cc[j],cc[k]) ) {
                    assert(!has(cc[i],n));
                    found=1;
                    ans=5;
                    sol={1,cc[i],cc[k],cc[j],cc[i],n};
                    return 1;
                }
                assert(found);
            }
        }
    }
    return 0;
}

void chk5() {
    if ( ans<=5 ) return;
    vis[1]=1;
    REP1(i,1,n) if ( bd[i]==1 && !vis[i] ) {
        cc.clear();
        go(i);
        if ( chk_cc() ) return;
    }
}

void main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    REP1(i,1,n) sort(ALL(e[i]));

    if ( has(1,n) ) {
        W(1);
        W(1,n);
        return;
    }

    ans=N;
    BFS();
    chk4();
    chk5();

    if ( ans==N ) {
        W(-1);
    } else {
        W(ans);
        W(sol);
#ifdef SHIK
        map<int,int> mp;
        assert(sol[0]==1);
        assert(sol.back()==n);
        REP(i,SZ(sol)-1) {
            int a=sol[i],b=sol[i+1];
            if ( mp[a]^mp[b] ) {
                assert(!has(a,b));
            } else {
                assert(has(a,b));
            }
            mp[a]^=1;
        }
#endif
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}