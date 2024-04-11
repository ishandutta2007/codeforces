// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

inline int min( int a, int b ) { return a<b?a:b; }

struct Maxflow {
    static const short INF=2e4;
    struct E {
        short to,cap,rev;
        E() {}
        E( short _to, short _cap, short _rev ):to(_to),cap(_cap),rev(_rev) {}
    };
    int n;
    vector< vector<E> > e;
    vector< vector<E>::iterator > cur;
    vector<short> dis;
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
    short go( int p, short c ) {
        if ( p==n-1 ) return c;
        short ret=0;
        for ( auto &it=cur[p]; it!=e[p].end(); it++ ) {
            if ( it->cap==0 || dis[it->to]!=dis[p]+1 ) continue;
            short now=go(it->to,min(it->cap,c-ret));
            ret+=now;
            it->cap-=now;
            e[it->to][it->rev].cap+=now;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    int maxflow() {
        int ret=0;
        while ( bfs() ) {
            REP(i,n) cur[i]=e[i].begin();
            ret+=go(0,INF);
        }
        return ret;
    }
} flow;

#define N 3010
int n,ea[N],eb[N],ec[N],ub[N];
vector<int> e[N];
short dis[N][N];
bool vis[N];
void dfs( int st, int p, int d, short _dis[N] ) {
    _dis[p]=d;
    FOR(it,e[p]) {
        int to=ea[*it]^eb[*it]^p;
        if ( !vis[to] ) {
            vis[to]=1;
            dfs(st,to,max(d,ec[*it]),_dis);
        }
    }
}
bool chk( int m ) {
    flow.init(2*n+2);
    REP1(i,1,n) flow.add(0,i,1);
    REP1(i,1,n) REP1(j,1,n) if ( dis[i][j]>=m ) flow.add(i,j+n,1);
    REP1(i,1,n) flow.add(i+n,n+n+1,ub[i]);
    return flow.maxflow()==n;
}
int main() {
    RI(n);
    REP(i,n-1) {
        RI(ea[i],eb[i],ec[i]);
        e[ea[i]].PB(i);
        e[eb[i]].PB(i);
    }
    REP1(i,1,n) RI(ub[i]);
    REP1(i,1,n) {
        memset(vis,0,sizeof(vis));
        dfs(i,i,0,dis[i]);
    }
    int l=0,r=10000;
    while ( l!=r ) {
        int m=(l+r+1)/2;
        if ( chk(m) ) l=m;
        else r=m-1;
    }
    printf("%d\n",l);
    return 0;
}