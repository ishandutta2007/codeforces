// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 1010
using namespace std;
typedef long long LL;
LL ten[20]={1},two[20]={2};
void pre_cal() {
	for ( int i=1; i<20; i++ ) ten[i]=ten[i-1]*10;
	for ( int i=1; i<20; i++ ) two[i]=two[i-1]*10;
}
LL Ls[N],Rs[N];
double tbl[N],dp[N][N];
LL cal( LL a, LL b, LL c, LL d ) {
	LL st=max(a,c);
	LL ed=min(b,d);
	return max(ed-st+1,0LL);
}
double cal( LL a, LL b ) {
	LL all=b-a+1,cnt=0;
	for ( int i=0; i<=18; i++ ) cnt+=cal(a,b,ten[i],two[i]-1);
	return double(cnt)/all;
}
int main()
{
	pre_cal();
	int n,i,j,k; double tmt,ans=0;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) cin>>Ls[i]>>Rs[i];
	scanf("%d",&k); tmt=k/100.0;
	for ( i=1; i<=n; i++ ) tbl[i]=cal(Ls[i],Rs[i]);
	dp[0][0]=1;
	for ( i=1; i<=n; i++ ) {
		dp[i][0]=dp[i-1][0]*(1-tbl[i]);
		for ( j=1; j<=i; j++ )
			dp[i][j]=dp[i-1][j-1]*tbl[i]+dp[i-1][j]*(1-tbl[i]);
	}
	for ( i=n; i>=0; i-- )
		if ( double(i)/n+1e-9>=tmt ) ans+=dp[n][i];
	printf("%.12f\n",ans);
	return 0;
}