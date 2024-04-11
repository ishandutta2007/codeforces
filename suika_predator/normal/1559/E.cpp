#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
int l[55],r[55],A[111111],B[111111],sum[111111],*dp=A,*dq=B;
int ans[111111];
long long SUM;
int solve(int d)
{
	int lim=m/d;
	SUM+=(lim+1)*n;
	for(int i=0;i<=lim;i++)dp[i]=dq[i]=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum[0]=dp[0];
		int L=(l[i]-1)/d+1,R=r[i]/d;
//		cerr<<"solve "<<d<<' '<<i<<' '<<L<<' '<<R<<endl;
		if(L>R)return 0;
		dq[0]=0;
		for(int j=1;j<=lim;j++)
		{
			sum[j]=(sum[j-1]+dp[j])%MOD;
			if(j-L>=0)
			{
				if(j-R-1>=0)
					dq[j]=(sum[j-L]-sum[j-R-1]+MOD)%MOD;
				else
					dq[j]=sum[j-L];
			}
			else dq[j]=0;
		}
		swap(dp,dq);
	}
	long long ret=0;
	for(int j=0;j<=lim;j++)
		ret+=dp[j];
//	cerr<<"solve "<<d<<" return "<<ret%MOD<<endl;
	return ret%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int j=1;j<=m;j++)
	{
		ans[j]=solve(j);
	}
//	cerr<<SUM<<endl;
	for(int i=m;i>=1;i--)
		for(int j=i+i;j<=m;j+=i)
			ans[i]=(ans[i]-ans[j]+MOD)%MOD;
	cout<<ans[1]<<endl;
	return 0;
}