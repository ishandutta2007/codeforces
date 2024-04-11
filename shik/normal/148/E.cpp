// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define M 10010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,sz,sv[N],tmt[N],dp[M];
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&sz);
		for ( int j=1; j<=sz; j++ ) scanf("%d",sv+j);
		for ( int j=1; j<=sz; j++ ) sv[j]+=sv[j-1];
		for ( int j=1; j<=sz; j++ ) for ( int k=tmt[j]=0; k<=j; k++ ) tmt[j]=max(tmt[j],sv[k]+sv[sz]-sv[sz-(j-k)]);
		for ( int j=m; j>=0; j-- ) for ( int k=min(sz,j); k>0; k-- ) dp[j]=max(dp[j],dp[j-k]+tmt[k]);
	}
	printf("%d\n",dp[m]);
	return 0;
}