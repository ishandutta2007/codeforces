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

#define N 100010
const LL INF=1e16;

struct E {
    int to,c;
};

vector<E> e[N];
LL dis[N];
int frm[N];

int main() {
    int n,m;
    RI(n,m);
    REP(i,m) {
        int a,b,c;
        RI(a,b,c);
        e[a].PB(E{b,c});
        e[b].PB(E{a,c});
    }
    REP1(i,1,n) dis[i]=INF;
    priority_queue<pair<LL,int>> q;
    dis[1]=0;
    q.push(MP(0,1));
    while ( !q.empty() ) {
        auto p=q.top().second;
        auto d=-q.top().first;
        q.pop();
        if ( dis[p]!=d ) continue;
        FOR(it,e[p]) if ( dis[p]+it->c<dis[it->to] ) {
            dis[it->to]=dis[p]+it->c;
            frm[it->to]=p;
            q.push(MP(-dis[it->to],it->to));
        }
    }
    if ( dis[n]==INF ) puts("-1");
    else {
        vector<int> path;
        for ( int i=n; i; i=frm[i] ) path.PB(i);
        reverse(ALL(path));
        REP(i,SZ(path)) printf("%d%c",path[i],i+1==SZ(path)?'\n':' ');
    }
    return 0;
}