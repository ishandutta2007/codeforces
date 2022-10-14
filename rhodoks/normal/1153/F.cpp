#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 2100
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;
LL dp[MAXN<<1][MAXN][2];
LL n,k,l;

LL mypow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		n/=2;
		x=x*x%MOD;
	}
	return ans%MOD;
}

int main()
{
	cin>>n>>k>>l;
	dp[0][0][0]=1;
	RPT(i,1,2*n+2)
		RPT(j,0,min((LL)i,n)+1)
		{
			if (j>=k)
				dp[i][j][1]+=dp[i-1][j][0];
			RPT(x,0,2)
			{
				if (i+j-x<=2*n && j>0)
					dp[i][j][x]+=dp[i-1][j-1][x];
				dp[i][j][x]+=dp[i-1][j+1][x]*(j+1);
				dp[i][j][x]%=MOD;
			}
		}
	LL tem1,tem2;
	tem1=1;
	RPT(i,1,n+1)
		tem1=tem1*2*i%MOD;
	tem2=1;
	RPT(i,1,2*n+2)
		tem2=tem2*i%MOD;
	LL ans=l;
	ans=ans*dp[2*n+1][0][1]%MOD;
	ans=ans*tem1%MOD;
	ans=ans*mypow(tem2,MOD-2)%MOD;
	cout<<ans;
	return ~~(0^_^0);
}