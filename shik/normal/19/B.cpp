// by shik
#include <cstdio>
#include <algorithm>
#include <iostream>
#define INF 1000000000000000LL;
using namespace std;
long long dp[4010],ans;
int t[2010],c[2010];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) {
		scanf("%d%d",t+i,c+i);
		t[i]++;
		if ( t[i]>n ) t[i]=n;
	}
	for ( i=1; i<=2*n; i++ ) dp[i]=INF;
	for ( i=0; i<n; i++ ) {
		for ( j=2*n; j>=t[i]; j-- )
			if ( dp[j-t[i]]+c[i]<dp[j] ) dp[j]=dp[j-t[i]]+c[i];
	}
	ans=INF;
	for ( i=n; i<=2*n; i++ )
		if ( dp[i]<ans ) ans=dp[i];
	cout<<ans<<endl;
	return 0;
}