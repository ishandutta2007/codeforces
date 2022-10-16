#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
double dp[1005][1005];
int main()
{
	clock_t s=clock();
	int n=read(),m=read(),x=read(),y=read();
//int n=10,m=14,x=5,y=14;
	if(m==1)return printf("%d\n",2*n-2*x)&0;
	if(n==x)return puts("0")&0;
	int p=100000000/((n-x)*m);
	for(int i=n-1;i>=x;i--)
	{
		//int yy=40;
		int u=p;
		while(u--)
		{
		//	printf("Debug! %.3lf\n",1.0*(clock()-s)/CLOCKS_PER_SEC);
			dp[i][1]=(dp[i][1]+dp[i][2]+dp[i+1][1])/3.0+1;
			dp[i][m]=(dp[i][m]+dp[i][m-1]+dp[i+1][m])/3.0+1;
			for(int j=2;j<m;j++)
				dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i][j+1]+dp[i+1][j])/4.0+1;
		}//while(1.0*(n-x)*(clock()-s)/CLOCKS_PER_SEC<1.50);
		//while(yy--);
	}
	printf("%.4lf",dp[x][y]);;;;;;
}