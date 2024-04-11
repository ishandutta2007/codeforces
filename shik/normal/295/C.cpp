// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define N 55
#define MOD 1000000007
int C[N][N];
LL dp[4*N][N][N];
bool can[4*N][N][N];
int main()
{
    for ( int i=0; i<N; i++ ) for ( int j=C[i][0]=1; j<=i; j++ ) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    int n,m;
    scanf("%d%d",&n,&m); m/=50;
    int c1=0,c2=0;
    for ( int i=1; i<=n; i++ ) {
        int x;
        scanf("%d",&x);
        if ( x==50 ) c1++;
        else c2++;
    }
    dp[0][c1][c2]=1;
    can[0][c1][c2]=1;
    for ( int i=0; i<=4*n+5; i++ ) {
        if ( i%2==1 && can[i][c1][c2] ) {
            int ans=dp[i][c1][c2]%MOD;
            printf("%d\n%d\n",i,ans);
            return 0;
        }
        for ( int j=0; j<=c1; j++ ) for ( int k=0; k<=c2; k++ ) if ( can[i][j][k] ) {
            int now=dp[i][j][k]%MOD;
            for ( int x=0; x<=j; x++ ) for ( int y=0; y<=k && x+2*y<=m; y++ ) if ( x+y>0 ) {
                can[i+1][c1-j+x][c2-k+y]=1;
                dp[i+1][c1-j+x][c2-k+y]+=1LL*C[j][x]*C[k][y]%MOD*now%MOD;
            }
        }
    }
    puts("-1\n0");
    return 0;
}