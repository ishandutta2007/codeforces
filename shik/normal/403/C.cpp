// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

int n,e1[N][N],e2[N][N];
bool v1[N],v2[N];
void dfs( int p, int e[N][N], bool v[N] ) {
    v[p]=1;
    REP1(i,1,n) if ( !v[i] && e[p][i] ) dfs(i,e,v);
}
int main() {
    RI(n);
    REP1(i,1,n) REP1(j,1,n) RI(e1[i][j]);
    REP1(i,1,n) REP1(j,1,n) e2[i][j]=e1[j][i];
    dfs(1,e1,v1);
    dfs(1,e2,v2);
    bool good=1;
    REP1(i,1,n) if ( !v1[i] || !v2[i] ) good=0;
    puts(good?"YES":"NO");
    return 0;
}