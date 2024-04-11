// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 100000000
using namespace std;
int k1,k2,dp[110][110][15][15];
int go( int n, int m, int a, int b ) {
	if ( n==0 && m==0 ) return 1;
	int &r=dp[n][m][a][b];
	if ( r!=-1 ) return r;
	r=0;
	if ( n>0 && a<k1 ) r+=go(n-1,m,a+1,0);
	if ( m>0 && b<k2 ) r+=go(n,m-1,0,b+1);
	return r%=MOD;
}
int main()
{
	int n,m;
	scanf("%d%d%d%d",&n,&m,&k1,&k2);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(n,m,0,0));
	return 0;
}