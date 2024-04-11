// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define N 1234
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool lucky( int n ) {
	while ( n ) {
		if ( n%10!=4 && n%10!=7 ) return 0;
		n/=10;
	}
	return 1;
}
map<int,int> app;
int fac[100010]={1},inv[100010]={1,1},l[N],nl,dp[N][N];
int C( int n, int m ) { return 1LL*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int main()
{
	int n,m,x,t=0,ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) fac[i]=1LL*fac[i-1]*i%MOD;
	for ( int i=2; i<=n; i++ ) inv[i]=1LL*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for ( int i=2; i<=n; i++ ) inv[i]=1LL*inv[i-1]*inv[i]%MOD;
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&x);
		if ( lucky(x) ) app[x]++;
		else t++;
	}
	FOR(it,app) l[++nl]=it->second;
	dp[0][0]=1;
	for ( int i=1; i<=nl; i++ ) for ( int j=dp[i][0]=1; j<=i; j++ ) dp[i][j]=(dp[i-1][j]+1LL*dp[i-1][j-1]*l[i])%MOD;
	for ( int i=0; i<=nl&&i<=m; i++ ) if ( m-i<=t ) ans=(ans+1LL*dp[nl][i]*C(t,m-i))%MOD;
	printf("%d\n",ans);
	return 0;
}