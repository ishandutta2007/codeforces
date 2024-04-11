// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int num[N][N],dp2[N][N],dp5[N][N];
int cal( int x, int b ) {
	if ( x==0 ) return 5000;
	int r=0;
	while ( x%b==0 ) {
		r++;
		x/=b;
	}
	return r;
}
void trace( int b, int dp[N][N], int x, int y ) {
	if ( x==1 && y==1 ) return;
	if ( x>1 && dp[x][y]==dp[x-1][y]+cal(num[x][y],b) ) {
		trace(b,dp,x-1,y);
		putchar('D');
	} else {
		trace(b,dp,x,y-1);
		putchar('R');
	}
}
int main()
{
	int n,i,j,flg=0,zx=0,zy=0;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=n; j++ ) 
			scanf("%d",num[i]+j);
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=n; j++ )
			if ( num[i][j]==0 ) flg=1,zx=i,zy=j;
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=n; j++ ) {
			if ( i==1 && j==1 ) {
				dp2[i][j]=cal(num[i][j],2);
				dp5[i][j]=cal(num[i][j],5);
			} else if ( i==1 ) {
				dp2[i][j]=dp2[i][j-1]+cal(num[i][j],2);
				dp5[i][j]=dp5[i][j-1]+cal(num[i][j],5);
			} else if ( j==1 ) {
				dp2[i][j]=dp2[i-1][j]+cal(num[i][j],2);
				dp5[i][j]=dp5[i-1][j]+cal(num[i][j],5);
			} else {
				dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+cal(num[i][j],2);
				dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+cal(num[i][j],5);
			}
		}
	if ( flg && min(dp2[n][n],dp5[n][n])>1 ) {
		puts("1");
		for ( i=1; i<zx; i++ ) putchar('D');
		for ( i=1; i<zy; i++ ) putchar('R');
		for ( i=zx; i<n; i++ ) putchar('D');
		for ( i=zy; i<n; i++ ) putchar('R');
	} else {
		printf("%d\n",min(dp2[n][n],dp5[n][n]));
		if ( dp2[n][n]<dp5[n][n] ) trace(2,dp2,n,n);
		else trace(5,dp5,n,n);
	}
	puts("");
	return 0;
}