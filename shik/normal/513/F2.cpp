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
    static const int INF=1e8;
    struct E {
        int to,cap,rev;
        E() {}
        E( int _to, int _cap, int _rev ):to(_to),cap(_cap),rev(_rev) {}
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
    int go( int p, int c ) {
        if ( p==n-1 ) return c;
        int ret=0;
        for ( auto &it=cur[p]; it!=e[p].end(); it++ ) {
            if ( it->cap==0 || dis[it->to]!=dis[p]+1 ) continue;
            int now=go(it->to,min(it->cap,c-ret));
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
} mf;

#define N 25
#define K 12345

int n,m,k1,k2,r[K],c[K],t[K];
char s[N][N];
void input() {
    RI(n,m,k1,k2);
    REP1(i,1,n) scanf("%s",s[i]+1);
    REP(i,k1+k2+1) RI(r[i],c[i],t[i]);
}

void BFS( int x, int y, int d[N][N] ) {
    const int dx[]={1,0,-1,0};
    const int dy[]={0,1,0,-1};
    static bool vis[N][N];
    memset(vis,0,sizeof(vis));
    queue<int> q;
    auto push=[&]( int xx, int yy, int dd ) {
        if ( s[xx][yy]!='.' ) return;
        if ( vis[xx][yy] ) return;
        vis[xx][yy]=1;
        q.push(xx);
        q.push(yy);
        d[xx][yy]=dd;
    };
    push(x,y,0);
    while ( !q.empty() ) {
        x=q.front(); q.pop();
        y=q.front(); q.pop();
        REP(i,4) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            push(nx,ny,d[x][y]+1);
        }
    }
}

int dis[N][N][N][N];
void build() {
    memset(dis,-1,sizeof(dis));
    REP1(i,1,n) REP1(j,1,m) if ( s[i][j]=='.' ) BFS(i,j,dis[i][j]);
    //REP1(i,1,n) REP1(j,1,m) REP1(x,1,n) REP1(y,1,m) if ( dis[i][j][x][y]!=-1 ) printf("%d,%d => %d,%d : %d\n",i,j,x,y,dis[i][j][x][y]);
}

void solve() {
    const LL INF=1e18;
    VI a,b;
    if ( k1+1==k2 ) a.PB(0);
    else if ( k1==k2+1 ) b.PB(0);
    else return puts("-1"),void();
    REP1(i,1,k1) a.PB(i);
    REP1(i,k1+1,k1+k2) b.PB(i);
    assert(SZ(a)==SZ(b));
    int z=SZ(a),sink=k1+k2+1+2*n*m+1;
    LL ll=0,rr=INF;
    while ( ll!=rr ) {
        LL mm=(ll+rr)/2;
        mf.init(sink+1);
        REP(i,z) mf.add(0,a[i]+1,1);
        REP(i,z) mf.add(b[i]+1,sink,1);
        REP1(x,1,n) REP1(y,1,m) if ( s[x][y]=='.' ) {
            int id=k1+k2+1+(x-1)*m+y;
            mf.add(id,id+n*m,1);
        }
        REP(i,z) REP1(x,1,n) REP1(y,1,m) if ( s[x][y]=='.' ) {
            int id=k1+k2+1+(x-1)*m+y;
            LL da=dis[r[a[i]]][c[a[i]]][x][y];
            LL db=dis[r[b[i]]][c[b[i]]][x][y];
            if ( da!=-1 && 1LL*t[a[i]]*da<=mm ) mf.add(a[i]+1,id,1);
            if ( db!=-1 && 1LL*t[b[i]]*db<=mm ) mf.add(id+n*m,b[i]+1,1);
        }
        int flow=mf.maxflow();
        if ( flow==z ) rr=mm;
        else ll=mm+1;
    }
    if ( ll==INF ) puts("-1");
    else cout<<ll<<endl;
}

int main() {
    input();
    build();
    solve();
    return 0;
}