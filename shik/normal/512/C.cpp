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

#define S 51400
bool pt[S];
void predo() {
    for ( int i=2; i<S; i++ ) if ( !pt[i] )
        for ( int j=i+i; j<S; j+=i ) pt[j]=1;
}

#define N 210

int n,a[N];
VI e[N],sol;
bool vis[N];

void dfs( int p ) {
    sol.PB(p);
    vis[p]=1;
    FOR(it,e[p]) if ( !vis[*it] ) {
        dfs(*it);
        break;
    }
}

int main() {
    predo();
    RI(n);
    REP1(i,1,n) RI(a[i]);
    int sink=n+1;
    flow.init(sink+1);
    REP1(i,1,n) {
        if ( a[i]%2==0 ) flow.add(0,i,2);
        else flow.add(i,sink,2);
    }
    REP1(i,1,n) if ( a[i]%2==0 ) REP1(j,1,n) if ( !pt[a[i]+a[j]] ) flow.add(i,j,1);
    int mf=flow.maxflow();
    if ( mf!=n ) {
        puts("Impossible");
        return 0;
    }
    auto ps=flow.getPath();
    FOR(it,ps) {
        //FOR(jt,*it) printf("%d ",*jt); puts("");
        assert(SZ(*it)==4);
        int x=it->at(1);
        int y=it->at(2);
        e[x].PB(y);
        e[y].PB(x);
    }
    REP1(i,1,n) assert(SZ(e[i])==2);
    vector<VI> sols;
    REP1(i,1,n) if ( !vis[i] ) {
        sol.clear();
        dfs(i);
        assert(SZ(sol)%2==0 && SZ(sol)>=4);
        sols.PB(sol);
    }
    printf("%d\n",SZ(sols));
    for (auto &s : sols) {
        printf("%d",SZ(s));
        FOR(it,s) printf(" %d",*it);
        puts("");
    }
    return 0;
}