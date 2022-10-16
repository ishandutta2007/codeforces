#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int fac[111111],ifac[111111];
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
long long C(int x,int y)
{
	if(x<0 or y<0 or y>x)return 0;
	return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	fac[0]=1;
	for(int i=1;i<=100000;i++)fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[100000]=poww(fac[100000],MOD-2);
	for(int i=100000;i>=1;i--)ifac[i-1]=1ll*ifac[i]*i%MOD;
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> cnt(n+1);
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		vector<vector<int>> f(n+1,vector<int>(n+1,0));
		int maxx=0,minn=1e9;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			maxx=max(maxx,x);
			minn=min(minn,x);
			cnt[x]++;
		}
		if(cnt[maxx]>1)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<1<<endl;
			continue;
		}
		/*
		dp[i][?]:
			(cnt[i]>0)place i: left j-cnt[i]+2 holes, dp[i+1][j]*C(j,cnt[i]-1)
			no place i: left j-cnt[i] holes, dp[i+1][j]*C(j,cnt[i])
		*/
		dp[maxx][0]=1;
		for(int i=maxx-1;i>minn;i--)
		{
			for(int j=0;j<=n/2;j++)
			{
				if(cnt[i]>0 and j>=cnt[i]-1)
				{
					dp[i][j-cnt[i]+2]=(dp[i][j-cnt[i]+2]+1ll*dp[i+1][j]*C(j,cnt[i]-1))%MOD;
					f[i][j-cnt[i]+2]=(f[i][j-cnt[i]+2]+1ll*dp[i+1][j]*C(j,cnt[i]-1))%MOD;
				}
				if(j>=cnt[i])
				{
					dp[i][j-cnt[i]]=(dp[i][j-cnt[i]]+1ll*dp[i+1][j]*C(j,cnt[i]))%MOD;
				}
			}
//			for(int j=0;j<n/2;j++)cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
		int ans=0;
		int sum=0,prod=1;
		for(int i=minn;i<=maxx;i++)
		{
			sum+=cnt[i];
			prod=1ll*prod*ifac[cnt[i]]%MOD;
			if(sum<=n/2)
			{
//				cerr<<"addans "<<i+1<<' '<<sum-1<<' '<<(1ll*f[i+1][sum-1]*fac[sum]%MOD*prod%MOD)<<endl;
				ans=(ans+1ll*f[i+1][sum-1]*fac[sum]%MOD*prod)%MOD;
			}
		}//??
		cout<<ans<<endl;
	}
	return 0;
}