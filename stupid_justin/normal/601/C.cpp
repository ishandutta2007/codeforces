#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1005;
int n,m,my_pts,L,R;
int c[N];
double d,ans;
double dp[N][N*M],sum[N*M];
//dp[i][j]ij
int main()
{
	cin>>n>>m;
	d=1.0/(m-1);
	for(int i=1;i<=n;i++) cin>>c[i],my_pts+=c[i];
	dp[0][0]=sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i*m;j++)
		{
			L=max(i-1,j-m),R=min((i-1)*m,j-1);
			dp[i][j]=d*sum[R];
			if(L)dp[i][j]-=d*sum[L-1];
			if(L<=j-c[i]&&j-c[i]<=R)
				dp[i][j]-=d*dp[i-1][j-c[i]];
		}
		for(int j=1;j<=i*m;j++)sum[j]=sum[j-1]+dp[i][j];
	}
	
	for(int j=n;j<my_pts;j++)ans+=dp[n][j];
	printf("%.12lf\n",ans*(m-1)+1);
}