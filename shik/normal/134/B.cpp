// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int dp[N][N];
int go( int a, int b ) {
	if ( b==0 ) return N;
	if ( b==1 ) return a-1;
	if ( a<N && b<N ) {
		if ( dp[a][b] ) return dp[a][b];
		else return dp[a][b]=a/b+go(b,a%b);
	}
	return a/b+go(b,a%b);
}
int main()
{
	int n,ans=N;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) ans=min(ans,go(n,i));
	printf("%d\n",ans);
	return 0;
}