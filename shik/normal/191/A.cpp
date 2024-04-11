// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
void chkmax( int &a, int b ) { if ( b>a ) a=b; }
int dp[130][130],tmp[130];
int main()
{
	for ( int i='a'; i<='z'; i++ ) for ( int j='a'; j<='z'; j++ ) dp[i][j]=-514514514;
	int n;
	char s[20];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%s",s);
		int l=strlen(s),a=s[0],b=s[l-1];
		for ( int j='a'; j<='z'; j++ ) tmp[j]=dp[j][a]+l;
		chkmax(dp[a][b],l);
		for ( int j='a'; j<='z'; j++ ) chkmax(dp[j][b],tmp[j]);
	}
	int ans=0;
	for ( int i='a'; i<='z'; i++ ) chkmax(ans,dp[i][i]);
	printf("%d\n",ans);
	return 0;
}