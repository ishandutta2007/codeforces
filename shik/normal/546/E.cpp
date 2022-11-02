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

#define N 110
#define INF 123456
int x[N],y[N],sol[N][N];
VI e[N];
int main() {
    int n,m;
    RI(n,m);
    REP1(i,1,n) RI(x[i]);
    REP1(i,1,n) RI(y[i]);
    REP(i,m) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    flow.init(2*n+2);
    REP1(i,1,n) flow.add(0,i,x[i]);
    REP1(i,1,n) flow.add(i,i+n,INF);
    REP1(i,1,n) for ( int j:e[i] ) flow.add(i,j+n,INF);
    REP1(i,1,n) flow.add(i+n,2*n+1,y[i]);
    int f=flow.maxflow();
    int sx=0,sy=0;
    REP1(i,1,n) sx+=x[i];
    REP1(i,1,n) sy+=y[i];
    if ( sx!=sy || f!=sx ) {
        puts("NO");
        return 0;
    }
    puts("YES");
    auto ps=flow.getPath();
    for ( auto p:ps ) {
        assert(SZ(p)==4);
        sol[p[1]][p[2]-n]++;
    }
    REP1(i,1,n) REP1(j,1,n) printf("%d%c",sol[i][j],j==n?'\n':' ');
    return 0;
}