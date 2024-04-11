// shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }

#define N 410
int n,m,a[N][N],dp[N][N],ans;
short last[N*N][N];
int main() {
    RI(n,m);
    REP1(i,1,n) REP1(j,1,m) RI(a[i][j]);
    REP1(i,1,n) {
        REP1(j,1,m) REP1(k,j,m) {
            chkmax(dp[j][k],last[a[i][j]][j]);
            chkmax(dp[j][k],last[a[i][j]][k]);
            chkmax(dp[j][k],last[a[i][k]][j]);
            chkmax(dp[j][k],last[a[i][k]][k]);
            if ( j!=k && a[i][j]==a[i][k] ) dp[j][k]=i;
        }
        REP1(d,1,m-1) REP1(j,1,m-d) chkmax(dp[j][j+d],max(dp[j+1][j+d],dp[j][j+d-1]));
        REP1(j,1,m) last[a[i][j]][j]=i;
        REP1(j,1,m) REP1(k,j,m) chkmax(ans,(i-dp[j][k])*(k-j+1));
    }
    printf("%d\n",ans);
    return 0;
}