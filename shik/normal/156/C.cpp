// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int dp[110][2550];
int go( int n, int m ) {
	int &r=dp[n][m];
	if ( r!=-1 ) return r;
	if ( n==0 ) return r=(m==0);
	r=0;
	for ( int i=0; i<26&&i<=m; i++ ) r=(r+go(n-1,m-i))%MOD;
	return r;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int t;
	char s[110];
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%s",s);
		int n=strlen(s),m=0;
		for ( int i=0; i<n; i++ ) m+=s[i]-'a';
		printf("%d\n",(go(n,m)+MOD-1)%MOD);
	}
	return 0;
}