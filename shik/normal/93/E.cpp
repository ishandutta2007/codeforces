// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <map>
#include <ctime>
#define M 110
#define T 50000
using namespace std;
typedef long long LL;
int dp[M][T];
int m,a[M];
LL go( int p, LL n ) {
	if ( n==0 ) return 0;
	if ( p==m ) return n;
	if ( n<T ) {
		if ( dp[p][n]!=-1 ) return dp[p][n];
		else return dp[p][n]=go(p+1,n)-go(p+1,n/a[p]);
	}
	return go(p+1,n)-go(p+1,n/a[p]);
}
int main()
{
	LL n;
	scanf("%I64d%d",&n,&m);
	for ( int i=0; i<m; i++ ) scanf("%d",a+i);
	sort(a,a+m,greater<int>());
	memset(dp,-1,sizeof(dp));
	printf("%I64d\n",go(0,n));
	return 0;
}