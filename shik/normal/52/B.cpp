// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N][N];
int cx[N],cy[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='*' ) cx[i]++,cy[j]++;
	long long ans=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='*' ) ans+=(cx[i]-1)*(cy[j]-1);
	printf("%I64d\n",ans);
	return 0;
}