// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
#define MOD 1000000007
#define REP(i,a,b) for ( int i=a; i<b; i++ )
void add( int &a, int b ) {
    a+=b;
    if ( a>=MOD ) a-=MOD;
}
int mul( int a, int b ) { return 1LL*a*b%MOD; }
int n,k,dp[N][N][2][2][2];
int main()
{
    scanf("%d%d",&n,&k);
    dp[1][0][0][0][1]=1;
    REP(i,1,n) REP(j,0,i+1) REP(x,0,2) REP(y,0,2) REP(z,0,2) {
        int me=dp[i][j][x][y][z];
        add(dp[i+1][j][0][0][1],me);
        if ( z==0 ) {
            add(dp[i+1][j+1-x][0][1][0],me);
            add(dp[i+1][j+1-y][1][0][0],me);
            add(dp[i+1][j][0][0][0],mul(i-j+x+y-2,me));
            add(dp[i+1][j-1][0][0][0],mul(j-x-y,me));
        } else {
            add(dp[i+1][j+2][1][1][0],me);
            add(dp[i+1][j][0][0][0],mul(i-j-1,me));
            add(dp[i+1][j-1][0][0][0],mul(j,me));
        }
    }
    int ans=0;
    REP(x,0,2) REP(y,0,2) REP(z,0,2) add(ans,dp[n][k][x][y][z]);
    printf("%d\n",ans);
    return 0;
}