#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL dp[MAXN];

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
}

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

int n,m;
LL a[MAXN];
int b[MAXN];
LL sum[2];
LL ans[2];
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[b[i]]+=a[i];
	}
	dp[0]=1;
	for (int i=0;i<m;i++)
		for (int j=i;j>=0;j--)
		{
			if (i-j<=sum[0])
			{
				LL sum0=sum[0]-(i-j);
				LL sum1=sum[1]+j;
				dp[j+1]+=dp[j]*sum1%MOD*inv(sum0+sum1)%MOD;
				dp[j]=dp[j]*sum0%MOD*inv(sum0+sum1)%MOD;
			}
		}
	for (int i=0;i<=m;i++)
	{
		ans[0]+=(sum[0]-(m-i))*dp[i]%MOD;
		ans[1]+=(sum[1]+i)*dp[i]%MOD;
		//cout<<sum[0]-(m-i)<<' '<<sum[1]+i<<' '<<endl;
	}
	for (int i=1;i<=n;i++)
		cout<<(ans[b[i]]*a[i]%MOD*inv(sum[b[i]])%MOD+MOD)%MOD<<endl;
	//cout<<endl;
	return ~~(0^_^0);
}