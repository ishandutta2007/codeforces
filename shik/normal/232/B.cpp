// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
LL C[N][N],D[N],dp[N][N*N];
LL pw( LL a, LL b ) {
	LL r=1;
	while ( b ) {
		if ( b&1 ) r=r*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return r;
}
int main()
{
	LL n,m,k;
	cin>>n>>m>>k;
	for ( int i=0; i<=n; i++ ) for ( int j=C[i][0]=1; j<=i; j++ ) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	for ( int i=0; i<=n; i++ ) D[i]=pw(C[n][i],m/n);
	dp[0][0]=1;
	for ( int i=1; i<=n; i++ ) for ( int j=0; j<=k && j<=n*i; j++ ) {
		for ( int l=0; l<=n && l<=j; l++ ) dp[i][j]+=dp[i-1][j-l]*D[l]%MOD*(i<=m%n?C[n][l]:1)%MOD;
		dp[i][j]%=MOD;
	}
	cout<<dp[n][k]<<endl;
	return 0;
}