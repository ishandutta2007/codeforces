// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int dp[50010][35];
int go( int a, int b, int n ) {
	if ( dp[a][b]!=-1 ) return dp[a][b];
	if ( pow(1.0*a,b)+0.5>=n ) return 1;
	if ( b>32 ) return dp[a][b]=2;
	if ( b==1 && a*a>=n ) return (dp[a][b]=1-(n-a)%2);
	if ( !go(a+1,b,n) || !go(a,b+1,n) ) return dp[a][b]=1;
	if ( go(a+1,b,n)==2 || go(a,b+1,n)==2 ) return dp[a][b]=2;
	return dp[a][b]=0;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	char sol[3][100]={"Stas","Masha","Missing"};
	puts(sol[go(a,b,n)]);
	return 0;
}