// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define M 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int inv[N],fac[N],ifac[N];
inline int addi( int &a, int b ) { return a=(a+b)%M; }
inline int mul( int a, int b ) { return 1LL*a*b%M; }
int solve( int n, int a[10] ) {
	int ans=0,dp[11][N]={}; dp[0][0]=1;
	for ( int i=0; i<10; i++ ) for ( int j=0; j<=n; j++ )
		for ( int k=max(a[i],0); j+k<=n; k++ ) addi(dp[i+1][j+k],mul(dp[i][j],ifac[k]));
	for ( int i=0; i<=n; i++ ) addi(ans,mul(fac[i],dp[10][i]));
	return ans;
}
int main()
{
	inv[1]=1;
	for ( int i=2; i<N; i++ ) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	for ( int i=fac[0]=1; i<N; i++ ) fac[i]=mul(i,fac[i-1]);
	for ( int i=ifac[0]=1; i<N; i++ ) ifac[i]=mul(inv[i],ifac[i-1]);
	int n,a[10],ans=0;
	scanf("%d",&n);
	for ( int i=0; i<10; i++ ) scanf("%d",a+i);
	for ( int i=1; i<10; i++ ) {
		a[i]--;
		addi(ans,solve(n-1,a));
		a[i]++;
	}
	printf("%d\n",ans);
	return 0;
}