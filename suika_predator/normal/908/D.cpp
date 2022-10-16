#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;
const int MOD=1e9+7;
int n,pa,pb;
inline long long inv(int x)
{
	int y=MOD-2,bit=1<<30;
	long long ret=1;
	while(bit)
	{
		ret*=ret,ret%=MOD;
		if(y&bit)ret*=x,ret%=MOD;
		bit>>=1;
	}
	return ret;
}
int dp[2333][2333];
int main()
{
	scanf("%d%d%d",&n,&pa,&pb);
	long long r=inv(pa+pb);
	pa=pa*r%MOD,pb=pb*r%MOD;
	long long tmp=inv(MOD+1-pa),ans=0;
	//cout<<tmp<<endl;
	dp[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i+j<n)
			{
				dp[i][j+i]=(dp[i][j+i]+1ll*dp[i][j]*pb)%MOD;
				dp[i+1][j]=(dp[i+1][j]+1ll*dp[i][j]*pa)%MOD;
			}
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			if(i+j>=n)
			{
				ans=(ans+1ll*dp[i][j]%MOD*(j+tmp%MOD*(pa+1ll*(MOD+1-pa)*i%MOD)%MOD))%MOD;
			}
		}
	}
	printf("%lld\n",ans%MOD);
	return 0;
}