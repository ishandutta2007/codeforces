#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define MAX 15000001
#define vs vector<string> 
int main() 
{
	int n,k,p;
	cin>>n>>k>>p;
	v arr(n+1);
	for (int i=1;i<=n; i++)
		cin>>arr[i];
	vv dp(k+1,v(p+1,-1));
	v maxi(k+1,-1);
	dp[0][0]=0;
	maxi[0]=0;
	for (int l=1; l<=n; l++)
	{
		vv dp1(k+1,v(p+1,-1));
		for (int i=1; i<=k; i++)
		{
			for (int j=0;j<p; j++)
			{
				int x=((j-arr[l])%p+p)%p;
				if (dp[i][x]!=-1)
					dp1[i][j]=dp[i][x]-x+j;
				if (x==0 && maxi[i-1]!=-1)
					dp1[i][j]=max(dp1[i][j],maxi[i-1]+arr[l]%p);
			}
		}
		maxi=v(k+1,-1);
		for (int i=1; i<=k; i++)
		{
			for (int j=1; j<=p; j++)
				maxi[i]=max(maxi[i],dp1[i][j]);
		}
		dp=dp1;
	}
	//cout<<dp[1][1]<<endl;
	ll ans=0;
	for (int i=0; i<p; i++)
	{
		ans=max(ans,dp[k][i]);
		//cout<<ans<<" "<<i<<endl;
	}
	cout<<ans<<endl;
    return 0; 
}