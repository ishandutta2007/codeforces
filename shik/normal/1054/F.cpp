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

#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

struct Maxflow {
    struct E {
        int to,cap,rev,rcap,ucap;
        E() {}
        E( int _to, int _cap, int _rev ):to(_to),cap(_cap),rev(_rev),rcap(_cap) {}
    };
    int n;
    vector< vector<E> > e;
    vector< vector<E>::iterator > cur;
    vector<int> dis;
    void init( int _n ) {
        n=_n;
        e.resize(n);
        cur.resize(n);
        dis.resize(n);
        REP(i,n) e[i].clear();
    }
    void add( int a, int b, int c ) {
        if ( a==b ) return;
        e[a].PB(E(b,c,e[b].size()));
        e[b].PB(E(a,0,e[a].size()-1));
    }
    bool bfs() {
        fill(dis.begin(),dis.end(),-1);
        queue<int> q;
        dis[0]=0; q.push(0);
        while ( !q.empty() && dis[n-1]==-1 ) {
            int p=q.front(); q.pop();
            FOR(it,e[p]) {
                if ( it->cap==0 || dis[it->to]!=-1 ) continue;
                dis[it->to]=dis[p]+1;
                q.push(it->to);
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0;
        for ( ; cur[p]!=e[p].end(); cur[p]++ ) {
            if ( cur[p]->cap==0 || dis[cur[p]->to]!=dis[p]+1 ) continue;
            LL now=go(cur[p]->to,min((LL)cur[p]->cap,c-ret));
            ret+=now;
            cur[p]->cap-=now;
            e[cur[p]->to][cur[p]->rev].cap+=now;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow() {
        LL ret=0;
        while ( bfs() ) {
            REP(i,n) cur[i]=e[i].begin();
            ret+=go(0,1LL<<60);
        }
        return ret;
    }
    bool _addPath(int wh, vector< vector<int> > &ans){
        if(wh == n - 1){
            ans.PB(vector<int>());
            ans.back().PB(wh);
            return true;
        }
        FOR(it, e[wh]) if(it->ucap > 0 && _addPath(it->to, ans)){
            it->ucap--;
            ans.back().PB(wh);
            return true;
        }
        return false;
    }
    vector< vector<int> > getPath(){
        vector< vector<int> > ans;
        FOR(it, e) FOR(jt, *it) jt->ucap = max(0, jt->rcap - jt->cap);
        while(_addPath(0, ans)) reverse(ans.back().begin(), ans.back().end());
        return ans;
    }
} flow;

// {{{ DJS
struct DJS {
    vector<int> fa, sz;
    DJS() {}
    DJS(int n) { init(n); }
    void init(int n) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int f(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        fa[a] = b;
        sz[b] += sz[a];
    }
    int size(int x) {
        return sz[f(x)];
    }
    bool is_root(int x) {
        return x == fa[x];
    }
    bool same(int a, int b) {
        return f(a) == f(b);
    }
};
// }}}

bool jiao( int x, int yl, int yr, int y, int xl, int xr ) {
    if ( x<xl || x>xr ) return 0;
    if ( y<yl || y>yr ) return 0;
    return 1;
}

const int N=1010;
int n,x[N],y[N],px[N],py[N];
bool ban[N][N];
VI ex[N],ey[N];
bool ma[N],mb[N];
set<PII> st;
VI gx[N],gy[N];

void main() {
    R(n);
    REP1(i,1,n) R(x[i],y[i]);
    REP1(i,1,n) REP1(j,1,n) if ( x[i]==x[j] && y[j]<y[i] && (px[i]==0 || y[j]>y[px[i]]) ) px[i]=j;
    REP1(i,1,n) REP1(j,1,n) if ( y[i]==y[j] && x[j]<x[i] && (py[i]==0 || x[j]>x[py[i]]) ) py[i]=j;
    REP1(i,1,n) st.insert({x[i],y[i]});
    int sink=2*n+1;
    flow.init(sink+1);
    REP1(i,1,n) flow.add(0,i,1);
    REP1(i,1,n) flow.add(n+i,sink,1);
    REP1(i,1,n) REP1(j,1,n) if ( i!=j ) {
        if ( !px[i] || !py[j] ) continue;
        if ( !jiao(x[i],y[px[i]],y[i],y[j],x[py[j]],x[j]) ) continue;
        if ( st.count({x[i],y[j]}) ) continue;
        ban[i][j]=1;
        ex[i].PB(j);
        ey[j].PB(i);
        flow.add(i,n+j,1);
    }
    int f=flow.maxflow();
    int cnt=0;
    REP1(i,1,n) cnt+=!!px[i]+!!py[i];
    cnt-=f;
    int ans=2*n-cnt;
    dump(ans);
    auto ps=flow.getPath();
    for ( auto p:ps ) {
        assert(SZ(p)==4);
        int a=p[1],b=p[2]-n;
        ma[a]=mb[b]=1;
    }
    set<int> sa,sb,ta,tb;
    REP1(i,1,n) if ( !ma[i] && px[i] ) sa.insert(i);
    REP1(i,1,n) if ( !mb[i] && py[i] ) sb.insert(i);
    REP1(k,1,n) {
        int z=SZ(sa)+SZ(sb)+SZ(ta)+SZ(tb);
        REP1(i,1,n) if ( sa.count(i) ) for ( int j:ex[i] ) tb.insert(j);
        REP1(i,1,n) if ( sb.count(i) ) for ( int j:ey[i] ) ta.insert(j);
        for ( auto p:ps ) {
            int a=p[1],b=p[2]-n;
            if ( ta.count(a) ) sb.insert(b);
            if ( tb.count(b) ) sa.insert(a);
        }
        if ( z==SZ(sa)+SZ(sb)+SZ(ta)+SZ(tb) ) break;
    }
    REP1(i,1,n) if ( px[i] && !sa.count(i) && !ta.count(i) ) sa.insert(i);
    dump(sa,sb);
    DJS dx(n),dy(n);
    for ( int i:sa ) dx.u(px[i],i);
    for ( int i:sb ) dy.u(py[i],i);
    REP1(i,1,n) gx[dx.f(i)].PB(y[i]);
    REP1(i,1,n) gy[dy.f(i)].PB(x[i]);
    vector<array<int,4>> tx,ty;
    REP1(i,1,n) if ( !gx[i].empty() ) {
        int mi=*min_element(ALL(gx[i]));
        int mx=*max_element(ALL(gx[i]));
        tx.PB({x[i],mi,x[i],mx});
    }
    REP1(i,1,n) if ( !gy[i].empty() ) {
        int mi=*min_element(ALL(gy[i]));
        int mx=*max_element(ALL(gy[i]));
        ty.PB({mi,y[i],mx,y[i]});
    }
    assert(SZ(tx)+SZ(ty)==ans);
    W(SZ(ty));
    for ( auto t:ty ) W(VI(ALL(t)));
    W(SZ(tx));
    for ( auto t:tx ) W(VI(ALL(t)));
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}