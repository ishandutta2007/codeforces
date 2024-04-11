#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
// #include <stdio.h>
#endif

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

struct MCMF {
    struct E { int to,c,w,r; };

    int n;
    vector<vector<E>> e;
    vector<vector<E>::iterator> cur;
    vector<int> dis;
    vector<char> vis;
    
    void init( int _n ) {
        n=_n;
        e.resize(n);
        for ( int i=0; i<n; i++ ) e[i].clear();
        cur.resize(n);
        dis.resize(n);
        vis.resize(n);
    }
    
    void add( int a, int b, int c, int w ) {
        // dump(a,b,c,w);
        e[a].push_back({b,c,w,(int)e[b].size()});
        e[b].push_back({a,0,-w,(int)e[a].size()-1});
    }
    
    int aug( int u, int f ) {
        if ( u==n-1 ) return f;
        vis[u]=1;
        int ret=0;
        for ( auto &it=cur[u]; it!=e[u].end(); it++ ) if ( it->c>0 ) {
            int v=it->to;
            if ( vis[v] || dis[u]!=dis[v]+it->w ) continue;
            int tf=aug(v,min(f-ret,it->c));
            ret+=tf;
            it->c-=tf;
            e[v][it->r].c+=tf;
            if ( ret==f ) break;
        }
        return ret;
    }
    
    bool relabel() {
        int d=INT_MAX;
        for ( int u=0; u<n; u++ ) if ( vis[u] )
            for ( auto &i:e[u] ) if ( i.c>0 && !vis[i.to] ) d=min(d,dis[i.to]+i.w-dis[u]);
        if ( d==INT_MAX ) return 0;
        for ( int i=0; i<n; i++ ) if ( vis[i] ) dis[i]+=d;
        return 1;
    }
    
    pair<int,int> mcmf() {
        int w=0,f=0;
        fill(dis.begin(),dis.end(),0);
        do {
            for ( int i=0; i<n; i++ ) cur[i]=e[i].begin();
            while ( 1 ) {
                fill(vis.begin(),vis.end(),0);
                int tf=aug(0,INT_MAX);
                if ( tf==0 ) break;
                w+=tf*dis[0];
                f+=tf;
            }
        } while ( relabel() );
        return {w,f};
    }
} mcmf;

struct DJS {
    vector<int> fa,sz;
    void init( int n ) {
        n++; // be nice for 1-index usage
        fa.resize(n);
        sz.resize(n);
        for ( int i=0; i<n; i++ ) sz[fa[i]=i]=1;
    }
    int f( int x ) {
        return x==fa[x]?x:fa[x]=f(fa[x]);
    }
    void u( int a, int b ) {
        a=f(a); b=f(b);
        if ( a==b ) return;
        if ( sz[a]>sz[b] ) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
    }
} djs;

const int N=2e5+10;
const int M=2e5+10;

struct E {
    int a,b,c;
} e[M];

bool operator<( const E &a, const E &b ) {
    return a.c>b.c;
}

int n,m;
bool vis[N];

int slow() {
    int s=0,l=1,r=l+m,t=r+n;
    mcmf.init(t+1);
    REP(i,m) {
        mcmf.add(s,l+i,1,0);
        mcmf.add(l+i,r+e[i].a-1,1,-e[i].c);
        mcmf.add(l+i,r+e[i].b-1,1,-e[i].c);
    }
    REP(i,n) mcmf.add(r+i,t,1,0);
    auto wf=mcmf.mcmf();
    // dump(wf);
    return -wf.first;
}

void main() {
    R(n,m);
    REP(i,m) R(e[i].a,e[i].b,e[i].c);
    sort(e,e+m);
    LL ans=0;
    djs.init(n);
    REP(i,m) {
        int a=djs.f(e[i].a);
        int b=djs.f(e[i].b);
        if ( vis[a] && vis[b] ) continue;
        if ( a==b ) vis[a]=1;
        else {
            djs.u(a,b);
            vis[a]|=vis[b];
            vis[b]|=vis[a];
        }
        ans+=e[i].c;
    }
    W(ans);
#ifdef SHIK
    auto slow_ans=slow();
    W(slow_ans);
    assert(slow_ans==ans);
#endif
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}