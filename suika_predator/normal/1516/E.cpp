#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
inline long long poww(long long x,int y)
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
long long par[1111],fac[1111],ifac[1111];
long long n,K;
long long Cn(long long sub,long long x)
{
	if(x<0||x>n-sub)return 0;
	return par[x+sub]*poww(par[sub],MOD-2)%MOD*ifac[x]%MOD;
}
long long dp[555][555];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>K;
	par[0]=fac[0]=1;
	for(int i=1;i<=min(n,1000ll);i++)
		par[i]=par[i-1]*(n-i+1)%MOD;
	for(int i=1;i<=1000;i++)
		fac[i]=fac[i-1]*i%MOD;
	ifac[1000]=poww(fac[1000],MOD-2);
	for(int i=1000;i>=1;i--)
		ifac[i-1]=ifac[i]*i%MOD;
//	for(int i=0;i<=10;i++)cerr<<i<<' '<<Cn(i)<<endl;
	dp[0][0]=1;
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=i&&i+j<=n;j++)
		{
			for(int k=2;k<=i+1;k++)
			{
//				cerr<<i<<' '<<j<<" from "<<i-k+1<<' '<<j-1<<", coeff "<<Cn(i+j-k,k)*(fac[k-1])<<endl;
				dp[i][j]+=dp[i-k+1][j-1]*Cn(i+j-k,k)%MOD*(fac[k-1])%MOD;
			}
			dp[i][j]%=MOD;
		}
	}
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=K;j++)
//			cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	for(int i=1;i<=K;i++)
	{
		long long tans=0;
		for(int t=i;t>=0;t-=2)
		{
			for(int j=0;j<=t&&j+t<=n;j++)
			{
				tans+=dp[t][j]*ifac[j]%MOD;
			}
		}
		cout<<tans%MOD<<' ';
	}
	return 0;
}