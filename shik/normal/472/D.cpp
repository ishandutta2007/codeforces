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

#define N 2010
const int INF=2e9;
int n,d[N][N],dd[N];
bool vis[N];
vector<PII> e[N];
LL sd[N];
void dfs( int p, int f, LL s ) {
    sd[p]=s;
    FOR(it,e[p]) if ( it->first!=f ) {
        dfs(it->first,p,s+it->second);
    }
}
int main() {
    RI(n);
    REP(i,n) REP(j,n) RI(d[i][j]);
    REP(i,n) REP(j,n) if ( d[i][j]!=d[j][i] || (i==j && d[i][j]!=0) || (i!=j && d[i][j]==0) ) {
        puts("NO");
        return 0;
    }
    vis[0]=1;
    REP(i,n) dd[i]=d[0][i];
    REP(i,n-1) {
        int w=-1;
        REP(j,n) if ( !vis[j] && (w==-1 || dd[j]<dd[w]) ) w=j;
        if ( w==-1 ) {
            puts("NO");
            return 0;
        }
        REP(j,n) if ( vis[j] && d[j][w]==dd[w] ) {
            e[w].PB(MP(j,dd[w]));
            e[j].PB(MP(w,dd[w]));
            break;
        }
        vis[w]=1;
        REP(j,n) if ( !vis[j] && d[w][j]<dd[j] ) dd[j]=d[w][j];
    }
    REP(i,n) {
        dfs(i,-1,0);
        REP(j,n) if ( d[i][j]!=sd[j] ) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}