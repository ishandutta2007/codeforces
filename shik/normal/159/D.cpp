// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int pal[N][N],sum[N];
int main()
{
	int n=strlen(gets(s+1)); long long ans=0;
	for ( int i=1; i<=n; i++ ) pal[i][i]=1;
	for ( int i=1; i<n; i++ ) pal[i][i+1]=(s[i]==s[i+1]);
	for ( int l=2; l<n; l++ ) for ( int i=1; i<=n; i++ ) pal[i][i+l]=(s[i]==s[i+l]&&pal[i+1][i+l-1]);
	for ( int i=1; i<=n; i++ ) {
		sum[i]=sum[i-1];
		for ( int j=1; j<=i; j++ ) sum[i]+=pal[j][i];
	}
	for ( int i=1; i<=n; i++ ) for ( int j=i; j<=n; j++ ) if ( pal[i][j] ) ans+=sum[i-1];
	printf("%I64d\n",ans);
	return 0;
}