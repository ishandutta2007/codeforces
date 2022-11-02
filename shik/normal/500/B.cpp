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

#define N 314
int n,p[N],a[N][N];
bool vis[N];

VI v;
void go( int x ) {
    vis[x]=1;
    v.PB(x);
    REP1(i,1,n) if ( !vis[i] && a[x][i] ) go(i);
}

int main() {
    RI(n);
    REP1(i,1,n) RI(p[i]);
    REP1(i,1,n) REP1(j,1,n) scanf("%1d",a[i]+j);
    REP1(i,1,n) if ( !vis[i] ) {
        v.clear();
        go(i);
        sort(ALL(v));
        VI vv;
        FOR(it,v) vv.PB(p[*it]);
        sort(ALL(vv));
        REP(j,SZ(v)) p[v[j]]=vv[j];
    }
    REP1(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
    return 0;
}