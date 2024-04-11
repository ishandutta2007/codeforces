#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long a[N],b[N],dp[N][3],dp2[N][3];
long long n;
int main() 
{
	cin>>n;
	for (long long i=1;i<=n;i++)
		cin>>a[i];
	for (long long i=1;i<=n;i++)
		cin>>b[i];
	for (long long i=1;i<=n;i++)
	{
		if (i==1)
		{
			dp[i][0]=0;
			dp[i][1]=a[i];
			dp[i][2]=b[i];
		}
		else
		{
			dp[i][0]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][0]);
			dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
			dp[i][2]=max(dp[i-1][0],dp[i-1][1])+b[i];
			
		}
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
}