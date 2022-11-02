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
struct DJS {
    int fa[N];
    void init( int n ) {
        REP1(i,1,n) fa[i]=i;
    }
    int Find( int x ) {
        return x==fa[x]?x:fa[x]=Find(fa[x]);
    }
    void Union( int a, int b ) {
        fa[Find(a)]=Find(b);
    }
} djs;

int n,m,par[N];
vector<int> e[N];

bool vis[N];
vector<int> sol;
int go( int p ) {
    vis[p]=1;
    int c=0;
    sol.PB(p); c^=1;
    FOR(it,e[p]) if ( !vis[*it] ) {
        int ret=go(*it);
        sol.PB(p); c^=1;
        if ( ret!=par[*it] ) {
            sol.PB(*it);
            sol.PB(p); c^=1;
        }
    }
    return c;
}

int main() {
    RI(n,m);
    djs.init(n);
    REP(i,m) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
        djs.Union(a,b);
    }
    REP1(i,1,n) RI(par[i]);
    int p1=find(par+1,par+n+1,1)-par;
    if ( p1==n+1 ) return puts("0"),0;
    REP1(i,1,n) if ( par[i]==1 && djs.Find(p1)!=djs.Find(i) ) return puts("-1"),0;
    if ( go(p1)!=par[p1] ) sol.pop_back();
    printf("%d\n",SZ(sol));
    REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    return 0;
}