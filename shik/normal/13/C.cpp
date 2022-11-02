// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N],b[N];
long long dp[N];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	memcpy(b,a,sizeof(a)); sort(b,b+n);
	for ( int i=0; i<n; i++ ) {
		dp[0]+=abs(a[i]-b[0]);
		for ( int j=1; j<n; j++ ) dp[j]=min(dp[j]+abs(a[i]-b[j]),dp[j-1]);
	}
	printf("%I64d\n",dp[n-1]);
	return 0;
}